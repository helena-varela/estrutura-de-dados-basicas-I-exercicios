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
 * @brief Calcula a soma e o produto de todos os elementos de um array de inteiros.
 *
 * @param numeros Um array de inteiros.
 * @param tamanho O tamanho do array.
 * @return Um par onde o primeiro valor é a soma dos elementos e o segundo é o produto dos elementos.
 */

 std::pair<int, int> somaProdutoArrayRecursivo(const int numeros[], int tamanho, int interacao, std::pair<int, int>valores) {

    if (tamanho == interacao)
    {
        return valores;
    }

    valores.first = numeros[interacao] + valores.first;
    valores.second = numeros[interacao] * valores.second;

    return somaProdutoArrayRecursivo(numeros, tamanho, interacao +1, valores);
}

std::pair<int, int> somaProdutoArray(const int numeros[], int tamanho) {
    int soma = 0;
    int produto = 1;

    if (numeros == nullptr || tamanho <= 0)
    {
        return {0, 1};
    }

    return somaProdutoArrayRecursivo(numeros, tamanho, 0, {soma, produto});
}

TEST_CASE("Soma e Produto - Teste com elementos positivos") {
    int numeros[] = {1, 2, 3, 4};
    auto resultado = somaProdutoArray(numeros, 4);
    CHECK(resultado.first == 10);   // Soma
    CHECK(resultado.second == 24);  // Produto
}

TEST_CASE("Soma e Produto - Teste com elementos negativos") {
    int numeros[] = {-1, -2, -3, -4};
    auto resultado = somaProdutoArray(numeros, 4);
    CHECK(resultado.first == -10);   // Soma
    CHECK(resultado.second == 24);  // Produto
}

TEST_CASE("Soma e Produto - Teste com array vazio") {
    auto resultado = somaProdutoArray(nullptr, 0);
    CHECK(resultado.first == 0);  // Soma (neutro da soma é 0)
    CHECK(resultado.second == 1); // Produto (neutro do produto é 1)
}
