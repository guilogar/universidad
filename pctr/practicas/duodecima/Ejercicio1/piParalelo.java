import java.util.*;
import java.util.concurrent.*;

public class piParalelo implements Runnable {
    private int puntos;
    public static double aciertos = 0;
    
    public piParalelo(int puntos) {
        this.puntos = puntos;
    }
    
    public void masPuntos(int puntos) {
        this.puntos += puntos;
    }
    
    public void reset() {
        this.puntos = 0;
    }
    
    public synchronized void run() {
        for (int i = 0; i < this.puntos; i++) {
            double x = Math.random() * 2 - 1;
            double y = Math.random() * 2 - 1;
            double z = x*x + y*y;
            
            if(z <= 1) {
                aciertos++;
            }
        }
    }
    
    public static double getPi(double aciertos, int puntos) {
        return (aciertos * 4) / puntos;
    }
    
    public static void main (String[] args) throws Exception {
        ExecutorService pool = Executors.newCachedThreadPool();
        int N = 10000;
        pool.execute(new piParalelo(N / 4));
        pool.execute(new piParalelo(N / 4));
        pool.execute(new piParalelo(N / 4));
        pool.execute(new piParalelo(N / 4));
        
        pool.shutdown();
        pool.awaitTermination(1L, TimeUnit.DAYS);
        
        System.out.println(getPi(aciertos, N));
    }
}

