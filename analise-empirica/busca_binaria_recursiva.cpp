#include "busca.h"

int buscaBinariaRecursiva(const int arr[], int inicio, int fim, int alvo){
    int meio = (inicio + fim)/2;

    if (inicio > fim)
    {
        return -1;
    } 
    else if(arr[meio] > alvo){
        return buscaBinariaRecursiva(arr, 0, meio-1, alvo);
    } 
    else if(arr[meio] < alvo){
        return buscaBinariaRecursiva(arr, meio+1, fim, alvo);
    } 
    else if (arr[meio] == alvo){
        return meio;
    }
    return -1;
}

int busca(const int* arr, int tamanho, int chave) {
    return buscaBinariaRecursiva(arr, 0, tamanho-1, chave);
}