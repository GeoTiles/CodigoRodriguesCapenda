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

  //verificar o número de argumento
  if(argc!=2){
    cout << "\n Utilização: ./quebrarRSA n  \n\n"; 
    cout << "\n1 - Método das Divisões" << endl;
    cout << "\n2 - Método de Fermat" << endl;
    cout << "\n3 - Fórmula 6k +- 1" << endl;
    return 1;
  }
  
  //Declaração das variáveis
  int op;
  mpz_t n;
  
  FactorizarPrimos factorizador;

  mpz_init(n);
  mpz_set_ui(n,atoi(argv[1]));

  //Menu
  cout << "\nSeleccione o método para a quebra" << endl;
  cout << "\n1 - Método das divisões" << endl;
  cout << "\n2 - Método de Fermat" << endl;
  cout << "\n3 - Fórmula 6k +- 1" << endl;
  cin >> op;

  /*

  t = clock(); // tempo inicial
  aux.Fermat(n); // executar o método de Fermat
  t= clock()-t; // tempo total = tempo final - tempo inicial 
  cpu_time_used = ((double)t) / CLOCKS_PER_SEC; 
  cout << "tempo usado metodo de Fermat: " << cpu_time_used << endl;
  t= clock();   // tempo inicial
  aux.formulageradora(n);
  t= clock()-t; // tempo total = tempo final - tempo inicial 
  cpu_time_used = ((double)t) / CLOCKS_PER_SEC; 
  cout << "tempo usado formula geradora: " << cpu_time_used << endl;
  t= clock();

   */

  
  
  //Tratamento da opção
  switch(op){
  case 1:
    cifrador.metodoDivisoes(n); 
    break;
  case 2:
    cifrador.metodoFermat(n,&p,&q); 
    break;
  case 3:
    cifrador.formulaGeradora(n,&p,&q); 
    break;
  default:
    cout<< "\nEscolha não válida" << endl;
  }
  
 //verificando se a saida do meto é um primo
  if (!cifrador.testaPrimo(p) || !cifrador.testaPrimo (q)){
	  cout<< "P e q calculados nao sao primos" << endl;
	// return 0;
	  }
 cout<< "P = " << p << "  Q = " << q << endl;
  
  return 0;
  
}
