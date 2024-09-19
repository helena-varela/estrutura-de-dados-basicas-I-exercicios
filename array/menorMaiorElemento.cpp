/**
 * @copyright (c) 2024 Eiji Adachi Medeiros Barbosa
 * 
 * Este código é licenciado sob a Licença MIT.
 */
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"
#include <stdexcept>

/**
 * @brief Encontra o menor e o maior elemento em um array de inteiros.
 *
 * @param numeros Um array de inteiros.
 * @param tamanho O tamanho do array.
 * @return Um par onde o primeiro valor é o menor elemento e o segundo é o maior elemento.
 * @throws std::invalid_argument se o array estiver vazio (tamanho == 0).
 */
std::pair<int, int> menorMaiorElemento(const int numeros[], int tamanho) {
    return {-1, -1}; // é assim que se retorna um par: colocar um par de valores envoltos num par de colchetes
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

TEST_CASE("Menor e Maior Elemento - Teste com array vazio") {
    CHECK_THROWS_AS(menorMaiorElemento(nullptr, 0), std::invalid_argument);
}
