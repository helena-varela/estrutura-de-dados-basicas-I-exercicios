//
//  Fila.h ​
//
//  Criado por Eiji Adachi Medeiros Barbosa
//

#ifndef __Fila__
#define __Fila__
#define __CHECK_INTEGRIDADE__ 1
#include <string>
#include <sstream>
#include <vector>
template <typename T>
class Fila
{
private:
    T* elementos;
    int capacidade;
    int quantidade;
    int inicio;
    int fim;
    
public:
    // Não altere ​
    Fila(int cap)
    {
        this->quantidade = 0;
        this->inicio = 0;
        this->fim = 0;
        this->capacidade = cap;
        this->elementos = new T[this->capacidade];
    }
    // Não altere ​
    ~Fila()
    {
        delete [] this->elementos;
    }
    
    int tamanho()
    {
        return this->quantidade;
    }

    T frente()                                                                                                                                                                                                // versão: EAMB-1.0
    {// Begin ​
        if (quantidade == 0)
        {
            throw std::underflow_error("A fila está vazia");
        } else {
            return elementos[inicio];
        }
        
    }// End

    void enfileirar(T elemento)
    {// Begin
        if (quantidade == capacidade)
        {
            throw std::overflow_error("A fila está cheia");
        } else{
            elementos[fim] = elemento;
            fim = (fim+1)%capacidade;
            quantidade++;
        }        
    }// End​

    T desenfileirar()
    {// Begin 
        if (quantidade == 0)
        {
            throw std::underflow_error("A fila está vazia");
        } else {
            T remover = elementos[inicio];
            inicio = (inicio + 1)%capacidade;
            quantidade--;
            return remover;
        }
    }//⁣ End

    bool cheia()
    {
        return this->quantidade == this->capacidade;
    }

    bool vazia()
    {
        return this->quantidade == 0;
    }

    std::string imprimir()
    {
        std::stringstream r; r << "{ "; for (int a = this->inicio, b = 0; b < this->quantidade; ++b, a = (a + 1) % this->capacidade) r << this->elementos[a] << " ";r << "}";return r.str();       
    }
};

#endif