
#include <gmp.h>
#include <iostream>

#include "cifraRSA.hpp"

// ===//Fun��es Auxiliares (private)//===
 

char CifraRSA::toChar(int c){
	 return static_cast<char>(c);
	}
int CifraRSA::toAscii(char m ){
	
	return static_cast<int>(m);
	
	}
bool CifraRSA::testaPrimo(mpz_t cand) {
	mpz_t i, aux;
	mpz_init(aux);
	
	for (mpz_init_set_ui(i,2); mpz_cmp(i,cand-1)<= 0; mpz_add_ui(i,i,1)) {
		 mpz_tdiv_q(aux, cand,i);
		if (mpz_cmp_ui(aux,0)== 0) {
			return false;
		}
	}
    return true;
}

void CifraRSA::crivoEratostenes(mpz_t n, mpz_t *contaPrimos, mpz_t primos[]){
	// n > 2
	// lista de primos at� n (inclusiv�)
	
	mpz_t i;
	mpz_t candidatos[comprimentoVector];
	contaPrimos = 0;
	
	for(mpz_init_set(i,0); mpz_cmp_ui(i,comprimentoVector)<0; mpz_add_ui(i,i,1))
	//	mpz_set(candidatos[i],i+2);
	
	/*  
	 *  inicializar, candidatos[2,3,4,5,6,7,...,n]
	 *  i = 0;
	 *  enquanto (i <= n-2)
	 *    // o primeiro elemento de candidatos (n�o nulo) � primo 
	 *    enquanto candidatos[i] � zero 
	 *         i++;
	 *    fimenquanto
	 *    primos[contaPrimos] <- candidatos[i];
	 *    contaPrimos++;
	 *    // aplicar o crivo candidatos[i] ---> i=0 ---> 2
	 *       ---> candidatos[0,3,0,5,0,7,...,n] ---> coloca a zero todos os m�ltiplos de 2...
	 * 
	 * 
	 */
}

// ===//(fim) Fun��es Auxiliares (private)//===

//===Criptoan�lise da Cifra RSA===//

	// M�todo das divis�es
	void CifraRSA::metodoDivisoes(mpz_t n, mpz_t *p, mpz_t *q){	
	// constro� a lista de primos at� sqrt(n) 
	// [1,2,3,5,7,11,...,k] k<=sqrt(n)
	// p --- 2, ... at� descobrir o primeiro factor primo de n
	// q = n/p
}

	/*
	 * Criptoan�lise da cifra RSA usando a f�rmula geradora 6k+-1
	 * --> n: natural factor de dois primos
	 * <-- p,q: naturais, tais que n=p*q
	 */
	void CifraRSA::formulaGeradora(mpz_t n, mpz_t *p, mpz_t *q){
		
		mpz_t k, aux,sqrtAux; 
		mpz_t candidato1,candidato2;
		mpz_init_set_ui(k,1);
		mpz_mul_ui(aux,k,6);
		mpz_init_set(aux,aux+1);
		mpz_sqrt(sqrtAux,n);
		mpf_t ceilAux;
		mpf_init_set_uf(ceilAux,mpf_ceil(sqrtAux));
		while ( mpz_cmp_ui(aux,ceil(mpz_sqrt(n)))==0) {
			// gera potenciais primos atrav�s da f�rmula 6k+-1
			candidato1 = 6*k-1;
			candidato2 = 6*k+1;
			
			// verifica se cada um dos candidatos �, ou n�o primo
			if (testaPrimo(candidato1)){
				if ( n % candidato1 == 0){
					*p = candidato1;
					*q = n / candidato1; // divis�o inteira
				} // sen�o, n�o fa�o nada
			}
			if (testaPrimo(candidato2)){
				if ( n % candidato2 == 0){
					*p = candidato2;
					*q = n / candidato2; // divis�o inteira
				} // sen�o, n�o fa�o nada
			}
			k++;
		}
	}
	

	void CifraRSA::metodoFermat(long int n, long int *p, long int *q){
	// 
	
	}

//===(fim)Criptoan�lise da Cifra RSA===//

//===Cifra RSA===//

// gerarChaves
// cifrarRSA
// decifrarRSA

	int CifraRSA::cifrarRSA(int m, long int e, long int n){
		int mCifrado;
			
		mCifrado = (m^e)% n;
		
		return mCifrado;
	}
	
	int CifraRSA::decifrarRSA(int m, long int d, long int n){
		
		long int mDecifrado;		
		mDecifrado = (m^d) % n;

		return mDecifrado;		
	}

//===(fim)Cifra RSA===//






