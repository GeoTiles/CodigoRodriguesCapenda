#include <stdio.h>
#include <stdlib.h>
#include <cstdint> 
#include <time.h>

#include <gmp.h>

#include "cifraRSA.hpp"

// Gera um Número primo
char* CifraRSA::randomprime(char fmt[COMPCHAVES], unsigned long seed, unsigned long n) {
  
  FILE *fp;
  mpz_t x, m;
  gmp_randstate_t state;
  
  n=n/2;

  mpz_init(x);
  mpz_init(m);
  
  //inicilaiza a variavel state
  gmp_randinit_default(state);
  //associa o valor da semente ao state
  gmp_randseed_ui(state,seed);
  
  //gera um numero aleatorio e guarda em x que e um nr binario
  mpz_rrandomb(x, state, n);
  //identifica o proximo primo em relacao a x
  mpz_nextprime(m,x);
  //escreve numa string o valor de m na base 10
  mpz_get_str(fmt,10,m);
  
  return(fmt);
  
}

// Gera as Chaves Públicas e Privadas
void CifraRSA::gerarchaves(char str_p[COMPCHAVES], char str_q[COMPCHAVES], char str_e[COMPCHAVES], char str_d[COMPCHAVES], char str_n[COMPCHAVES]) {
  int i;
  mpz_t n, fi, e, d, p, q, aux;

  //Inicializa variaveis
  mpz_init_set_str(p,str_p,10); 
  mpz_init_set_str(q,str_q,10); 
  mpz_init(aux);
  mpz_init(n);
  mpz_init(fi);
  mpz_init_set_ui(e,2); 
  mpz_init(d);

  
  mpz_mul(n,p,q);
  mpz_sub_ui(p,p,1); 
  mpz_sub_ui(q,q,1); 
  mpz_mul(fi,p,q);
  
  mpz_gcd(aux,fi,e);
 
  
  //Determina e
  while ((mpz_cmp_ui(aux,1))!=0) {
    mpz_add_ui(e,e,1);
    mpz_gcd(aux,fi,e);	
  }

  //Determina d
  mpz_invert(d, e, fi);

  //Coloca os inteiros em Strings
  mpz_get_str(str_n,10,n);
  mpz_get_str(str_e,10,e);   
  mpz_get_str(str_d,10,d);

  //Liberta o espaço de memoria ocupado pelos inteiros
  mpz_clear(n);
  mpz_clear(fi);
  mpz_clear(e);
  mpz_clear(d);
  mpz_clear(p);
  mpz_clear(q);
  mpz_clear(aux);
  
}


void CifraRSA::geradorChaves(FILE *CPublica, FILE *CPrivada, int numbits){
  char p[COMPCHAVES], q[COMPCHAVES], e[COMPCHAVES], d[COMPCHAVES], n[COMPCHAVES]; 
  FILE *fopen();
  char *CPub, *CPriv;
  char opcao;
  unsigned long int seed, nbit = numbits;
    
  srand(time(NULL));
  seed=rand();
  //seed = 102475383874;
  randomprime(p,seed,nbit);
  seed=rand();
  //seed = 845345364638;
  randomprime(q,seed,nbit);  
  gerarchaves(p,q,e,d,n);

  //Escreve no ficheiro
      
  fprintf(CPublica, "%s\n%s ",e,n);
  fprintf(CPrivada, "%s\n%s ",d,n);
}


// função auxiliar para resolver a questao dos restos negativos.
int  CifraRSA::mod(int numero, int base) {
  int res;

  res = numero % base;
  if (res>=0) 
    return(res);
  else
    return(res+base);
}

void  CifraRSA::escreveBloco(FILE *pfC, mpz_t bloco) {

  int i;
  unsigned long t, x;
  mpz_t aux, aux2;
  
  
  mpz_init(aux);
  
  //inicializa aux2 para o inteiro com representação 11111111
  //de forma a servir de mascara
  mpz_init_set_ui(aux2,255); 
  
  
  mpz_fdiv_q_2exp(aux,bloco,0);  //Realiza a operação: >>    e retira o valor de aux
  mpz_and(aux,aux,aux2);                 //usa a mascara para tirar os ultimos 8 bits
  t=mpz_get_si(aux);                     //coloca o valor em t
  fprintf(pfC,"%c",t);
  
  
  //limpa o espaço das variaveis
  mpz_clear(aux);
  mpz_clear(aux2);
}



//funcao para encriptar
void  CifraRSA::encriptar(FILE *pfC,mpz_t bloco, mpz_t e, mpz_t n) {
  char str[1000];
  mpz_powm(bloco,bloco,e,n);
  mpz_get_str(str,10,bloco);
  
  fprintf(pfC,"%s ",str);
}



//funcao para desencriptar
void CifraRSA::desencriptar(FILE *pfC, mpz_t bloco, mpz_t d, mpz_t n) {
  mpz_powm(bloco,bloco,d,n);  
  escreveBloco(pfC,bloco);
}


void CifraRSA::tratablocoE(FILE *pfM, FILE *pfC, mpz_t e, mpz_t n){
     
  char c;
  uint64_t bloco1 = 0;
  int i = 1, j,m;
  mpz_t bloco, aux;
  
  mpz_init_set_ui(aux,0);
  mpz_init(bloco);
  
  while ((i <= 8) && (fscanf(pfM, "%c", &c)!= EOF)){
    
    m=mod(c,256);             //retira o caracter
    mpz_set_ui(aux,m);
    mpz_set_ui(bloco,bloco1);
    mpz_mul_2exp(bloco,bloco,8); //operação << em gmp
    mpz_ior(bloco,bloco,aux);
    i++;
    encriptar(pfC,bloco,e,n);
    if (i == 8) i = 0;
  }
  if (i < 8){
    j = i;
    c = 'x';
    m=mod(c,256);             
    mpz_set_ui(aux,m);
    mpz_mul_2exp(bloco,bloco,8); 
    mpz_ior(bloco,bloco,aux);
    j++;
    while(j < 8){
      c = ' ';
      m=mod(c,256);             
      mpz_set_ui(aux,m);
      mpz_mul_2exp(bloco,bloco,8); 
      mpz_ior(bloco,bloco,aux);
      j++;
    }
    encriptar(pfC,bloco,e,n);
  }  
  else {
    j = 1;
    c = 'x';
    m=mod(c,256);             
    mpz_set_ui(aux,m);
    mpz_mul_2exp(bloco,bloco,8);
    mpz_ior(bloco,bloco,aux);
    j++;
    while(j < 8){
      c = ' ';
      m=mod(c,256);             
      mpz_set_ui(aux,m);
      mpz_mul_2exp(bloco,bloco,8);
      mpz_ior(bloco,bloco,aux);
      j++;
    }
  }
  mpz_clear(bloco);
  mpz_clear(aux);
  
}

void  CifraRSA::tratablocoD(FILE *pfM, FILE *pfC,mpz_t d,mpz_t n){
     
  char c, nr[1000];
  mpz_t bloco, aux;
  
  mpz_init_set_ui(aux,0);
  mpz_init(bloco);
  
  while ((fscanf(pfM, "%s", nr)!= EOF)){
    mpz_init_set_str(bloco,nr,10);
    desencriptar(pfC,bloco,d,n);
  }
  
  mpz_clear(bloco);
  mpz_clear(aux);
}
