#include <stdio.h>
#include <stdlib.h>
#include <cstdint> 
#include <time.h>

#include <gmp.h>

#include "factorizarPrimos.hpp"

/*
 * Testa Primo - <descrição>
 * --> cand:mpz_t, <significado>
 * <-- bool, verdade se..., falso se ...
 */
bool FactorizarPrimos::testaPrimo(mpz_t cand){
  
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
 * Recebe um inteiro n e calcula os primos p e q pelo método de euclides
 */
void  FactorizarPrimos::metodoEuclides(mpz_t n){
  mpz_t min,max,product,p,q;
  mpz_inits(min,max,product,p,q,NULL);
  
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

  gmp_printf("%Zd = %Zd*%Zd\n",n,p,q);
  
}

/*
 */
bool FactorizarPrimos::metodoFermat(mpz_t n){
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

/*
 * 
 */ 
bool FactorizarPrimos::forcaBruta(mpz_t n){
	
	mpz_t p,q,sqr,r; // sqr: armazena a sqrt(n); r: restos
	bool encontrado = false;
	mpz_inits(p,q,sqr,r);
	mpz_set_ui(p,2);
	mpz_sqrt(sqr,n);
	
	while(mpz_cmp(p,sqr)<=0 && !encontrado){
		
		if(testaPrimo(p)){
			mpz_cdiv_qr(q,r,n,p);
			if(mpz_cmp_ui(r,0)==0 || testaPrimo(q)){
					return true;
				}else{
					mpz_add_ui(p,p,1);
					}
			}else{
				mpz_add_ui(p,p,1);
				}
		}
	return false;	
	}

/*
 *formulaGeradora: Calcula o  valor de P e que utilizando a fólmula p = 6k+_1
 * -> n:mpz_t, GMP int (n da chave pública)
 * <-- bool, verdade se..., falso se ...
 * Calcula P pela formula gerado
 */ 

bool FactorizarPrimos::formulaGeradora(mpz_t n){
	//ainda por revisar
	
	mpz_t p,q,sqr,r,k; // sqr: armazena a sqrt(n); r: restos
	bool encontrado = false;
	mpz_inits(p,q,sqr,r,k);
	mpz_set_ui(p,2);
	mpz_set_ui(k,0);
	
	while(mpz_cmp(p,sqr)<=0 && !encontrado){//combinou-se com o critério p<= sqrt(n)
		mpz_add_ui(k,k,1);
		if(testaPrimo(p+1)){
			mpz_cdiv_qr(q,r,n,p);
			if(mpz_cmp_ui(r,0)==0 || testaPrimo(q)){
					return true;
				}else{
					mpz_add_ui(k,k,1);
					}
			}else if(testaPrimo(p-1)){
				mpz_cdiv_qr(q,r,n,p);
				if(mpz_cmp_ui(r,0)==0 || testaPrimo(q)){
					return true;
				}else{
					mpz_add_ui(k,k,1);
					}
					
				}else{
					mpz_mul_ui(p,k,6);
				}
		}
	return false;	
	}
