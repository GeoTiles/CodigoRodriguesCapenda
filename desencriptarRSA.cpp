// Copyright (c) 2021
// vers�o 2.0 desenvolvido Doutor Pedro Quaresma

#include <gmp.h>
#include "cifraRSA.hpp"
#include <iostream>
#include <stdio.h>
#include <cstdint> // Permite a utiliza��o de int com um n�mero preciso de bytes

//#include "cifrasProduto.hpp" // Classe com as Cifras Produto

using namespace std;

int main(int argc, char *argv[]){
  
  //verificar o n�mero de argumento
  if(argc!=5){
    cout << "\n Utiliza��o: ./encriptarCP nomeFicheiroEntrada d,n(inteiros primos) nomeFicheiroSaida\n\n"; 
    return(1);
  }
  
  //Declara��o das vari�veis
  
  //fl -> o ficheiro de entrada(leitura) 
  //fe -> o ficheiro de saida(escrita) 
  
  FILE *fl,*fe;
  char *mensnormal, *menscifrada, ch;
  mpz_t d, n,m,mRSA;
  mpz_inits(d,n,m,mRSA);
  CifraRSA decifrador;
  
  
  //c�pia do ficheiro de entrada
  mensnormal = argv[1];
    
  // n 
  
  
  mpz_set_ui(d,atoi(argv[2]));
  mpz_set_ui(n,atoi(argv[3]));
  
  

  
  //c�pia do ficheiro de saida
  menscifrada = argv[4];
  
  
  //abrir o ficheiro para a leitura
  fl = fopen(mensnormal,"r");
  
  //verificar se o ficheiro foi aberto ou nao
  //caso contrario o programa termina
  if(fl == NULL){
    cout << "Imposs�vel abrir o ficheiro " << mensnormal << endl;
    return(2);
  }

  //Abrir o ficheiro para escrever a mensagem cifrada
  if((fe = fopen(menscifrada,"w")) == NULL){
    cout << "Imposs�vel criar o ficheiro " << menscifrada << endl;
    return(3);
  }

  // Encriptar da mensagem
	
	while (!feof(fl)){
		
		ch = fgetc(fl);
		mpz_set_ui(m,decifrador.toAscii(ch));
		decifrador.decifrarRSA(mRSA,m,d,n);
		fputc(decifrador.toChar(mpz_get_ui(mRSA)), fe);
		}
  
  //Fechar os ficheiros
  fclose(fl);
  fclose(fe);
  return(0);
  
  
}
