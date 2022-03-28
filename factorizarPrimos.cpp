#include <stdio.h>
#include <stdlib.h>
#include <cstdint> 
#include <time.h>

#include <gmp.h>

#include "factorizarPrimos.hpp"



void FactorizarPrimos::forcaBruta(const mpz_t n, mpz_t p, mpz_t q){
  mpz_t res;

  mpz_init(res);
  mpz_init(p);
  mpz_init(q);

  mpz_set_ui(q, 2);
  mpz_tdiv_r(res,n,q);

  while (mpz_cmp_ui(res,0)!=0){
    mpz_nextprime(q,q);
    mpz_tdiv_r(res,n,q);}
  mpz_tdiv_q(p,n,q);
  gmp_printf("Os fatores primos de %Zd sao %Zd e %Zd\n",n,p,q);

  mpz_clear(res);
  mpz_clear(p);
  mpz_clear(q);
}

// Método de Fermat
void FactorizarPrimos::metodoFermat(const mpz_t n, mpz_t p, mpz_t q){
  mpz_t a;

  mpz_init(a);
  mpz_init(q);
  mpz_init(p);
  
  mpz_sqrt(a,n);
  mpz_add_ui(a,a,1);
  mpz_mul(q,a,a);
  mpz_sub(q,q,n);
  while(mpz_perfect_square_p(q)==0){
    mpz_add_ui(a,a,1);
    mpz_mul(q,a,a);
    mpz_sub(q,q,n);
  }
  
  mpz_sqrt(q,q);
  mpz_add(p,a,q);
  mpz_sub(q,a,q);
  
  gmp_printf("Os fatores primos de %Zd sao %Zd e %Zd\n", n, p,q); 

  mpz_clear(a);
  mpz_clear(p);
  mpz_clear(q);
}

// Fórmula geradora
void FactorizarPrimos::formulaGeradora(const mpz_t n, mpz_t p, mpz_t q){
  mpz_t res1, res2, aux;

  mpz_init (p);
  mpz_init (q);
  mpz_init(aux);
  mpz_init(res1);
  mpz_init(res2);

  mpz_set_ui(p,1);
  mpz_tdiv_r_ui(res1,n,2);
  if(mpz_cmp_ui(res1,0)==0){
    mpz_tdiv_q_ui(q,n,2);
    gmp_printf("Os fatores primos de %Zd sao 2 e %Zd\n",n, q);
  }
  
  mpz_tdiv_r_ui(res2,n,3);
  if(mpz_cmp_ui(res2,0)==0){
    mpz_tdiv_q_ui(q,n,3);
    gmp_printf("Os fatores primos de %Zd sao 3 e %Zd\n",n, q);
  }
  
  mpz_mul(aux,res1,res2);
  if(mpz_cmp_ui(aux,0)!=0){
    while(mpz_cmp_ui(aux,0)!=0){
      mpz_add_ui(p,p,4);
      mpz_tdiv_r(res1,n,p);
      mpz_add_ui(p,p,2);
      mpz_tdiv_r(res2,n, p);
      mpz_mul(aux,res1,res2);
    }
    if(mpz_cmp_ui(res1,0)==0){
      mpz_sub_ui(p,p,2);
      mpz_tdiv_q(q,n,p);
      gmp_printf("Os fatores primos de %Zd sao %Zd e %Zd\n",n, p, q);
    }
    else {
      mpz_tdiv_q(q,n,p);
      gmp_printf("Os fatores primos de %Zd sao %Zd e %Zd\n",n, p, q);
    }
  }

  mpz_clear(p);
  mpz_clear(q);
  mpz_clear(res1);
  mpz_clear(res2);
  mpz_clear(aux);
}

// Método de Euclides
void FactorizarPrimos::metodoEuclides(const mpz_t n, mpz_t p, mpz_t q){		
  mpz_t paux, p_2, res; 	

  mpz_init(paux);
  mpz_init (p_2);	 
  mpz_init (p);	 
  mpz_init (q);	
  mpz_init(res);	
  mpz_set_ui(p_2, 2);
  mpz_set_ui(q,1);	

  while(mpz_cmp_ui(q,1)==0){
    mpz_set(p, p_2);
    mpz_nextprime(p_2,p_2);
    mpz_mul(paux,p,p_2);
    mpz_nextprime(p_2,p_2);
    mpz_mul(paux,paux,p_2);		
    mpz_nextprime(p_2,p_2);
    mpz_mul(paux,paux,p_2);
    mpz_nextprime(p_2,p_2);
    mpz_mul(paux,paux,p_2);		
    mpz_nextprime(p_2,p_2);
    mpz_mul(paux,paux,p_2);	
    mpz_gcd(q, paux, n);	
    
  }

  if(mpz_cmp(q,n)!=0) {
      mpz_tdiv_q(p,n,q);
      gmp_printf("Os fatores primos de %Zd sao %Zd e %Zd\n",n, p, q);}
  else {
    mpz_tdiv_r(res,n, p);
    while(mpz_cmp_ui(res,0)!=0){
      mpz_nextprime(p,p);
      mpz_tdiv_r(res,n, p);		     		
    }
    mpz_tdiv_q(q,n,p);
    gmp_printf("Os fatores primos de %Zd sao %Zd e %Zd\n",n, p, q);
  }

  mpz_clear(paux);
  mpz_clear(p);
  mpz_clear(p_2);
  mpz_clear(q);
  mpz_clear(res);
}	
