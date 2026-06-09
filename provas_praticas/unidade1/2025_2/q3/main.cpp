#define __CHECK_INTEGRIDADE__ 1 
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"

using namespace std;

int posicaoInsercao(int array[], int esquerda, int direita, int alvo)                                                                                                                                                                                          // versão: EAMB-1.0
{ // Begin ​
    throw "ERRO: Função ainda não foi implementada"; // remova esta linha ao implementar sua solução
} // End ​

TEST_CASE("Questão 3 - Testes da função posicaoInsercao") 
{
    int array1[] = {1, 3, 5, 7};
    int tam = sizeof(array1) / sizeof(int);

    CHECK( posicaoInsercao(array1, 0, tam-1, 0) == 0);
    CHECK( posicaoInsercao(array1, 0, tam-1, 2) == 1);
    CHECK( posicaoInsercao(array1, 0, tam-1, 4) == 2);
    CHECK( posicaoInsercao(array1, 0, tam-1, 6) == 3);
    CHECK( posicaoInsercao(array1, 0, tam-1, 8) == 4);
}
