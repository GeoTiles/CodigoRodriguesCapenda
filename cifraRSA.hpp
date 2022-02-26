/*
 * Cifra RSA
 *
 * Criptoanálise da cifra RSA
 */

#include <gmp.h>
#include <cstdio> // para poder usar FILE
#include <cmath>  // sqrt

#ifndef CIFRARSA
#define CIFRARSA

class CifraRSA {
private:

    int comprimentoVector = 5000;

public:
	/*
	 * Converte um char para int
	 * --> ch: char
	 * <-- m: inteiro referente ao numero Ascii do char ch
     */
	int toAscii(char m);
	char toChar(int m);
    /*
	 * Verifica se um dado natural é primo
	 * --> cand: natural
	 * <-- p: p=true, n é primo, p=false, não é primo
     */
	bool testaPrimo(mpz_t);	

	/*
	 * Crivo de Eratostenes
	 * --> n: inteiro
	 * <-- primos: vector de inteiros, contendo os primos até n (inclusivé)
	 */
	void crivoEratostenes(mpz_t n, mpz_t *contaPrimos, mpz_t primos[]); 
	/* 
	 * Método das Divisões --- Criptoanálise da cifra RSA
	 * Utiliza o Crivo de Eratostenes para obter uma lista de primos a testar
	 * --> n: inteiro, produto de dois primos
	 * <-- p,q: inteiros, primos tais que pq = n
	 */
	void metodoDivisoes(mpz_t n, mpz_t *p, mpz_t *q);	
	/* 
	 * Método da fórmula geradora de primos 6k+-1 --- Criptoanálise da cifra RSA
	 * --> n: inteiro, produto de dois primos
	 * <-- p,q: inteiros, primos tais que pq = n
	 */
	void formulaGeradora(mpz_t n, mpz_t p, mpz_t q);
	
	// Método de Fermat
	void metodoFermat(mpz_t n, mpz_t *p, mpz_t *q);
	
	/*
	 *  Gerar das Chaves
	 * --> p, q: primos (de grande dimensão)
	 * <-- (e,n),(d,n): n=p*q, (e,n) - chave pública, (d,n) - chave privada
	 */
	void gerarChavesRSA(mpz_t p, mpz_t q, mpz_t *n, mpz_t *e, mpz_t *d);
	
	/*
	 * Gerar um primo (de grande dimensão) --- crivo de Eratostenes
	 */
	 
	/* cifrar RSA
	 * --> m: inteiro (de grande dimensão), bloco da mensagem
	 *     (e,n): chave pública
	 * <-- c: inteiro (de grande dimensão) resultado da encriptação de m, c=cifrarRSA(m,e,)
	 */
	int cifrarRSA(mpz_t m, mpz_t e, mpz_t n); 
	
	/* decifrar RSA 
	 * --> c: inteiro (de grande dimensão), bloco da mensagem encriptada
	 *     (d,n): chave privada
	 * <-- m: inteiro (de grande dimensão) resultado da desencriptação de m=decifrarRSA(c,d,n)
	 */
	int decifrarRSA(mpz_t m, mpz_t d, mpz_t n); 
	
};

#endif
