/**
 * @copyright (c) 2024 Eiji Adachi Medeiros Barbosa
 * 
 * Este código é licenciado sob a Licença MIT.
 */
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"
#include <utility>

using namespace std;

/**
 * @brief Encontra o menor e o maior elemento em um array de inteiros.
 *
 * @param numeros Um array de inteiros.
 * @param tamanho O tamanho do array.
 * @return Um par onde o primeiro valor é o menor elemento e o segundo é o maior elemento.
 * @throws std::invalid_argument se o array estiver vazio (tamanho == 0).
 */


std::pair<int, int> menorMaiorElementoRecursivo(const int numeros[], int tamanho, int interacao, std::pair<int, int> valores){
    if (tamanho == interacao)
    {
        return valores;
    }

    if (numeros[interacao] < valores.first)
    {
        valores.first = numeros[interacao];
    }

    if (numeros[interacao] > valores.second)
    {
        valores.second = numeros[interacao];
    }
    
    return menorMaiorElementoRecursivo(numeros, tamanho, interacao+1, valores);
    
}

std::pair<int, int> menorMaiorElemento(const int numeros[], int tamanho) {

    if (numeros == nullptr || tamanho <= 0) {
        return {0, 0}; 
    }

    int maior = numeros[0];
    int menor = numeros[0];
    return menorMaiorElementoRecursivo(numeros, tamanho, 0, {menor, maior});
}

TEST_CASE("Menor e Maior Elemento - Teste com elementos distintos") {
    int numeros[] = {3, 1, 4, 1, 5, 9};
    auto resultado = menorMaiorElemento(numeros, 6);
    CHECK(resultado.first == 1);
    CHECK(resultado.second == 9);
}

TEST_CASE("Menor e Maior Elemento - Teste com elementos iguais") {
    int numeros[] = {7, 7, 7};
    auto resultado = menorMaiorElemento(numeros, 3);
    CHECK(resultado.first == 7);
    CHECK(resultado.second == 7);
}

TEST_CASE("Menor e Maior Elemento - Teste com array unitário") {
    int numeros[] = {42};
    auto resultado = menorMaiorElemento(numeros, 1);
    CHECK(resultado.first == 42);
    CHECK(resultado.second == 42);
}
