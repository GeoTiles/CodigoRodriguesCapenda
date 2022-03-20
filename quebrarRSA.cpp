//

// bibliotecas do sistem
#include <iostream>
#include <stdlib.h>
#include <time.h> // biblioteca C para o cálculo de tempo (e.g. tempos de execução)

// bibliotecas externas
#include <gmp.h>

// bibliotecas do projecto
#include "factorizarPrimos.hpp"  

using namespace std;

int main(int argc, char *argv[]){
  clock_t t;
  long double cpu_time_used;

  //Declaração das variáveis
  int op;
  mpz_t n;
  
  FactorizarPrimos factorizador;

  if (argc < 2){ 
    cout << "\nUtilizacao: ./quebrarRSA <n> \t (com n=p*q)\n";
    return(1);
  }
  
  mpz_init(n);
  mpz_set_str(n,argv[1],10);


  t = clock(); // tempo inicial
  factorizador.metodoEuclides(n); // executar o método de Fermat
  t= clock()-t; // tempo total = tempo final - tempo inicial 
  cpu_time_used = ((double)t) / CLOCKS_PER_SEC; 
  cout << "tempo usado metodo de Fermat: " << cpu_time_used << endl;


  /*
  t= clock();   // tempo inicial
  aux.formulageradora(n);
  t= clock()-t; // tempo total = tempo final - tempo inicial 
  cpu_time_used = ((double)t) / CLOCKS_PER_SEC; 
  cout << "tempo usado formula geradora: " << cpu_time_used << endl;
  t= clock();
   */


  return 0;
  
}
