//

// bibliotecas do sistem
#include <iostream>
#include <stdlib.h>

// bibliotecas externas
#include <gmp.h>

// bibliotecas do projecto
#include "factorizarPrimos.hpp"  

using namespace std;

int main(int argc, char *argv[]){

  //Declaração das variáveis
  int aux;
  mpz_t n;
  
  FactorizarPrimos factorizador;

  mpz_init(n);

  do {
    cout << "aux=";
    cin >> aux;
    mpz_set_ui(n,aux);
    if (factorizador.testaPrimo(n)) { cout << "\t é primo\n";}
  } while (aux != 4);

  return 0;
  
}
