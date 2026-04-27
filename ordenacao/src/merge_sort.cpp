#include "../include/ordenar.h"
#include <string>

void intercalar(string arr[], int inicio1, int inicio2, int fim2){
    int fim1 = inicio2 - 1;
    int i = inicio1;
    int j = inicio2;
    int k = 0;

    int tamanho = (fim2 - inicio1) + 1;
    string temp[tamanho];

    while (i <= fim1 && j <= fim2)
    {
        if (arr[i] < arr[j])
        {
            temp[k] = arr[i];
            i = i + 1;
        } else {
            temp[k] = arr[j];
            j = j + 1;
        }
        k = k + 1;
    }

    while (i <= fim1)
    {
        temp[k] = arr[i];
        i = i + 1;
        k = k + 1; 
    }
    
    while (j <= fim2)
    {
        temp[k] = arr[j];
        j = j + 1;
        k = k + 1;
    }
    
    for (int p = 0; p < tamanho; p++)
    {
        arr[inicio1 + p] = temp[p];
    }
    
}

void mergeSort(string arr[], int esquerda, int direita){

    if (esquerda < direita)
    {
        int meio = (direita + esquerda)/2;
        mergeSort(arr, esquerda, meio);
        mergeSort(arr, meio+1, direita);
        intercalar(arr, esquerda, meio+1, direita);
    }
    
}

void ordenar(string array[], int tamanho) {
    mergeSort(array, 0, tamanho - 1);
}