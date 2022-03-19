
#ifndef FACTORIZAR
#define FACTORIZAR

#define COMPCHAVES 1500

class FactorizarPrimos {
public:
  /*
   * Métodos para Cripto análise
   * 
   */
   
  /*
   * Testa Primo - <descrição>
   * --> cand:mpz_t, <significado>
   * <-- bool, verdade se..., falso se ...
   */
  bool testaPrimo(mpz_t cand);
   
   
  /*
   * Método das divisões - <descrição>
   * --> 
   * <--
   */
  
  /*
   * Método de Euclides - <descrição>
   * -->
   * <--
   */
  void metodoEuclides(mpz_t n);
  
  /*
   * Método Fermat - <descrição>
   * -->
   * <--
   */
  bool metodoFermat(mpz_t n);

  /*
   * Força bruta
   */ 

  bool forcaBruta(mpz_t n);
  
  
  /*
   * Formula geradora: p =6k+_ 1
   */ 
  bool formulaGeradora(mpz_t n);
   
};



#endif
