/**
 * @file exponenciacaoRecursiva.cpp
 * @brief Realizar a exponenciação de dois números inteiros usando multiplicações sucessivas e recursão.
 * 
 * @copyright (c) 2024 Eiji Adachi Medeiros Barbosa
 * 
 * Este código é licenciado sob a Licença MIT.
 */

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"

/**
 * @brief Calcula a exponenciação de X elevado a Y usando multiplicações sucessivas e recursão.
 *
 * @param X A base da exponenciação.
 * @param Y O expoente.
 * @return O resultado de X^Y.
 */
int exponenciacao(int X, int Y) {
    if (Y == 0)
    {
        return 1;
    } else {
        return X * exponenciacao(X, Y-1);
    }
    
}
// ex: 2^3
// X = 2, Y = 3
// 2 * exp() -> 2 * 4 = 8
// X = 2, Y = 2
// 2 * exp() -> 2 * 2 = 4
// X = 2, Y = 1
// 2 * exp() -> 2 * 1 = 2 
// X = 2, Y =0
// retorna 1, pq qualquer número elevado a 0 da 1

TEST_CASE("Exponenciação de Dois Números Inteiros - Testes") {
    CHECK(exponenciacao(3, 4) == 81);
    CHECK(exponenciacao(2, 0) == 1);
    CHECK(exponenciacao(5, 1) == 5);
    CHECK(exponenciacao(2, 5) == 32);
    CHECK(exponenciacao(10, 3) == 1000);
}
