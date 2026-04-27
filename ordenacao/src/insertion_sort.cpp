#include "../include/ordenar.h"
#include <string>

void insertionSort(string arr[], int tamanho) {
    for (int i = 1; i < tamanho; i++) 
    {
        string novo = arr[i]; 
        int j = i-1;
        
        while (j>=0 && arr[j] > novo)
        {
            arr[j + 1] = arr[j];
            j = j-1;
        }

        arr[j+1] = novo;
    }
}

void ordenar(string array[], int tamanho) {
    insertionSort(array, tamanho);
}