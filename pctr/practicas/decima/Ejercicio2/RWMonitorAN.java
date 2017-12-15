import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.ReentrantLock;

import java.util.*;
import java.util.concurrent.*;

public class RWMonitorAN {
    volatile int readers = 0;
    volatile boolean writing = false;
    private Condition[] arrayCondiciones;
    private ReentrantLock l;
    
    public RWMonitorAN(int n) {
        this.l = new ReentrantLock();
        this.arrayCondiciones = new Condition[n];
        
        for (int i = 0; i < n; i++) {
            this.arrayCondiciones[i] = l.newCondition();
        }
    }
    
    public void StartRead(int id) {
        this.l.lock();
        while (writing)
            try {
               this.arrayCondiciones[id].await();
            } catch (InterruptedException e) {}
        readers = readers + 1;
        System.out.println("Lector inicia lectura...");
        notifyAll();
        this.l.unlock();
    }
    
    public void EndRead(int id) {
        this.l.lock();
        readers = readers - 1;
        if (readers == 0)
            this.arrayCondiciones[id].signalAll();
        System.out.println("Lector finaliza lectura...");
        this.l.unlock();
    }
    
    public void StartWrite(int id) {
        this.l.lock();
        while (writing || (readers != 0))
            try {
               this.arrayCondiciones[id].await();
            } catch (InterruptedException e) {}
        writing = true;
        System.out.println("Escritor inicia escritura...");
        this.l.unlock();
    }
    
    public void EndWrite(int id) {
        this.l.lock();
        writing = false;
        
        this.arrayCondiciones[id].signalAll();
        
        System.out.println("Escritor finaliza escritura...");
        this.l.unlock();
    }
}
