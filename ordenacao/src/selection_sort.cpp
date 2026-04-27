#include "../include/ordenar.h"
#include <string>

using namespace std;

void selectionSort(string arr[], int tamanho){

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
            string temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp; 
        }
        
    }
    
}

void ordenar(string array[], int tamanho) {
    selectionSort(array, tamanho);
}