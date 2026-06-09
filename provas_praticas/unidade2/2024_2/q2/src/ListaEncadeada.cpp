//
//  ListaEncadeada.cpp
//
//  Created by Eiji Adachi Medeiros Barbosa
//

#include "../header/ListaEncadeada.h"
#include "../header/No.h"
#include <iostream>
#include <string>
#include <sstream>

ListaEncadeada::ListaEncadeada()
{
    this->inicio = nullptr;
}

ListaEncadeada::~ListaEncadeada()
{
    // To-Do
}

void ListaEncadeada::inserirNoInicio(int e){auto n = new No<int>(e);if( inicio == nullptr ) inicio = n;else { n->setProximo( inicio );inicio = n;}}

int ListaEncadeada::removerTodos(int val) 
{
    No<int>* atual = inicio;
    No<int>* anterior = nullptr;
    int contador = 0;
    
    while (atual != nullptr)
    {
        No<int>* proximo_atual = atual->getProximo();
        if (atual->getValor() == val)
        {
            // 1) caso o primeiro elemento para remover seja o primeiro da lista
            if (inicio == atual)
            {
                inicio = proximo_atual;
                
            } else {
                // 2) tenha que remover no meio
                anterior->setProximo(proximo_atual);
            }
            
            delete atual;
            atual = proximo_atual;
            contador++; 
        } else {
            anterior = atual;
            atual = atual->getProximo();
        }
    }
    return contador;
}

No<int>* ListaEncadeada::getInicio()
{
    return this->inicio;
}

std::string ListaEncadeada::imprimir()
{
    std::stringstream resultado;
    
    auto no = this->getInicio();

    while(no != nullptr)
    {
        resultado << no->getValor() << "->" ;
        no = no->getProximo();
    }
    resultado << "null";

    return resultado.str();
}

