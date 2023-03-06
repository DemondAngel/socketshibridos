import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.net.Socket;
import java.util.Scanner;


class JavaClientCode{
    public static void main(String[] args) {

        try {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            System.out.println("Ingresa un entero");
            // String ip ;
            // String p;
            String ss;
            int port;

            // ip = br.readLine();
            // p = br.readLine();
            // port = Integer.parseInt(p);
            Socket s = new Socket("192.168.0.13", 5000);
            OutputStream os = s.getOutputStream();
            PrintWriter pw = new PrintWriter(os);

            Scanner in = new Scanner(System.in);
            ss = in.nextLine();
            pw.print(ss);
            pw.flush();
            BufferedReader entrada = new BufferedReader(new InputStreamReader(s.getInputStream()));
            String mensajeRecibido = entrada.readLine();
            System.out.println("El Servidor dice: " + mensajeRecibido);
            // InputStream is = s.getInputStream();
            pw.close();

        } catch (Exception e) {
            System.out.println("ERROR!!!");
            e.printStackTrace();
            e.getLocalizedMessage();
        }
    }
}