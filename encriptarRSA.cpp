#include <iostream>

#include <cstdio>
#include <cstdlib>

#include <gmp.h>

#include "cifraRSA.hpp"

using namespace std;

int main(int argc, char *argv[]) {
  //Declaracao de variaveis
  FILE *pfM, *pfC, *CPublica;
  char *msginicial,*msgfinal, *chavePub;
  char str_e[COMPCHAVES], str_d[COMPCHAVES], str_n[COMPCHAVES]; 
  mpz_t e, d, n;

  CifraRSA cfr;
  
  mpz_init(e); //inicializacao de e
  mpz_init(n); //inicializacao de n

  if (argc < 4){ 
    cout << "\nUtilizacao: ./encriptarRSA <ficheiro_chave_pública> <ficheiro_texto_claro> <ficheiro_texto_cifrado>\n\n";
    return(1);
  }
  
  // obtem os argumentos da linha de comando
  chavePub = argv[1];
  msginicial = argv[2];
  msgfinal = argv[3];

  if ((CPublica=fopen(chavePub,"r")) == NULL){
    cout << "Não foi possível abrir o ficheiro, " << chavePub << ",contendo a Chave Pública,  para leitura\n";
    return(2);
  }  
  if ((pfM = fopen(msginicial,"r")) == NULL) {
    cout << "Não foi possível abrir o ficheiro do texto inicial, " << msginicial << ", para leitura\n";
    return(3);
  } else if ((pfC = fopen(msgfinal,"w")) == NULL) {
    cout << "Não foi possível abrir o ficheiro do texto cifrado, " << msgfinal << ", para escrita\n";
    return(4);
  }          

  fscanf(CPublica,"%s %s ", str_e, str_n);
  fclose(CPublica);
  mpz_set_str(e, str_e, 0);
  mpz_set_str(n, str_n, 0);
  cfr.tratablocoE(pfM, pfC, e, n);

  fclose(pfM);
  fclose(pfC);

  return(0);
} 

    
