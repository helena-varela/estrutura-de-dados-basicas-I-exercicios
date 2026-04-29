#include <iostream>
#include <cmath>

using namespace std;

// Crie uma função que verifique se um número é primo. A função deve retornar true se o
// número for primo e false caso contrário.

bool ehPrimo(int numero){
    // lógica: se o número for menor ou igual a 1 ele não é primo 
    if (numero <= 1) return false;

    // então fazemos um for do número 2 até a raiz quadrada do número
    // se o resto da divisão do número for igual a 0 então não é primo

    for (size_t i = 2; i <= sqrt(numero); i++){
        if ((numero % i == 0)) return false;
    }

    // caso não retornar false em nenhuma das opções então ele é primo
    return 1;
}

int main(){
    int testesPassados = 0;

    cout << "Teste 1: O resultado esperado é 1 e o valor retornado foi " << ehPrimo(5) << endl;
    if (ehPrimo(5) == true) testesPassados++;

    cout << "Teste 2: O resultado esperado é 0 e o valor retornado foi " << ehPrimo(10) << endl;
    if (ehPrimo(10) == false) testesPassados++;

    cout << "Teste 3: O resultado esperado é 1 e o valor retornado foi " << ehPrimo(13) << endl;
    if (ehPrimo(13) == true) testesPassados++;

    cout << "Teste 4: O resultado esperado é 0 e o valor retornado foi " << ehPrimo(1) << endl;
    if (ehPrimo(1) == false) testesPassados++;

    cout << "Teste 5: O resultado esperado é 1 e o valor retornado foi " << ehPrimo(17) << endl;
    if (ehPrimo(17) == true) testesPassados++;

    cout << "Sua implementação passou em " << testesPassados << " de 5 testes" << endl;

    return 0;
}