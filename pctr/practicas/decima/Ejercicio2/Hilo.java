import java.util.*;
import java.util.concurrent.*;

public class Hilo implements Runnable {
    private RWMonitorAN m;
    private int tipo;
    
    public Hilo(RWMonitorAN m, int tipo) {
        this.m = m;
        this.tipo = tipo;
    }
    
    public void run() {
        if(tipo % 2 == 0) {
            this.m.StartRead();
            String res = utilsFile.readOfFile(".", "holi.txt");
            this.m.EndRead();
            if(res != null) {
                System.out.println("El valor de la lectura es => " + res);
            }
        } else {
            this.m.StartWrite();
            utilsFile.writeInFile(".", "holi.txt", "Oh my gad...\n");
            this.m.EndWrite();
        }
    }
}
