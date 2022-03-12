// Copyright (c) 2021, Pedro Quaresma <pedro@mat.uc.pt>


#include <gmp.h>

#include "cifraRSA.hpp"  
#include <iostream>
#include <stdlib.h>

using namespace std;



int main(int argc, char *argv[]){


  

  //verificar o número de argumento
  if(argc!=2){
    cout << "\n Utilização: ./quebrarRSA n  \n\n"; 
    return 1;
  }
  
  //Declaração das variáveis
  int op;
  mpz_t n;
  CifraRSA cifrador;
  

  //   
  mpz_init(n);
  mpz_set_ui(n,atoi(argv[1]));

  
  
  //Menu
  cout << "\nSeleccione o metodo para a quebra" << endl;
  cout << "\n1 - Metodo das divisoes" << endl;
  cout << "\n2 - Metodo de Fermat" << endl;
  cout << "\n3 - Formula 6k +- 1" << endl;
  cin >> op;
  
  
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
		cout<< "\nEscolha nao valida" << endl;
	}
  
 //verificando se a saida do meto é um primo
  if (!cifrador.testaPrimo(p) || !cifrador.testaPrimo (q)){
	  cout<< "P e q calculados nao sao primos" << endl;
	// return 0;
	  }
 cout<< "P = " << p << "  Q = " << q << endl;
  
  return 0;
  
}
