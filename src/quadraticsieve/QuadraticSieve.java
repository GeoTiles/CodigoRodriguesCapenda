/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package quadraticsieve;

import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import static java.lang.Math.sqrt;
import java.util.ArrayList;
import java.util.Scanner;
import java.math.*;

/**
 *
 * @author rodrigues.capenda
 */
public class QuadraticSieve {

    private static final ArrayList<Integer> primes = new ArrayList<>();
    private static final Primes myprime = new Primes();

    public static ArrayList<Integer> getPrimes() {

        return primes;
    }

    /**
     *
     */
    public static void setPrimes() {
        try {
            File myObj = new File("baseprimes.txt");
            if (!myObj.createNewFile()) {
                //FileReader myReader = new FileReader("primes.txt");
                Scanner myReader = new Scanner(new FileReader("baseprimes.txt"));
                String lastLine = "";
                //Moving to the file last line
                while (myReader.hasNextLine()) {
                    lastLine = myReader.nextLine().trim();
                    QuadraticSieve.primes.add(Integer.parseInt(lastLine));
                }

            }
        } catch (IOException e) {
            System.out.println("An error occurred.");
        }
    }

    /**
     *
     * @param index
     * @return
     */
    static ArrayList<Factors> factorBase(int index) {

        ArrayList<Factors> factorBase = new ArrayList<>();

        for (int i = 0; i < 10; i++) {

            factorBase.add(new Factors(BigInteger.valueOf(primes.get((int) 
                    (Math.random() * ((int) (index) - 61 + 1) + 61))), 0));

            index--;
        }

        //  crongruences();
        return factorBase;
    }

    /**
     *
     * @param n
     * @return
     */
    @SuppressWarnings("empty-statement")
    static int smothBase(int n) {
        /*
        entry: n (number to be factorized)
        This function picks randonly a prime number betwen 61 and sqrt(n)
        output: A list of prime numbers to be used to composit conguences
         */
        int returnning = (int) (Math.random() * ((int) (Math.floor(Math.sqrt(n))) - 61 + 1) + 61);

        ArrayList<Integer> primeBase = getPrimes();
        try {

            while (!primeBase.contains(returnning)) {
                returnning = (int) (Math.random() * ((int) (Math.floor(sqrt(n))) - 61 + 1) + 61);
            }
        } catch (Exception e) {
        }
        return primeBase.indexOf(returnning);

    }

    public static void main(String[] args) {
        // TODO code application logic here
        setPrimes();
        int smoothIndex;
        BigInteger n = new BigInteger("58268954234564");
        smoothIndex = smothBase(15145125);

          System.out.println("Index Smooth B:  " + smoothIndex);
          System.out.println("Number Smooth B:  " + primes.get(smoothIndex));
        ArrayList<Factors> base = factorBase(smoothIndex);
        ArrayList<Congruences> congruences = new ArrayList<>();
        
        Congruences congruence = new Congruences(base);
        System.out.println("Producto:  " +  congruence.getNumber());

        //Congruences congruence = new Congruences(base);
       
        
    }

}
