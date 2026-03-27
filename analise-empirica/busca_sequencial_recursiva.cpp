#include "busca.h"

int busca(const int* arr, int tamanho, int chave) {
    if (tamanho == 0) {
        return -1; 
    }
    else if (arr[tamanho-1] == chave) {
        return tamanho-1;
    } 
    else {
        return busca(arr, tamanho-1, chave); 
    }
}