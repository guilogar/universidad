import java.util.*;
import java.lang.*;

public class algEisenbergMcGuire implements Runnable {
    public static int turno = 0;
    public static final int N = 5;
    public static int numProcesos = 1;
    private int index;
    private Estados t;
    
    public algEisenbergMcGuire(int index) {
        this.index = index;
        this.t = Estados.IDLE;
    }
    
    public void run() {
        while(true) {
            do {
                this.t = Estados.WAITING;
                System.out.println("index actual => " + index);
                System.out.println("turno actual =>" + turno);
                while(this.index != turno) {
                    //System.out.println("Turno => " + turno);
                }
                this.t = Estados.ACTIVE;
            } while(this.t == Estados.IDLE);
            
            // BEGIN CRITICAL SECTION
            numProcesos++;
            numProcesos--;
            System.out.println("Estamos en el hilo => " + this.index + " y parece que se mantiene la seguridad de la concurrencia porque hay " + numProcesos + " proceso en la sección crítica.");
            // END CRITICAL SECTION
            
            turno = ++turno % N;
            t = Estados.IDLE;
        }
    }
    
    public static void main (String[] args) {
        for (int i = 0; i < N; i++)
            new Thread(new algEisenbergMcGuire(i)).start();
    }
}
