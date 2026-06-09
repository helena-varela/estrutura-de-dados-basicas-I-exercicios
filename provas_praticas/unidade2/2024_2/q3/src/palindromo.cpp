#include "palindromo.h"
#include <stack>

using namespace std;
// e colocarmos as letras de uma palavra dentro de uma pilha, ao retirarmos essas letras, elas sairão na ordem invertida


bool ehPalindromo(string str)
{
    stack<char> pilha;
    
    // 1) insere na pilha ignorando os espaços em branco
    for(char ch : str)
    {
        
        if( ch != ' ') // checar se for diferente de um espaço em branco
        {
            pilha.push(ch); // empilha
        } 
        
    }
    
    // 2) compara a string original com o topo da pilha
    for(char ch: str){
        if (ch == ' ') // Se for um espaço na string original, pula ele
        {
            continue;
        }

        if (ch != pilha.top())
        {
            return false;
        }
        pilha.pop(); 
    }

    return true;
}