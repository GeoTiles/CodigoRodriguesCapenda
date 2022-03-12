
#ifndef CHAVESRSA
#define CHAVESRSA

#define COMPCHAVES 1500

class CifraRSA {
public:

  // Métodos para a Geração de Chaves
  
  /* 
   * Gera um primo aleatório
   * --> ???
   *     seed, valor inicial (semente) para o gerador de números aleatórios
   * <-- string com o número primo gerado
   */
  char* randomprime(char fmt[], unsigned long seed, unsigned long n);

  
  /*
   * Gera as chaves RSA
   * --> primos 
   *     ponteiros para os ficheiros
   * <-- (e,n) e (d,n), chaves públicas, escritas nos ficheiros respectivos   
   */
  void gerarchaves(char str_p[], char str_q[], char str_e[], char str_d[], char str_n[]);
  
  /*
   * Chama por duas vezes o gerador de números primos e depois chama a função de geração de chaves 
   * --> Ponteiros para os ficheiros de escrita
   *     número de bits dos primos gerados
   * <-- As chaves, escritas nos ficheiros dados
   */
  void geradorChaves(FILE *,FILE *,int);


  // Métodos para a implementação da Cifra RSA
  
  /*
   *
   */
  int mod(int numero, int base);

  /*
   *
   */
  void escreveBloco(FILE *pfC, mpz_t bloco);

  /*
   *
   */
  void encriptar(FILE *pfC,mpz_t bloco, mpz_t e, mpz_t n);

  /*
   *
   */
  void desencriptar(FILE *pfC, mpz_t bloco, mpz_t d, mpz_t n);

  /*
   *
   */
  void tratablocoE(FILE *pfM, FILE *pfC,mpz_t e,mpz_t n);

  /*
   *
   */
  void tratablocoD(FILE *pfM, FILE *pfC,mpz_t d,mpz_t n);


};

#endif
