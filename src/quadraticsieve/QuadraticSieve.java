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

    private static ArrayList<Integer> primes;
    private static ArrayList<Congruences> frs = new ArrayList<>();

    /**
     *
     * @param index
     * @return
     */
    static ArrayList<Factors> factorBase(int index, BigInteger n) {

        ArrayList<Factors> factorBase = new ArrayList<>();
        int primeAux;
        BigInteger legendre;

        for (int i = 0; i <= index; i++) {
            primeAux = primes.get(i);
            legendre = Primes.legendreSymbol(n, primeAux);
            if (legendre.compareTo(BigInteger.valueOf(1)) == 0) {
                factorBase.add(new Factors(BigInteger.valueOf(primeAux), 0));
            }

        }

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

        ArrayList<Integer> primeBase = MyFiles.getPrimes();
        try {

            while (!primeBase.contains(returnning)) {
                returnning = (int) (Math.random() * ((int) (Math.floor(sqrt(n))) - 61 + 1) + 61);
            }
        } catch (Exception e) {
        }
        return primeBase.indexOf(returnning);

    }

    //IMplementar o escalonamento em Z2
    static void escalonamento(int[][] matrix) {
        //Sellecting pivot row
        int pivot = 0;
        for (int i = 1; i < matrix.length; i++) {
            if (matrix[i][0] == 1) {
                pivot = i;
            }
        }

        for (int i = pivot; i < matrix.length; i++) {
            for (int j = 0; j < matrix[i].length; j++) {
            }
        }
    }

    public static boolean checkF(ArrayList<Factors> base, BigInteger fr, BigInteger r) {
        boolean test = false;
        int i, exp = 0;
        BigInteger frAux = fr;

        BigInteger baseAux;
        ArrayList<Factors> congruenceFactors = new ArrayList<>();

        for (i = 0; i < base.size(); i++) {
            baseAux = base.get(i).getBase();
            test = fr.mod(baseAux).compareTo(BigInteger.valueOf(0)) == 0;
            while (test) {
                exp++;
                fr = fr.divide(baseAux);
                test = fr.mod(baseAux).compareTo(BigInteger.valueOf(0)) == 0;
            }
            //test = test || (exp % 2 == 0);
            congruenceFactors.add(new Factors(baseAux, exp));
            exp = 0;
        }
        if (fr.compareTo(BigInteger.valueOf(1)) == 0) {
            frs.add(new Congruences(r, frAux, congruenceFactors));
            return true;
        } else {
            return false;
        }

    }

    static int f(BigInteger sqrtN, BigInteger n, ArrayList<Factors> base) {
        BigInteger fr, r;
        int lines = 0;
        for (int i = 1; i <= 200; i++) {
            r = sqrtN.add(BigInteger.valueOf(i));
            fr = r.pow(2).subtract(n);
            if (checkF(base, fr, r)) {
                lines++;
            }
        }
        return 0;
    }

    static void printMatrix(int[][] matrix) {
        int i, j;
        for (i = 0; i < matrix.length; i++) {
            for (j = 0; j < matrix[i].length; j++) {
                System.out.print(matrix[i][j]);
            }
            System.out.println("");
        }
    }

    static int[][] generateIdentity(int n) {
        int[][] matrix = new int[n][n];

        for (int i = 0; i < n; i++) {
            matrix[i][i] = 1;
        }
        return matrix;
    }

    static int nullVector(int[][] matrix) {
        int v = 0;
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[i].length; j++) {

                v += matrix[i][j];
            }

            if (v == 0) {
                return i;
            } else {
                v = 0;
            }
        }
        return -1;
    }

    static int[] gaussMethod(int[][] matrix) {
        int i, j, k, l = 0, p, q, nullLine, row = matrix.length, columns = matrix[0].length;
        int[][] identity = generateIdentity(matrix.length);
        int[][] matrixCopy = new int[row][columns];

        //Criando uma copia da Matrix
        for (i = 0; i < matrix.length; i++) {
            for (j = 0; j < matrix[i].length; j++) {
                matrixCopy[i][j] = matrix[i][j];
            }
        }

        //Escalonando
        for (i = 0; i < matrix.length; i++) {
            k = i + 1;
            while (k < matrix.length) {
                for (j = 0; j < matrix[i].length; j++) {

                    matrix[k][j] = (matrix[k][j] + matrix[i][j]) % 2;
                    //    identity[k][j] = (identity[k][j] + identity[i][j]) % 2;
                }
                k++;
            }

            nullLine = nullVector(matrix);

            if (nullLine != -1) {

                return identity[nullLine];
            }
            //Recebendo a copia armazenada

            for (p = 0; p < matrix.length; p++) {
                for (q = 0; q < matrix[i].length; q++) {
                    matrix[p][q] = matrixCopy[p][q];
                }
            }
        }

        return null;
    }

    static int gaussElimination(int[][] matrix) {

        int i, j, k, l = 0, nullLine;
        int[][] identity = generateIdentity(matrix.length);
        for (i = 0; i < matrix.length; i++) {
            k = i + 1;
            System.out.println("Etapa:  " + k);

            while (k < matrix.length) {
                for (j = l; j < matrix[i].length; j++) {
                    if (matrix[i][l] % 2 == 1 && matrix[k][l] % 2 == 1) {
                        matrix[k][j] = (matrix[k][j] + matrix[i][j]) % 2;
                        identity[k][j] = (identity[k][j] + identity[i][j]) % 2;
                    } else if (matrix[i][l] % 2 == 0 && matrix[k][l] % 2 == 1) {
                        matrix[k][j] = (2 * matrix[k][j] + matrix[i][j]) % 2;
                        identity[k][j] = (2 * identity[k][j] + identity[i][j]) % 2;

                    } else if (matrix[i][l] % 2 == 1 && matrix[k][l] % 2 == 0) {
                        matrix[k][j] = (matrix[k][j] + 2 * matrix[i][j]) % 2;
                        identity[k][j] = (identity[k][j] + 2 * identity[i][j]) % 2;
                    } else {
                        matrix[k][j] = (matrix[k][j] + matrix[i][j]) % 2;
                        identity[k][j] = (identity[k][j] + identity[i][j]) % 2;
                    }
                }
                k++;
            }
            if (l + 1 < matrix[i].length) {
                l++;
            }
            nullLine = nullVector(matrix);
            if (nullLine != -1) {
                System.out.println("1:   " + frs.get(i).getR());
                System.out.println("2:   " + frs.get(nullLine).getR());
                printMatrix(identity);
                return nullLine;
            }

        }
        return -1;
    }

    static int[] buildMatrix(ArrayList<Factors> base) {
        //      ArrayList<Factors> factorsAux = new ArrayList<>();
        frs.remove(0);
        int rows = frs.size(), columns = base.size(), foccusLine;
        int[][] matrix = new int[rows][columns];
        int i, j;

        for (i = 0; i < frs.size(); i++) {
            for (j = 0; j < frs.get(i).getFactors().size(); j++) {
                matrix[i][j] = frs.get(i).getFactors().get(j).getExponent() % 2;
            }
        }
        return gaussMethod(matrix);

    }

    static void factotizarN(BigInteger target) {

        MyFiles.setPrimes();
        QuadraticSieve.primes = MyFiles.getPrimes();

        MyFiles.setPublickeys("chavesPub8a64_RC.csv");
        //ArrayList<String> publickeys = MyFiles.getPublickeys();
        ArrayList<String> publickeys = MyFiles.getPublickeys();

        int smoothIndex = 40;
        int[] nullLine;
        BigInteger a, b, y = new BigInteger("1"), x = new BigInteger("1");

        BigInteger n = target;
        //Passo 1
        ArrayList<Factors> base = factorBase(smoothIndex, n);
        // Passo 2
        BigInteger sqrtN = n.sqrt();

        //Passo 3
        f(sqrtN, n, base);
        // Passo 

        nullLine = buildMatrix(base);

        while (nullLine == null) {
            smoothIndex++;
            base = factorBase(smoothIndex, n);
            // Passo 2
            sqrtN = n.sqrt();

            //Passo 3
            f(sqrtN, n, base);
            // Passo 
            nullLine = buildMatrix(base);

        }
        if (nullLine != null) {
            for (int i = 0; i < nullLine.length; i++) {
                if (nullLine[i] != 0) {
                    x = x.multiply(frs.get(i).getR());
                    y = y.multiply(frs.get(i).getFr());
                }
            }
            x = x.mod(n);
            y = y.sqrt().mod(n);

            System.out.print("n = " + n);
            //  System.out.println("x=  " + x);

            //  System.out.println("y=  " + y);
            a = x.subtract(y);
            // System.out.println("x-y=  " + a);
            a = a.gcd(n);
            System.out.print("  a=  " + a);

            b = x.add(y);
            b = b.gcd(n);

            System.out.print("  b = " + b);
        }
    }

    public static void main(String[] args) {
        /* 
            Leitura dos ficheiros 
            primes: ficheiros com numeros primos previamente gerados
            publickeys: ficheiro com as chaves publicas
         */

        MyFiles.setPublickeys("chavesPub8a64_RC.csv");
        ArrayList<String> publickeys = MyFiles.getPublickeys();
        factotizarN(new BigInteger("264978904569647"));
        System.out.println("");
    }

}
