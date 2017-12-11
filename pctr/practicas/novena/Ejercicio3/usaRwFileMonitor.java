import java.util.*;
import java.util.concurrent.*;

public class usaRwFileMonitor {
    
    public static void main (String[] args) {
        ExecutorService pool = Executors.newCachedThreadPool();
    }
}

class Hilo implements Runnable {
    private RWFileMonitor m;
    private int tipo;
    
    public Hilo(RWFileMonitor m, int tipo) {
        this.m = m;
        this.tipo = tipo;
    }
    
    public void run() {
        if(tipo % 2 == 0) {
            
        } else {
            
        }
    }
}
