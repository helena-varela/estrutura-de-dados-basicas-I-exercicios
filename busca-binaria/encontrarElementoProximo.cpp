/**
 * @file encontrarElementoProximo.cpp
 * @brief Encontra o elemento mais próximo de um valor alvo em um array ordenado.
 * 
 * @copyright (c) 2024 Eiji Adachi Medeiros Barbosa
 * 
 * Este código é licenciado sob a Licença MIT.
 */

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"

/**
 * @brief Encontra o elemento mais próximo de um valor alvo em um array ordenado.
 *
 * @param arr O array ordenado de inteiros.
 * @param tamanho O tamanho do array.
 * @param alvo O valor alvo.
 * @return O valor do elemento mais próximo ao alvo.
 */

int encontrarElementoProximoRecursivo(const int arr[], int inicio, int fim, int alvo, int tamanho){
    if(inicio > fim){
        // Se o fim passou da borda esquerda, o único candidato é o inicio
        if (fim < 0) return arr[inicio];
        // Se o inicio passou da borda direita, o único candidato é o fim
        if (inicio >= tamanho) return arr[fim];

        if (abs(arr[inicio] - alvo) < abs(arr[fim] - alvo))
        {
            return arr[inicio];
        } else {
            return arr[fim];
        }
        
    }
    
    int meio = (inicio + fim)/2;
    
    if (arr[meio] == alvo)
    {
        return arr[meio];
    } else if(arr[meio] > alvo){
        return encontrarElementoProximoRecursivo(arr, inicio, meio-1, alvo, tamanho);
    } else if(arr[meio] < alvo){
        return encontrarElementoProximoRecursivo(arr, meio+1, fim, alvo, tamanho);
    }
    
}

int encontrarElementoProximo(const int arr[], int tamanho, int alvo) {
    return encontrarElementoProximoRecursivo(arr, 0, tamanho - 1, alvo, tamanho);
}

TEST_CASE("Encontrar o Elemento Mais Próximo - Testes") {
    int arr1[] = {1, 3, 5, 7, 9};
    CHECK(encontrarElementoProximo(arr1, 5, 4) == 3);
    CHECK(encontrarElementoProximo(arr1, 5, 8) == 7);
    CHECK(encontrarElementoProximo(arr1, 5, 5) == 5);
    CHECK(encontrarElementoProximo(arr1, 5, 10) == 9);
}
