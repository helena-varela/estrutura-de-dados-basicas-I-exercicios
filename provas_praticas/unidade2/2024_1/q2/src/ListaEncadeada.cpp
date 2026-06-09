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
    No<int>* atual = this->inicio;
    while (atual != nullptr)
    {
        No<int>* proximo_no = atual->getProximo();
        delete atual;
        atual = proximo_no;
    }
    this->inicio = nullptr;
}

void ListaEncadeada::inserirNoInicio(int e){auto n = new No<int>(e);if( inicio == nullptr ) inicio = n;else { n->setProximo( inicio );inicio = n;}}

int ListaEncadeada::removerTodos(int val) 
{
    No<int>* atual = inicio;
    No<int>* anterior = nullptr;
    int contador = 0;

    while (atual != nullptr)
    {
        No<int>* proximoNo = atual->getProximo();
        
        if (atual->getValor() == val)
        {
            if (atual == inicio)
            {
                inicio = proximoNo;
            } else {
                anterior->setProximo(proximoNo);
            }

            delete atual;
            atual = proximoNo;
            contador++;

        } else {
            anterior = atual;
            atual = atual->getProximo();
            atual->setProximo(proximoNo);
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

