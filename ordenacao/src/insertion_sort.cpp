#include "../include/ordenar.h"

void insertionSort(int arr[], int tamanho){
    for (int i = 1; i < tamanho; i++)
    {
        int novo = arr[i];
        int j = i-1;
        
        while (j>=0 && arr[j] > novo)
        {
            arr[j + 1] = arr[j];
            j = j-1;
        }

        arr[j+1] = novo;
    }
    
}