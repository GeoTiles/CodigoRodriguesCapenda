
#include <gmp.h>
#include <vector>
#include "cifraRSA.hpp"
#include <iostream>

// ===//Funções Auxiliares (private)//===
 

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
	// lista de primos até n (inclusivé)
	
	mpz_t i;
	std::vector<mpz_t> candidatos;
	//mpz_t candidatos[comprimentoVector];
	contaPrimos = 0;
	
	for(mpz_init_set(i,0); mpz_cmp_ui(i,comprimentoVector)<0; mpz_add_ui(i,i,1))
		mpz_set(candidatos.at(mpz_get_ui(i)),i+2);
	
	/*  
	 *  inicializar, candidatos[2,3,4,5,6,7,...,n]
	 *  i = 0;
	 *  enquanto (i <= n-2)
	 *    // o primeiro elemento de candidatos (não nulo) é primo 
	 *    enquanto candidatos[i] é zero 
	 *         i++;
	 *    fimenquanto
	 *    primos[contaPrimos] <- candidatos[i];
	 *    contaPrimos++;
	 *    // aplicar o crivo candidatos[i] ---> i=0 ---> 2
	 *       ---> candidatos[0,3,0,5,0,7,...,n] ---> coloca a zero todos os múltiplos de 2...
	 * 
	 * 
	 */
}

// ===//(fim) Funções Auxiliares (private)//===

//===Criptoanálise da Cifra RSA===//

	// Método das divisões
	void CifraRSA::metodoDivisoes(mpz_t n, mpz_t *p, mpz_t *q){	
	// constroí a lista de primos até sqrt(n) 
	// [1,2,3,5,7,11,...,k] k<=sqrt(n)
	// p --- 2, ... até descobrir o primeiro factor primo de n
	// q = n/p
}

	/*
	 * Criptoanálise da cifra RSA usando a fórmula geradora 6k+-1
	 * --> n: natural factor de dois primos
	 * <-- p,q: naturais, tais que n=p*q
	 */
	void CifraRSA::formulaGeradora(mpz_t n, mpz_t p, mpz_t q){
		
		mpf_t sqrtAux;
		mpz_t k,aux,ceilZ,candidato1,candidato2, rop;
		mpz_inits(candidato1,candidato2,rop);
		
		mpz_init_set_ui(k,1);
		mpz_mul_ui(aux,k,6);
		mpz_init_set(aux,aux+1);
		mpf_sqrt_ui(sqrtAux,mpz_get_ui(n));
		mpf_ceil(sqrtAux,sqrtAux);
		
		//mpf_init_set_uf(ceilAux,mpf_ceil(sqrtAux));
		mpz_init_set_ui(ceilZ,mpf_get_ui(sqrtAux));
		
		while (mpz_cmp(aux,ceilZ)==0) {
			// gera potenciais primos através da fórmula 6k+-1
			mpz_mul_ui (k, k, 6);
			mpz_set(candidato1,k-1);
			mpz_set(candidato2,k+1);

			
			// verifica se cada um dos candidatos é, ou não primo
			if (testaPrimo(candidato1)){
				mpz_cdiv_q(rop, n, candidato1);
				if (mpz_cmp_ui(rop, 0)){
					mpz_set(p,candidato1);
					mpz_div(q,n,candidato1); // divisão inteira
				} // senão, não faço nada
			}
			if (testaPrimo(candidato2)){
				mpz_cdiv_q(rop, n, candidato2);
				if (mpz_cmp_ui(rop, 0)){
					mpz_set(p,candidato2);
					mpz_div(q,n,candidato2); // divisão inteira
				} // senão, não faço nada
			}
			mpz_add_ui(k,k,1);
		}
	}
	

	void CifraRSA::metodoFermat(mpz_t n, mpz_t *p, mpz_t *q){
	// 
	
	}

//===(fim)Criptoanálise da Cifra RSA===//

//===Cifra RSA===//

// gerarChaves
// cifrarRSA
// decifrarRSA

	mpz_t CifraRSA::cifrarRSA(mpz_t m, mpz_t e, mpz_t n){
		mpz_t mCifrado;
		
		mpz_init(aux);
		mpz_powm(mCifrado, m, e, n);
		
		return mCifrado;
	}

	
	int CifraRSA::decifrarRSA(int m, long int d, long int n){
		mpz_t aux;
		long int mDecifrado;
		
		mpz_init(aux);
		mpz_powm(aux, m, d, n);
		
		mDecifrado = mpz_get_ui(aux);

		return mDecifrado;		
	}

//===(fim)Cifra RSA===//






