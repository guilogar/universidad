import java.util.*;
import java.util.concurrent.*;

public class ProcesoB implements Runnable {
    private Buffer f;
    private int tamTrasp;
    
    public ProcesoB(Buffer f, Buffer f2, int tamTrasp) {
        this.f = f;
        this.tamTrasp = tamTrasp;
    }
    
    public void run() {
        double[][] matriz = f.extraer();
        double[][] matrizTrasp = new double[this.tamTrasp][tamTrasp];
        
        for (int i = 0; i < this.tamTrasp; i++) {
            for (int j = 0; j < this.tamTrasp; j++) {
                matrizTrasp[i][j] = matriz[j][i];
            }
        }
        f.insertar(matriz);
    }
}
