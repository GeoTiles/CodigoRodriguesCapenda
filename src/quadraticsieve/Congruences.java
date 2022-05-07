/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package quadraticsieve;

import java.util.ArrayList;
import java.util.Comparator;
import java.math.BigInteger;

/**
 *
 * @author rodrigues.capenda
 */
public class Congruences {

    BigInteger number;
    int congruence;
    ArrayList<Factors> factors;

    public BigInteger getNumber() {
        return number;
    }

    public void setNumber(BigInteger number) {
        this.number = number;
    }

    public int getCongruence() {
        return congruence;
    }

    public void setCongruence(int congruence) {
        this.congruence = congruence;
    }

    public ArrayList<Factors> getFactors() {
        return factors;
    }

    public void setFactors(ArrayList<Factors> factors) {
        this.factors = factors;
    }

    /**
     * This method takes the list of sorted primes and write repeated as pow
     *
     * @return
     */
    public ArrayList<Factors> ordering() {
        ArrayList<Factors> aux = new ArrayList<>();// = this.factors;
        ArrayList<Factors> aux1 = new ArrayList<>();// = this.factors;
        boolean test = false;
        this.factors.forEach((e) -> {
            int count = 0;
            count = this.factors.stream().filter((p) -> (e.getBase()
                    == p.getBase())).map((_item) -> 1).reduce(count, Integer::sum);
            aux.add(new Factors(e.getBase(), count));
        });
        //removendo repetições
        aux1 = aux;
        
        
        
        return aux1;
    }

    public Congruences(ArrayList<Factors> factors) {
        this.factors = new ArrayList<>();
        ArrayList<BigInteger> toSort = new ArrayList<>() ;
        int k;
        BigInteger product = new BigInteger("1"), aux;
        int j = 0;
        while (j < 9) {
            k = (int) (Math.random() * (10));
            //this.factors.add(factors.get(k));
            toSort.add(factors.get(k).getBase());
            product = product.multiply(factors.get(k).getBase());
            j++;
        }
        
        toSort.sort(Comparator.naturalOrder());
        
        aux = toSort.get(0);
        int  cont =0;
        /**
         * Writing repetitions as pow
         */
        for(BigInteger e: toSort){
            if(aux==e){
                cont++;
            }else{
                this.factors.add(new Factors(aux, cont));
                cont = 1;
                aux=e;
            }
        }
        this.factors.add(new Factors(aux, cont));
        this.setNumber(product);
    }
}
