#include <iostream>
#include <cstdio>
#include <cstdlib>

#include <gmp.h>

#include "cifraRSA.hpp"

using namespace std;

int main(int argc, char *argv[]) {

  //Declaração de variáveis
  FILE *pfCPub, *pfCPriv;
  char *chavePublica, *chavePrivada;
  char str_e[1000], str_d[1000], str_n[1000];
  int bitsChave;
  mpz_t e, d, n;

  CifraRSA chvPP;
  
  mpz_init(d); //inicializacao de d
  mpz_init(n); //inicializacao de n

  if (argc < 4){ 
    cout << "\nUtilizacao: geraChavesRSA <nome_ficheiro_chave_pública> <nome_ficheiro_chave_privada> <num_bits_chave>\n\n";
    return(1);
  }
  
  // obtém os argumentos da linha de comando
  chavePublica = argv[1];
  chavePrivada = argv[2];
  bitsChave = atoi(argv[3]);

  if ((pfCPub = fopen(chavePublica,"w")) == NULL) {
    cout << "Não foi possível abrir o ficheiro " << chavePublica << endl;
    return(2);
  }
  else if ((pfCPriv = fopen(chavePrivada,"w")) == NULL) {
    cout << "Não foi possivel abrir para escrita o ficheiro " << chavePrivada << endl;
    return(3);
  }

  //gera as chaves pública e privada
  chvPP.geradorChaves(pfCPub,pfCPriv,bitsChave);

  fclose(pfCPub);
  fclose(pfCPriv);

  return(0);
} 
  

    
