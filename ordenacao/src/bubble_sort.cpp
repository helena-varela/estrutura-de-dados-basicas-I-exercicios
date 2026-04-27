#include "../include/ordenar.h"
#include <string>

void bubbleSort(string arr[], int tamanho){
    bool fez_swap = true;
    int fim = tamanho - 1;

    while (fez_swap)
    {
        fez_swap = false;

        for (int i = 0; i < fim; i++)
        {
            if (arr[i] > arr[i+1])
            {
                string temp = arr[i+1];
                arr[i+1] = arr[i];
                arr[i] = temp;   
            }   
        }
        fim = fim - 1;
    }
}

void ordenar(string array[], int tamanho) {
    bubbleSort(array, tamanho);
}