//
//  ListaEncadeada.cpp
//
//  Created by Eiji Adachi Medeiros Barbosa
//

#include "../header/Analisador.h"
#include <string>
#include <stack>

using namespace std;

Analisador::Analisador()
{
}

bool Analisador::eBemFormada(std::string str)
{
    stack<char> pilha;

    for(char ch : str)
    {
        // se for uma abertura vai empilhar
        if (ch == '[' || ch == '{' || ch == '(')
        {
            pilha.push(ch);

            // se for um fechamento
        } else if(ch == ']' || ch == '}' || ch == ')') {

            // se a pilha estiver vazia, retorna falso
            if (pilha.empty())
            {
                return false;
            }

            char topo = pilha.top();

            if ((ch == '}' && topo == '{') ||
                (ch == ']' && topo == '[') ||
                (ch == ')' && topo == '('))
            {
                // se o ch for } e o topo for {, então está certo e pode retirar da pilha
                pilha.pop();
            } else {
                // se não, retona falso
                return false;
            }
        }
    }

    return pilha.empty();
}
