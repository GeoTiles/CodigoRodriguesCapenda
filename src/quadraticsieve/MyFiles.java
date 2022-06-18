/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package quadraticsieve;

import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Scanner;

/**
 *
 * @author rcapenda
 */
public class MyFiles {
    
   private static ArrayList<Integer> primesNumbers = new ArrayList<>();
   private static ArrayList<String> publickeys = new ArrayList<>();
    
    public static ArrayList<Integer> getPrimes() {

        return primesNumbers;
    }

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
                    primesNumbers.add(Integer.parseInt(lastLine));
                }

            }
        } catch (IOException e) {
            System.out.println("An error occurred.");
        }
    }

    public static ArrayList<String> getPublickeys() {
        return publickeys;
    }

    public static void setPublickeys(String fileName) {
        int i =0;
        try {

            File myObj = new File(fileName);
            if (!myObj.createNewFile()) {
                //FileReader myReader = new FileReader("primes.txt");
                Scanner myReader = new Scanner(new FileReader(fileName));
                String lastLine;
                //Moving to the file last line
                try {
                    while (myReader.hasNextLine()) {
                        lastLine = myReader.nextLine().trim();
                        publickeys.add(lastLine);
                        i++;
                    }

                } catch (NullPointerException e) {
                    System.out.println("Erro na linha  " + i );
                }
                
            }
        } catch (IOException e) {
            System.out.println("An error occurred.");
        }
    }
    
  
    
}
