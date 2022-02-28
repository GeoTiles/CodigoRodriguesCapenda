
#include <gmp.h>

#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

 

bool testaPrimo(mpz_t cand) {
	mpz_t i, remain;
	mpz_inits (i, remain);
	
	for (mpz_set_ui(i,2);mpz_cmp(i,cand-1) <=0;mpz_add_ui(i, i, 1)) {
		
		mpz_mod(remain,cand,i);
		if (mpz_cmp_ui(remain,0) == 0) {
			return false;
		}
	}
    return true;
}



unsigned long int gcd(mpz_t m, mpz_t n){
	mpz_t maximo;
	mpz_init(maximo);
	
	mpz_gcd (maximo, m, n);
	return mpz_get_ui(maximo);
}

/**	
 * Determinação das Chaves Pública e Privada:
 *  -> p,q dois números primos.
 * <- (e,n) e (d,n), as chaves públicas e privadas.
 * */

void chaves(mpz_t p ,mpz_t q){
	
	bool encontrou;
	long long int j=0;
	mpz_t n, e;
	mpz_t fi,i,k,size;
	mpz_inits(n,e,fi,i,k,size);
	mpf_t d;
	
	mpz_mul(n,p,q); 
	mpz_mul(fi, p-1,q-1);
	mpz_set_ui(e,2);
	mpz_set_ui(k,0);
	mpz_set_ui(i,2);

	
	
	while(i<fi){
		if(gcd(i,fi)==1)
			mpz_add_ui(k,k,1);
			mpz_add_ui(i,i,1);	
		}
	
	std::vector<mpz_t> coprimos;
	
	
	//int coprimos[10000];
	mpz_set(size,k);
	mpz_set_ui(k, 0);
	for (mpz_set_ui(i,2);mpz_cmp(i,fi) <0;mpz_add_ui(i, i, 1)) {
	
		if(gcd(i,fi)==1){
			mpz_init(coprimos.at(j));
			mpz_set(coprimos.at(j),i);
			j++;
			//mpz_add_ui(k,k,1);
		}
	}
	
	// Escolha de um 'e' aleatorio 
	if(mpz_cmp_ui(size,1)< 0){
		mpz_t rop;
		
		gmp_randstate_t rstate;
		gmp_randinit_mt(rstate);
		mpz_urandomm(rop, rstate, size-1);

		mpz_set(e,coprimos.at(mpz_get_ui(rop)));
		} else{
				mpz_set(e,coprimos.at(0));
			}
	mpz_set_ui(k,1);
	
	// Calculo de 'd'
	encontrou = false;
	while(!encontrou){
		mpz_t aux, r;
		mpz_inits(aux,r);
		mpz_mul(aux,k,e);
		mpz_tdiv_q(r, aux, fi);
		if ( mpz_cmp_ui(r,1)==0){
			encontrou = true;
			mpf_set_z(d,k);
			}
		else
			mpz_add_ui(k,k,1);
		}
	cout << "\n Totiente(n) = " << fi << endl;
	cout<<"\n A chave pública é ("<< d << ","<< n <<")" << endl;
	cout<<"\n A chave privada é ("<< e << ","<< n <<")" << endl;
	}
	
	int main(int argc, char *argv[]){
		
		mpz_t p,q;
		mpz_inits(p,q);
		mpz_set_ui(p,atoi(argv[1]));
		mpz_set_ui(q,atoi(argv[2]));

		  if(!testaPrimo(p) || !testaPrimo(q)){
			  std::cout << "Valor de p ou q inválidos" << std::endl << "Entre com  números primos";
			return 0;
			}
			
		
		return 0;
		}


