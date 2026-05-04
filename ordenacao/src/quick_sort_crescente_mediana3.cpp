#include <iostream>

void swap(int arr[], int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int medianade3(int arr[], int esquerda, int direita){
    int meio = (esquerda + direita)/2;

    // com os ifs eu quero deixar o menor valor fique na esquerda
    // e o maior valor fique na direita, assim o que ficar no meio é a mediana

    if (arr[esquerda] > arr[meio])
    {
        swap(arr, esquerda, meio);
    }
    
    if (arr[esquerda] > arr[direita])
    {
        swap(arr, esquerda, direita);
    }

    if (arr[meio] > arr[direita])
    {
        swap(arr, meio, direita);
    }

    // ex: [10, 5, 2]
    // [5, 10, 2]
    // [2, 10, 5]
    // [2, 5, 10] a mediana ficou no meio

    swap(arr, meio, direita); // a mediana que está no meio deve ir pra posição "direita"

    return arr[direita];
    
}

int particao(int arr[], int esquerda, int direita){
    int pivo = medianade3(arr, esquerda, direita);
    int fronteira = esquerda - 1;

    for (int i = esquerda; i <= direita-1; i++)
    {
        if (arr[i] <= pivo)
        {
            fronteira += 1;
            swap(arr, i, fronteira);
        }
        
    }

    swap(arr, direita, fronteira+1);

    return fronteira+1;
    
}

void quickSort(int arr[], int esquerda, int direita){
    if (esquerda < direita)
    {
        int p = particao(arr, esquerda, direita);
        quickSort(arr, esquerda, p-1);
        quickSort(arr, p+1, direita);
    }
    
}