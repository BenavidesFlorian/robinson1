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
        
        
        try{
                // Create file 
                FileWriter fstream = new FileWriter("/Users/Florian/Documents/twitter/entrepot.txt");
                BufferedWriter out = new BufferedWriter(fstream);
                for(Status st : status)
                {
                    String s=st.getUser().getName()+"---------"+st.getText();
                    System.out.println(s);
                    out.write(s);
                    out.newLine();
                }
                //Close the output stream
                out.close();
            }catch (Exception e){//Catch exception if any
            System.err.println("Error: " + e.getMessage());
            }
        }
    }
