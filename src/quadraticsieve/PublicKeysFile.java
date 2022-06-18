/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package quadraticsieve;

import java.math.BigInteger;

/**
 *
 * @author rcapenda
 */
public class PublicKeysFile {
    private int numberOfBits;
    private BigInteger e;
    private BigInteger n;
    private BigInteger p;
    private BigInteger q;

    public int getNumberOfBits() {
        return numberOfBits;
    }

    public void setNumberOfBits(int numberOfBits) {
        this.numberOfBits = numberOfBits;
    }

    public BigInteger getE() {
        return e;
    }

    public void setE(BigInteger e) {
        this.e = e;
    }

    public BigInteger getN() {
        return n;
    }

    public void setN(BigInteger n) {
        this.n = n;
    }

    public BigInteger getP() {
        return p;
    }

    public void setP(BigInteger p) {
        this.p = p;
    }

    public BigInteger getQ() {
        return q;
    }

    public void setQ(BigInteger q) {
        this.q = q;
    }

    public PublicKeysFile(int numberOfBits, BigInteger e, BigInteger n, BigInteger p, BigInteger q) {
        this.numberOfBits = numberOfBits;
        this.e = e;
        this.n = n;
        this.p = p;
        this.q = q;
    }
    
    
    
}
