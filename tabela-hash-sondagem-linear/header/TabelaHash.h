//
//  TabelaHash.h
//
//  Created by Eiji Adachi Medeiros Barbosa
//

#ifndef TABELA_HASH_H
#define TABELA_HASH_H

#include <string>
#include <unordered_set>
#include <iostream>
#include <optional>

enum class Estado 
{ 
    LIVRE = 0, 
    OCUPADO, 
    REMOVIDO 
};

struct Elemento 
{
        std::string chave;
        std::string valor;
        Estado estado = Estado::LIVRE;
};

enum class ConsistenciaStatus {
    OK = 0,
    QUANTIDADE_INCORRETA,
    CHAVE_DUPLICADA,
};

class TabelaHash 
{
    friend class TabelaHashTestHelper;

private:
    Elemento* array;
    int capacidade;
    int quantidade;    
    
    static constexpr int CAPACIDADE_PADRAO = 17;
    static constexpr float CARGA_LIMITE_INFERIOR = 0.125f;
    static constexpr float CARGA_LIMITE_SUPERIOR = 0.5f;

    size_t valorHash(const std::string& chave) const 
    {
        size_t valorHash = 0;
		for (char c : chave) {
			// Função simples para facilitar colisões em testes
			valorHash += static_cast<unsigned int>(c);
			// Forma melhor de calcular valor hash que gera valores mais distribuídos
			// valorHash = 31 * valorHash + static_cast<unsigned int>(c);
		}
        return valorHash;
    }

    int hash(const std::string& chave) const 
    {
        return this->valorHash(chave) % this->capacidade; 
    }

    float fatorDeCarga() 
    {
        return (float)quantidade / (float)capacidade;
    }

    void aumentar()
    {
        int novaCapacidade = (this->capacidade * 2) + 1;
        redimensionar(novaCapacidade);
    }

    void diminuir()
    {
        int novaCapacidade = (this-> capacidade / 2) + 1;
        redimensionar(novaCapacidade);
    }

    void redimensionar(size_t tamanhoNovo)
    {
        Elemento* arrayNovo = new Elemento[tamanhoNovo];

        Elemento* arrayVelho = this->array;
        int capacidadeVelha = this->capacidade;

        this->capacidade = tamanhoNovo;
        this->quantidade = 0;
        this->array = arrayNovo; 

        for (int i = 0; i < capacidadeVelha; i++) 
        {
            if (arrayVelho[i].estado == Estado::OCUPADO) 
            {
                for (int j = 0; j < tamanhoNovo; j++) 
                {
                    auto indice = (hash(arrayVelho[i].chave) + j) % tamanhoNovo;

                    if (arrayNovo[indice].estado == Estado::LIVRE) 
                    {
                        arrayNovo[indice].chave = arrayVelho[i].chave;
                        arrayNovo[indice].valor = arrayVelho[i].valor;
                        arrayNovo[indice].estado = Estado::OCUPADO;
                        this->quantidade++;
                        break; 
                    }
                }
            }
        }
        delete[] arrayVelho;   
    }

public:
    TabelaHash(int capacidadeInicial = CAPACIDADE_PADRAO) : capacidade(capacidadeInicial) , quantidade(0)
    {
        this->array = new Elemento[this->capacidade];
    }

    ~TabelaHash()
    {
        delete [] this->array;
    }

