/*
 * Métodos para Criptoanálise da cifra RSA
 * 
 * Factorização n=p*q, com 'p' e 'q' números primos usados para gerar
 * a chave pública do método RSA
 * 
 * --> (e,n) -- uma dada chave pública (método RSA)
 * <-- p, q -- os factores primos de 'n'
 */
  
#ifndef FACTORIZAR
#define FACTORIZAR

#define COMPCHAVES 1500

class FactorizarPrimos {
public:

  /*
   * Força Bruta - tenta-se a divisão sucessiva por todos os números
   * primos até ao maior inteiro contido na raiz quadrada de n
   * --> n
   * <-- p,q -- com n=p*q
   */ 
  void forcaBruta(const mpz_t,mpz_t, mpz_t);
  
  /*
   * Método Fermat - consiste em encontrar dois inteiros a e b que
   * permitam representar o número natural n como a diferença de dois
   * quadrados: n = a^2-b^2 <=> n = (a-b)(a+b)
   * --> n
   * <-- p,q -- com n=p*q
   */
  void metodoFermat(const mpz_t,mpz_t, mpz_t);

  /*
   * Formula geradora: p = 6k+-1, gera primos sucessivos, embora também 
   * gere números que não são primos   
   * --> n
   * <-- p,q -- com n=p*q
   */ 
  void formulaGeradora(const mpz_t,mpz_t, mpz_t);

  /*
   * Método de Euclides - Basta multiplicar todos os números primos
   * entre 2 e o maior inteiro contido na raiz quadrada de
   * n,calculando de seguida o mdc entre esse produto e n.
   * --> n
   * <-- p,q -- com n=p*q
   */
  void metodoEuclides(const mpz_t,mpz_t, mpz_t);
};

#endif
