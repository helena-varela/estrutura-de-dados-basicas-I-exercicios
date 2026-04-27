#include "../include/ordenar.h"
#include <string>

using namespace std;

int particao(string arr[], int esquerda, int direita){
    string pivo = arr[direita]; // escolhe o pivo como o ultimo elemento
    int fronteira = esquerda-1; // fronteira é o primeiro elemento menor 1

    for (int i = esquerda; i <= direita-1; i++) // pecorre todos os elementos menos o pivo
    {
        if (arr[i] <= pivo) // se achar um elemento menor que o pivo, incrementa a fronteira e troca com o elemento menor
        {
            fronteira = fronteira + 1;

            string temp = arr[fronteira];
            arr[fronteira] = arr[i];
            arr[i] = temp;

        }
    }
    // no final coloca o pivô em seu lugar que é após a fronteira
    string temp = arr[fronteira+1];
    arr[fronteira+1] = arr[direita];
    arr[direita] = temp;

    return fronteira+1; // retorna o lugar que ta o pivo (após a fronteira)
}

void quickSort(string arr[], int esquerda, int direita){
    if (esquerda < direita)
    {
        int pivo = particao(arr, esquerda, direita);
        quickSort(arr, esquerda, pivo-1);
        quickSort(arr, pivo+1, direita);
    }
    
}

void ordenar(string array[], int tamanho) {
    quickSort(array, 0, tamanho - 1);
}