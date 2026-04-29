#include <iostream>
#include <cmath>

using namespace std;

// Crie uma função que conte quantos números entre 0 e N são primos.

int contarPrimosAteN(int N){
    int qntd = 0;
    
    if (N <= 1) return 0;

    for (int i = 2; i <= N; i++){

        bool eh_primo = true;

        for (int j = 2; j*j<= i; j++)
        {
            if ((i % j == 0)){
                eh_primo = false;
                break;
            }
        }

        if (eh_primo) {
            qntd++;
        }
        
    }
    
    return qntd;
}

int main(){
    int testesPassados = 0;

    cout << "Teste 1: O resultado esperado é 4 e o valor retornado foi "<< contarPrimosAteN(10) << endl;
    if (contarPrimosAteN(10) == 4) testesPassados++;
    
    cout << "Teste 2: O resultado esperado é 8 e o valor retornado foi " << contarPrimosAteN(20) << endl;
    if (contarPrimosAteN(20) == 8) testesPassados++;
 
    cout << "Teste 3: O resultado esperado é 3 e o valor retornado foi " << contarPrimosAteN(5) << endl;
    if (contarPrimosAteN(5) == 3) testesPassados++;

    cout << "Teste 4: O resultado esperado é 0 e o valor retornado foi " << contarPrimosAteN(1) << endl;
    if (contarPrimosAteN(1) == 0) testesPassados++;

    cout << "Teste 5: O resultado esperado é 25 e o valor retornado foi " << contarPrimosAteN(100) << endl;
    if (contarPrimosAteN(100) == 25) testesPassados++;

    cout << "Sua implementação passou em " << testesPassados << " de 5 testes" << endl;

    return 0;
}