#include "busca.h"

int busca(const int* arr, int tamanho, int chave) {
    for (int i = 0; i < tamanho; i++)
    {
        if (arr[i] == chave)
        {
            return i;
        }
    }
    return -1;
}