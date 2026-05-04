void swap(int arr[], int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int mediana(int arr[], int esquerda, int direita){
    int meio = (esquerda + direita)/2;

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
    
    swap(arr, meio, direita);

    return arr[direita];
    
}

int particao(int arr[], int esquerda, int direita){
    int pivo = mediana(arr, esquerda, direita);
    int fronteira = esquerda - 1;

    for (int i = esquerda; i <= direita-1; i++)
    {
        if (arr[i] >= pivo)
        {
            fronteira += 1;
            swap(arr, i, fronteira);
        }
        
    }
    
    swap(arr, direita, fronteira+1);

    return fronteira+1;
}

void quicksort(int arr[], int esquerda, int direita){
    if (esquerda < direita)
    {
        int p = particao(arr, esquerda, direita);
        quicksort(arr, esquerda, p-1);
        quicksort(arr, p+1, direita);

    }
    
}