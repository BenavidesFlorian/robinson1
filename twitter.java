package twitter;
import java.util.List;
import twitter4j.Status;
import twitter4j.TwitterException;
import twitter4j.TwitterFactory;
import twitter4j.conf.ConfigurationBuilder;
import java.io.*;
/**
 *
 * @author Florian
 */
public class Twitter {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws TwitterException {
        ConfigurationBuilder cb= new ConfigurationBuilder();
        
        cb.setDebugEnabled(true)
                .setOAuthConsumerKey("nQMYGGBYZaPqgkBmwBc7MqGdd")
                .setOAuthConsumerSecret("XM3qJKZ0xmdUewTc17ug8b72nXusBllacHbaZrh30tgyj1SO2Q")
                .setOAuthAccessToken("983293228110761984-r33OODzALSah5uEwHnM4CBcazwipYUj")
                .setOAuthAccessTokenSecret("aFNNFbpraqLgkEQeCOQlPQ8zhUWpVr2S37yRhyZM7iRv6");
        
        TwitterFactory tf = new TwitterFactory(cb.build());
        twitter4j.Twitter twitter = tf.getInstance();
        
        List<Status> status = twitter.getHomeTimeline();
        EcrireFichier ef=new EcrireFichier();
        for(Status st : status)
        {
            String s=st.getUser().getName()+"---------"+st.getText();
            System.out.println(s);
            ef.EcrireFichier(s);
            
            

            
            
            
            /*try{    
                FileOutputStream fout=new FileOutputStream("/Users/Florian/Documents/twitter/entrepot.txt");    
                String s= st.getUser().getName()+"---------"+st.getText()+"\n";    
                byte b[]=s.getBytes();//converting string into byte array    
                fout.write(b);    
                fout.close();    
                System.out.println("success...");    
            }catch(Exception e){System.out.println(e);}    */
        }
    }
            
        
        
        
        
        
        /*try{    
             FileOutputStream fout=new FileOutputStream("D:\\testout.txt");    
             String s="Welcome to javaTpoint.";    
             byte b[]=s.getBytes();//converting string into byte array    
             fout.write(b);    
             fout.close();    
             System.out.println("success...");    
            }catch(Exception e){System.out.println(e);}*/  
      
    
    
}
