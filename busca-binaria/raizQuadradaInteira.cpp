/**
 * @file raizQuadradaInteira.cpp
 * @brief Encontra a parte inteira da raiz quadrada de um número usando busca binária.
 * 
 * @copyright (c) 2024 Eiji Adachi Medeiros Barbosa
 * 
 * Este código é licenciado sob a Licença MIT.
 */

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"

/**
 * @brief Encontra a parte inteira da raiz quadrada de um número positivo usando busca binária.
 *
 * @param N O número positivo.
 * @return A parte inteira da raiz quadrada de N.
 */


// recebe: numero, inicio, fim, provisorio
// se o inicio for maior que o fim é retornado o provisorio
// é calculado o meio e o quadrado
// se o quadrado(meio/meio) for igual ao N então é retornado o meio (raiz quadrada)
// caso o quadrado seja MAIOR que o número, chama a recursão e passa o N, o inicio segue sendo o mesmo e o fim será o meio-1, e o provisorio segue o mesmo
// caso o quadrado seja MENOR que o número, chama a recursão passando o N o inicio que vai ser meio+1, o fim continua sendo o mesmo e o provisorio sera o meio

int raizQuadradaRecursiva(int N, int inicio, int fim, int provisorio){
    if (inicio > fim)
    {
        return provisorio;
    }

    int meio = (inicio + fim)/2;
    int quadrado = meio * meio;

    if(quadrado == N){
        return meio;
    } else if(quadrado > N){
        return raizQuadradaRecursiva(N, inicio, meio-1, provisorio);
    } else if(quadrado < N){
        return raizQuadradaRecursiva(N, meio+1, fim, meio); //provisorio = meio
    }

    return provisorio;
}

int raizQuadradaInteira(int N) {
    return raizQuadradaRecursiva(N, 0, N, 0);
}

TEST_CASE("Encontrar a Raiz Quadrada Inteira - Testes") {
    CHECK(raizQuadradaInteira(16) == 4);
    CHECK(raizQuadradaInteira(20) == 4);
    CHECK(raizQuadradaInteira(25) == 5);
    CHECK(raizQuadradaInteira(1) == 1);
    CHECK(raizQuadradaInteira(0) == 0);
}
