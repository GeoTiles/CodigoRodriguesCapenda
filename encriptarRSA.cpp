// Copyright (c) 2021, Pedro Quaresma <pedro@mat.uc.pt>


#include <gmp.h>

#include "cifraRSA.hpp"  
#include <iostream>
#include <stdlib.h>

using namespace std;



int main(int argc, char *argv[]){

  //verificar o número de argumento
  if(argc!=5){
    cout << "\n Utilização: ./encriptarCP nomeFicheiroEntrada e d nomeFicheiroSaida\n\n"; 
    return(1);
  }
  
  //Declaração das variáveis
  
  //fl -> o ficheiro de entrada(leitura) 
  //fe -> o ficheiro de saida(escrita) 
  
  FILE *fl,*fe;
  char *mensnormal, *menscifrada, ch;
  int m;
  mpz_t e, n;
  mpz_inits(e,n);
  CifraRSA cifrador;
  
  
  //cópia do ficheiro de entrada
  mensnormal = argv[1];
    
  // n 
  
	mpz_set_ui(e,atoi(argv[2]));
    mpz_set_ui(n,atoi(argv[3]));
  
  
  //cópia do ficheiro de saida
  menscifrada = argv[4];
  
  
  //abrir o ficheiro para a leitura
  fl = fopen(mensnormal,"r");
  
  //verificar se o ficheiro foi aberto ou nao
  //caso contrario o programa termina
  if(fl == NULL){
    cout << "Impossível abrir o ficheiro " << mensnormal << endl;
    return(2);
  }

  //Abrir o ficheiro para escrever a mensagem cifrada
  if((fe = fopen(menscifrada,"w")) == NULL){
    cout << "Impossível criar o ficheiro " << menscifrada << endl;
    return(3);
  }

  // Encriptar da mensagem
	
	while (!feof(fl)){
		ch = fgetc(fl);
		m = cifrador.toAscii(ch);
		fputc(cifrador.toChar(cifrador.cifrarRSA(m,e,n)), fe);
	
		}
  
  //Fechar os ficheiros
  fclose(fl);
  fclose(fe);
  return(0);
  
}
