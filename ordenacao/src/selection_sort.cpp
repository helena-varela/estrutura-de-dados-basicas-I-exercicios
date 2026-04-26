#include "../include/ordenar.h"

void selectionSort(int arr[], int tamanho){

    for (int i = 0; i < tamanho-1; i++)
    {
        int min = i;

        for (int j = i+1; j < tamanho; j++)
        {
            if (arr[min] > arr[j])
            {
                min = j;
            }
            
        }

        if (i != min)
        {
            int temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp; 
        }
        
    }
    
}