/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package twitter;

import java.io.*
import java.util.*;
import twitter4j.*;
/**
 *
 * 
 */
public class Indexation {
    public static void main(String[] args) {  
     try{    
            FileInputStream source=new FileInputStream("entree.txt");    
            int i=fin.read();  
            //System.out.print((char)i);    
            source.close();   
            
            FileWriter result=new FileWriter("sortie.txt");    
            result.write(i);    
            result.close();    
            
          }catch(Exception e){System.out.println(e);}    
         }

      System.out.println("Success...");    
   }
}
