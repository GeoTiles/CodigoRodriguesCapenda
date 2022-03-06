#include <iostream>

#include <cstdio>
#include <cstdlib>

#include <gmp.h>

#include "cifraRSA.hpp"

using namespace std;

int main(int argc, char *argv[]) {
  //Declaracao de variaveis
  FILE *pfM, *pfC, *cPrivada;
  char *msginicial,*msgfinal, *chavePriv;
  char str_e[1000], str_d[1000], str_n[1000]; 
  mpz_t e, d, n;

  CifraRSA cfr;
  
  mpz_init(d); //inicializacao de d
  mpz_init(n); //inicializacao de n

  if (argc < 4){ 
    cout << "\nUtilizacao: ./desencriptarRSA <ficheiro_chave_privada> <ficheiro_texto_cifrado> <ficheiro_texto_decifrado>\n\n";
    return(1);
  }
  
  // obtem os argumentos da linha de comando
  chavePriv = argv[1];
  msginicial = argv[2];
  msgfinal = argv[3];
  
  if ((cPrivada=fopen(chavePriv,"r")) == NULL){
    cout << "Não foi possível abrir o ficheiro, " << chavePriv << ",contendo a Chave Pública,  para leitura\n";
    return(2);
  }

  if ((pfM = fopen(msginicial,"r")) == NULL) {
    cout << "Não foi possível abrir o ficheiro do texto cifrado, " << msginicial << ", para leitura\n";
    return(3);
  }
  else if ((pfC = fopen(msgfinal,"w")) == NULL) {
    cout << "Não foi possível abrir o ficheiro do texto decifrado, " << msgfinal << ", para escrita\n";
    return(4);
  }
    
  fscanf(cPrivada,"%s %s ", str_d, str_n);
  fclose(cPrivada);

  mpz_set_str(d, str_d, 0);
  mpz_set_str(n, str_n, 0);
  // vai fazer a desencriptação
  cfr.tratablocoD(pfM, pfC, d, n);

  fclose(pfM);
  fclose(pfC);

  return(0);
} 

    
