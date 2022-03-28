// bibliotecas do sistem
#include <iostream>
#include <stdlib.h>
// biblioteca C para o cálculo dos tempos de execução
#include <time.h> 

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
  mpz_t n,p,q;
  
  FactorizarPrimos factores;

  if (argc < 2){ 
    cout << "\nUtilizacao: ./quebrarRSA <n> \t (com n=p*q)\n";
    return(1);
  }
  
  mpz_init(n);
  mpz_init(p);
  mpz_init(q);
  
  mpz_set_str(n,argv[1],10);

  // Força Bruta
  /*t = clock(); // tempo inicial
  factores.forcaBruta(n,p,q);
  t= clock()-t; // tempo total = tempo final - tempo inicial 
  cpu_time_used = ((double)t) / CLOCKS_PER_SEC; 
  cout << "tempo usado método da Força Bruta: " << cpu_time_used << endl;
  */
  // Método Fermat
  t = clock(); // tempo inicial
  factores.metodoFermat(n,p,q);
  t= clock()-t; // tempo total = tempo final - tempo inicial 
  cpu_time_used = ((double)t) / CLOCKS_PER_SEC; 
  cout << "tempo usado método de Fermat: " << cpu_time_used << endl;

  // Fórmula Geradora 6k+-1
  t= clock();   // tempo inicial
  factores.formulaGeradora(n,p,q);
  t= clock()-t; // tempo total = tempo final - tempo inicial 
  cpu_time_used = ((double)t) / CLOCKS_PER_SEC; 
  cout << "tempo usado fórmula geradora: " << cpu_time_used << endl;
  t= clock();
  /*
  // Método de Euclides
  t= clock();   // tempo inicial
  factores.metodoEuclides(n,p,q);
  t= clock()-t; // tempo total = tempo final - tempo inicial 
  cpu_time_used = ((double)t) / CLOCKS_PER_SEC; 
  cout << "tempo usado, Método de Euclides: " << cpu_time_used << endl;
  t= clock();
  */
  return(0);  
}




/*

Gerar chaves públicas de n bits

8 bits - Força Bruta: 5.6e-05s
 187
16 bits - Força Bruta: 8.3e-05s
 31439
24 bits - Força Bruta: 0.000502s
 9030097
32 bits - Força Bruta: 0.010998s
 3279646673
40 bits - Força Bruta: 0.178782s
 827908152161
48 bits - Força Bruta: 3.95128s
 280256389051271
56 bits - Força Bruta: 38.5596s
 41615198928269563
64 bits - Força Bruta: 1064.85s
 18060848976177946303
72 bits
 4427362412524367531927
80 bits
 1190096951745269742231019

128 bits
 339119943716719321666552368520142215723
 333987964804260144402931254225994218101

*/
