#include <stdio.h>
#include <stdlib.h>
#include <cstdint> 
#include <time.h>

#include <gmp.h>

#include "factorizarPrimos"

/*
 * Testa Primo - <descrição>
 * --> cand:mpz_t, <significado>
 * <-- bool, verdade se..., falso se ...
 */
bool CifraRSA::testaPrimo(mpz_t cand){
  
  mpz_t i, remain;
  mpz_inits (i, remain, NULL);
  
  for (mpz_set_ui(i,2);mpz_cmp(i,cand-1) <= 0; mpz_add_ui(i, i, 1)) {
    
    mpz_mod(remain,cand,i);
    if (mpz_cmp_ui(remain,0) == 0) {
      return false;
    }
  }
  return true;
}

/*
 */
void  CifraRSA::metodoEuclides(mpz_t n){
  mpz_t min,max,product,p,q;
  mpz_inits(min,max,product,p,q);
  
  mpz_set_ui(min,3);
  mpz_sqrt(max,n);
  mpz_set_ui(product,1);
  
  while(mpz_cmp(min,max)<0){ 
    if(testaPrimo(min)){
      mpz_mul(product,product,min);
    } else {
      mpz_add_ui(min,min,1);
    }
    mpz_add_ui(min,min,1);
  }
  mpz_gcd (p,n,product);	
  mpz_cdiv_q (q, n, p);	
  
}

/*
 */
bool CifraRSA::metodoFermat(mpz_t n){
	mpz_t aux,a,b,r,p,q;
	mpz_inits(aux,a,b,r,p,q);
	
	mpz_cdiv_r_ui(aux,n,2);
	
	if(mpz_cmp_ui(aux,0)==0)
		return false;
	else{
		
	  //Calculando a e b
		mpz_sqrt(aux,n);
		mpz_add_ui(a, aux,1);
		mpz_pow_ui(aux,a,2);
		mpz_sub(b, aux,n);
		
		/*
		 * Calculando o valor de b incrementado sucessivas vezes
		 * até obter um b quadrado perfeito
		 */
		  
		while((mpz_perfect_square_p(b)==0) && (mpz_cmp(a,n)<0)){
			mpz_add_ui(a, a,1);
			mpz_pow_ui(aux,a,2);
			mpz_sub(b, aux,n);
			}
		mpz_sqrt(b,b);		
		mpz_sub(p,a,b); // p = (a-b)
		mpz_add(q,a,b); // q = (a+b)
		
		}
		
	return true;
	}
