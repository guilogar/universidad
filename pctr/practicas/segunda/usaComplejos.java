import java.lang.*;
import java.util.*;

public class usaComplejos {
    
    public static void main (String[] args) {
        
        int op = 0;
        Scanner sc = new Scanner(System.in);
        
        Complejos c1 = new Complejos();
        Complejos c2 = new Complejos();
        
        do {
            //System.out.println("Menu de opciones");
            //System.out.println("================");
            //
            //System.out.println("1º) Suma.");
            //System.out.println("2º) Resta.");
            //System.out.println("3º) Producto.");
            //System.out.println("4º) División.");
            //System.out.println("5º) Salir.");
            //System.out.println();
            //
            //System.out.print("¿Qué desea hacer? => ");
            
            try {
                op = sc.nextInt();
                
                /*
                 *if(op == 5) {
                 *    System.out.println("Bye.");
                 *    return;
                 *}
                 *
                 *Scanner s = new Scanner(System.in);
                 *
                 *System.out.print("Dime la parte real del primer complejo => ");
                 *System.out.println(s.nextInt());
                 *
                 *System.out.print("Dime la parte compleja del primer complejo => ");
                 *c1.setCompleja(s.nextDouble());
                 *
                 *System.out.print("Dime la parte real del segundo complejo => ");
                 *c2.setReal(s.nextDouble());
                 *
                 *System.out.print("Dime la parte compleja del segundo complejo => ");
                 *c2.setCompleja(s.nextDouble());
                 */
            } catch(Exception e) {
                System.err.println("Error a la hora de escojer la opción. Vuelva a intentarlo.");
                continue;
            }
            
            switch (op) {
                
            }
            System.out.println("Bye");
        } while(op != 5);
        
        
    }
}
