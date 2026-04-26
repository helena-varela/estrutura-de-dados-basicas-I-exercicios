#include "../include/ordenar.h"

void bubbleSort(int arr[], int tamanho){
    bool fez_swap = true;
    int fim = tamanho;

    while (fez_swap)
    {
        fez_swap = false;

        for (int i = 0; i < fim; i++)
        {
            if (arr[i] > arr[i+1])
            {
                int temp = arr[i+1];
                arr[i+1] = arr[i];
                arr[i] = temp;   
            }   
        }
        fim = fim - 1;
    }
}