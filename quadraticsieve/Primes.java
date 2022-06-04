/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package quadraticsieve;
import java.math.*;

/**
 *
 * @author rodrigues.capenda
 */
public class Primes {

    public Primes() {
    }

    /*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
     */
    /**
     *
     * @author rodrigues.capenda
     * @param n
     * @return 
     */
    public static boolean isPrime(int n) {
        int count = 0;
        for (int i = 2; i <= n; i++) {
            if (n % i == 0) {
                count++;
            }
        }
        return (count == 1);

    }
    
    public static BigInteger legendreSymbol(BigInteger n, int p) {
        n = n.pow((int)((p-1)/2));
        n = n.mod(BigInteger.valueOf(p));
        return n;
    }

}
