/*
 * Cifra RSA
 *
 * Criptoan�lise da cifra RSA
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
	 * Verifica se um dado natural � primo
	 * --> cand: natural
	 * <-- p: p=true, n � primo, p=false, n�o � primo
     */
	bool testaPrimo(mpz_t);	

	/*
	 * Crivo de Eratostenes
	 * --> n: inteiro
	 * <-- primos: vector de inteiros, contendo os primos at� n (inclusiv�)
	 */
	void crivoEratostenes(mpz_t n, mpz_t *contaPrimos, mpz_t primos[]); 
	/* 
	 * M�todo das Divis�es --- Criptoan�lise da cifra RSA
	 * Utiliza o Crivo de Eratostenes para obter uma lista de primos a testar
	 * --> n: inteiro, produto de dois primos
	 * <-- p,q: inteiros, primos tais que pq = n
	 */
	void metodoDivisoes(mpz_t n, mpz_t *p, mpz_t *q);	
	/* 
	 * M�todo da f�rmula geradora de primos 6k+-1 --- Criptoan�lise da cifra RSA
	 * --> n: inteiro, produto de dois primos
	 * <-- p,q: inteiros, primos tais que pq = n
	 */
	void formulaGeradora(mpz_t n, mpz_t p, mpz_t q);
	
	// M�todo de Fermat
	void metodoFermat(mpz_t n, mpz_t *p, mpz_t *q);
	
	/*
	 *  Gerar das Chaves
	 * --> p, q: primos (de grande dimens�o)
	 * <-- (e,n),(d,n): n=p*q, (e,n) - chave p�blica, (d,n) - chave privada
	 */
	void gerarChavesRSA(mpz_t p, mpz_t q, mpz_t *n, mpz_t *e, mpz_t *d);
	
	/*
	 * Gerar um primo (de grande dimens�o) --- crivo de Eratostenes
	 */
	 
	/* cifrar RSA
	 * --> m: inteiro (de grande dimens�o), bloco da mensagem
	 *     (e,n): chave p�blica
	 * <-- c: inteiro (de grande dimens�o) resultado da encripta��o de m, c=cifrarRSA(m,e,)
	 */
	int cifrarRSA(mpz_t m, mpz_t e, mpz_t n); 
	
	/* decifrar RSA 
	 * --> c: inteiro (de grande dimens�o), bloco da mensagem encriptada
	 *     (d,n): chave privada
	 * <-- m: inteiro (de grande dimens�o) resultado da desencripta��o de m=decifrarRSA(c,d,n)
	 */
	int decifrarRSA(mpz_t m, mpz_t d, mpz_t n); 
	
};

#endif
