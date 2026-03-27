#include "busca.h"

int busca(const int* arr, int tamanho, int chave) {
    int inicio = 0, fim = tamanho-1, meio;

    do
    {
        meio = (inicio + fim)/2;
        if (chave > arr[meio])
        {
            inicio = meio + 1;
        }
        else if(chave < arr[meio]){
            fim = meio - 1;
        }
        else {
            return meio;
        }
        
    } while (inicio <= fim);
    
    return -1;
}