    bool inserir(const std::string& chave, const std::string& valor)
    {
        int posicaoRemover = -1; // aqui indica a ultima posição que vi que tinha status REMOVER

        for (int delta = 0; delta < capacidade; delta++){

            auto indice = (hash(chave) + delta)%capacidade; // calculo o indice

            Elemento& elemento = array[indice]; // pego a posição

            if (elemento.estado == Estado::LIVRE){ // se a posição estiver livre
                int posicaoInsercao;

                if (posicaoRemover != -1) // se achei uma posição remover 
                {
                    posicaoInsercao = posicaoRemover;
                } else {
                    posicaoInsercao = indice;
                }
                
                array[posicaoInsercao].chave = chave;
                array[posicaoInsercao].valor = valor;
                array[posicaoInsercao].estado = Estado::OCUPADO;
                quantidade++;
                return true;
                
            } else if(elemento.chave == chave && elemento.estado == Estado::OCUPADO){ // se eu achei a chave e tenho que atualizar o valor dela

                elemento.valor = valor;
                return true;

            } else if (elemento.estado == Estado::REMOVIDO && posicaoRemover == -1) { //encontrei o primeiro espaço removido encontrado
                posicaoRemover = indice; // atualizo qual a posição que tem esse espaço removido
            }
        }

        if (posicaoRemover != -1) // se eu percorri tudo e sobrou apenas a posição de remover, insiro nela
        {
            array[posicaoRemover].chave = chave;
            array[posicaoRemover].valor = valor;
            array[posicaoRemover].estado = Estado::OCUPADO;
            quantidade++;
            return true;
        } else { // se percorri tudo e não achei nenhuma posição livre ou removido, quer dizer que está cheio
            throw std::overflow_error("ta cheio bb");
        }
    
    }


    bool remover(const std::string& chave)
    {
        for (int i = 0; i < capacidade; i++)
        {
           auto indice = (hash(chave)+i)%capacidade;
           Elemento& elemento = array[indice];

           if (elemento.estado == Estado::OCUPADO && elemento.chave == chave) // achei e tenho que apagar
           {
                elemento.estado = Estado::REMOVIDO;
                quantidade--;
                return true;

           } else if(elemento.estado ==Estado::LIVRE){
                return false;
           } else if(elemento.estado == Estado::REMOVIDO){
                continue;
           }
        }

        return false;
        
    }

    std::optional<std::string> buscar(const std::string& chave) const 
    {
        for (int i = 0; i < capacidade; i++)
        {
            auto indice = (hash(chave) + i)%capacidade;
            Elemento& elemento = array[indice];

            if (elemento.estado == Estado::OCUPADO && elemento.chave == chave) // se encontrei a chave procurada, retorno o valor dela
            {
                return elemento.valor;
            } else if (elemento.estado == Estado::LIVRE){ // se encontro uma posição livre, essa chave nunca existiu
                return std::nullopt;
            } else if(elemento.estado == Estado::REMOVIDO){ // se encontrei naquela posição o status removido significa que minha chave ta em outro lugar do array e tenhoq ue procurar
                continue;
            }
        }
        return std::nullopt; // percorri tudo e só tinha uma lista cheia de removidos
    }

    ConsistenciaStatus checarConsistencia() const
    {
        int contador = 0;
        std::unordered_set<std::string> chaves;

        for (int i = 0; i < this->capacidade; ++i)
        {
            const Elemento& e = this->array[i];

            if (e.estado == Estado::OCUPADO)
            {
                contador++;

                // Verifica duplicatas
                if (chaves.count(e.chave) > 0)
                {
                    return ConsistenciaStatus::CHAVE_DUPLICADA;
                }
                chaves.insert(e.chave);
            }
        }

        if (contador != this->quantidade)
        {
            return ConsistenciaStatus::QUANTIDADE_INCORRETA;
        }

        return ConsistenciaStatus::OK;
    }

    int tamanho() const 
    {
        return quantidade;
    }

    bool vazia() const
    {
        return this->quantidade == 0;
    }

    bool cheia() const 
    {
        return this->capacidade == this->quantidade;
    }

    void imprimir() const
    {
        for (int i = 0; i < this->capacidade; ++i)
        {
            const Elemento& e = this->array[i];

            std::cout << "[" << i << "]: ";

            switch (e.estado)
            {
                case Estado::LIVRE:
                    std::cout << "LIVRE";
                    break;
                case Estado::REMOVIDO:
                    std::cout << "REMOVIDO";
                    break;
                case Estado::OCUPADO:
                    std::cout << "OCUPADO (" << e.chave << ", " << e.valor << ")";
                    break;
            }

            std::cout << std::endl;
        }
    }
};

#endif /* TABELA_HASH_H */
