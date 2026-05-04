#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"

/**
 * @brief Função auxiliar recursiva para encontrar a posição de inserção.
 */
/**
 * @brief Determina a posição onde o elemento deve ser inserido para manter o array ordenado.
 * * @param arr O array ordenado.
 * @param tamanho O número de elementos no array.
 * @param alvo O valor a ser inserido.
 * @return O índice da posição de inserção.
 */

// recebo: array, inicio, fim, alvo
// se o inicio for maior que o fim retorna o próprio inicio
// é calculado o meio
// se o array[meio] for IGUAL ao alvo, retorna o meio (quer dizer que achou um número igual ao númeor alvo)
// se o array[meio] for MAIOR que o alvo, chama a função passando o arr, meio+1, fim, alvo
// se o array[meio] for MENOR que o alvo, chama a função passando o arr, inicio, meio-1, alvo


 int encontrarPosicaoInsercaoRecursivo(const int arr[], int inicio, int fim, int alvo){
    if (inicio > fim)
    {
        return inicio; // quando o inicio cruzar o fim, retorna onde o início parou
    }

    int meio = (inicio + fim)/2;
    
    if (arr[meio] == alvo) // se ese valor já existir no array ele insere no mesmo lugar
    {
        return meio;
    } else if(arr[meio] > alvo){
        return encontrarPosicaoInsercaoRecursivo(arr, inicio, meio-1, alvo);
    }
    else if (arr[meio] < alvo){ 
        return encontrarPosicaoInsercaoRecursivo(arr, meio+1, fim, alvo);
    }
 }  


int posicaoInsercao(const int arr[], int tamanho, int alvo) {
    return encontrarPosicaoInsercaoRecursivo(arr, 0, tamanho - 1, alvo);
}

TEST_CASE("Posição de Inserção - Testes") {
    int arr[] = {1, 3, 5, 6};
    int tam = 4;

    // Caso 1: Inserir no meio (o 2 deve entrar no lugar do 3, índice 1)
    CHECK(posicaoInsercao(arr, tam, 2) == 1);

    // Caso 2: O elemento já existe (retorna o próprio índice do 5, que é 2)
    CHECK(posicaoInsercao(arr, tam, 5) == 2);

    // Caso 3: Inserir no início (o 0 deve entrar no índice 0)
    CHECK(posicaoInsercao(arr, tam, 0) == 0);

    // Caso 4: Inserir no fim (o 7 deve entrar após o 6, índice 4)
    CHECK(posicaoInsercao(arr, tam, 7) == 4);

    // Caso 5: Array vazio (deve entrar na posição 0)
    int arrVazio[] = {};
    CHECK(posicaoInsercao(arrVazio, 0, 10) == 0);
    
    // Caso 6: Mais um teste de inserção no meio
    int arr2[] = {10, 20, 30, 40};
    CHECK(posicaoInsercao(arr2, 4, 25) == 2);
}