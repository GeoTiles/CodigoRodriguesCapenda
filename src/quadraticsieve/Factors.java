/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package quadraticsieve;

import java.math.BigInteger;

/**
 *
 * @author rodrigues.capenda
 */
public class Factors {
    private BigInteger base;
    private int exponent;

    public BigInteger getBase() {
        return base;
    }

    public void setBase(BigInteger base) {
        this.base =base;
    }

    public int getExponent() {
        return exponent;
    }

    public void setExponent(int exponent) {
        this.exponent = exponent;
    }

    public Factors(BigInteger base, int exponent) {
        this.base = base;
        this.exponent = exponent;
    }

    public Factors() {
    }
    
    
}
