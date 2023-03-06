package Mensaje;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.net.Socket;
import java.util.Scanner;

class JavaClientCode {
    public static void main(String[] args) {

        try {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            System.out.println("Escribe la direccion IP y el puerto");
            String ip ;
            String p;
            String ss;
            int port;

             ip = br.readLine();
             p = br.readLine();
             port = Integer.parseInt(p);
            Socket s = new Socket(ip,port);
            OutputStream os = s.getOutputStream();
            PrintWriter pw = new PrintWriter(os);
            System.out.println("Escribe un mensaje");
            Scanner in = new Scanner(System.in);
            ss = in.nextLine();
            pw.print(ss);
            pw.flush();
            pw.close();
        } catch (Exception e) {
            System.out.println("ERROR!!!");
            e.printStackTrace();
            e.getLocalizedMessage();
        }
    }
}
