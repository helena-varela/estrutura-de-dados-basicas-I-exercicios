#define __CHECK_INTEGRIDADE__ 1
#include "../header/Lista.h"
#include <vector>
#include <iostream>
#include <stdexcept>
#include <sstream> // pra implementar o método imprimir ​

// Implemente aqui sua solução ​
int Lista::removerTodos(const std::string &valor) // versão: EAMB-1.0
{
    No *atual = primeiro;
    No *anterior = nullptr;
    int contador = 0;

    while (atual != nullptr)
    {
        if (atual->valor == valor) // se o nó com o valor for igual ao valor a ser removido
        {

            
            // 1. Caso de Borda: O nó a ser removido é o primeiro da lista
            if (atual == primeiro)
            {
                primeiro = atual->proximo;
            }
            else
            {
                // 2. Caso Comum: O nó está no meio da lista
                anterior->proximo = atual->proximo;
            }
            // 3. Caso de Borda: O nó a ser removido é o último da lista
            if (atual == ultimo)
            {
                ultimo = anterior;
            }
            
            
            No *proximo_aux = atual->proximo;
            delete atual;
            atual = proximo_aux; // Avança o atual para o próximo nó que guardamos
            contador++;
            quantidade--;
        }
        else
        {
            anterior = atual;
            atual = atual->proximo;
        }
    }

    return contador;
}

// Não alterar código daqui pra baixo ​
Lista::Lista(){this->quantidade=0;this->primeiro=nullptr;this->ultimo=nullptr;}Lista::~Lista(){auto a=this->primeiro;while(a!=nullptr){auto b=a;a=a->proximo;delete b;}this->primeiro=nullptr;this->ultimo=nullptr;this->quantidade=0;}bool Lista::inserirInicio(const std::string& x){No* n=new No(x);n->proximo=this->primeiro;this->primeiro=n;if(this->quantidade==0){this->ultimo=n;}this->quantidade++;return true;}const std::string& Lista::primeiroElemento()const{if(quantidade>0){return primeiro->valor;}else{throw std::out_of_range("A lista está vazia. Não é possível acessar o primeiro elemento.");}}const std::string& Lista::ultimoElemento()const{if(quantidade>0){return ultimo->valor;}else{throw std::out_of_range("A lista está vazia. Não é possível acessar o último elemento.");}}unsigned long Lista::tamanho()const{return quantidade;}std::string Lista::imprimir()const{std::ostringstream o;o<<"{";No* p=primeiro;while(p!=nullptr){o<<p->valor;if(p->proximo!=nullptr)o<<", ";p=p->proximo;}o<<"}";return o.str();}
