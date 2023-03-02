import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.net.Socket;
import java.util.Scanner;


class JavaClientCode
{
    public static void main(String[] args) {

    try
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
       System.out.println("Enter ip and port : ");
       //String ip ;
       //String p;
       String ss;
       int port;

       //ip = br.readLine();
       //p = br.readLine();
       //port = Integer.parseInt(p);
       Socket s = new Socket("192.168.100.13",5000);
       OutputStream os = s.getOutputStream();
       PrintWriter pw = new PrintWriter(os);

       Scanner in = new Scanner(System.in);
       ss = in.nextLine();      
       pw.print(s);
       pw.flush();
       pw.close();
    }
    catch(Exception e){
        System.out.println("ERROR!!!");
        e.printStackTrace();
        e.getLocalizedMessage();
    }
   }
}