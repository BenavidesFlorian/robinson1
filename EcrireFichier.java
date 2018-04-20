package twitter;

import java.io.File;
import java.io.FileOutputStream;
import java.io.FileWriter;
import java.io.IOException;

/**
 *
 * @author Florian
 */
public class EcrireFichier {
    void EcrireFichier(String s){
        /*try {
                FileWriter fw = new FileWriter(new File("/Users/Florian/Documents/twitter/entrepot.txt"));
                fw.write(String.format(s));
                fw.write(System.lineSeparator());
                fw.close();
            }catch(IOException ex){ex.printStackTrace();}*/
        try{    
                FileOutputStream fout=new FileOutputStream("/Users/Florian/Documents/twitter/entrepot.txt");       
                byte b[]=s.getBytes();//converting string into byte array    
                fout.write(b);    
                fout.close();    
                System.out.println("success...");    
            }catch(Exception e){System.out.println(e);}
    }
}
