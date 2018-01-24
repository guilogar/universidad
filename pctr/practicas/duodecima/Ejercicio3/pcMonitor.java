import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class pcMonitor {
    private int numSlots = 0;
    private int[] items = null;
    private int cont = 0;
    int putptr, takeptr;
    
    final Lock cerrojo = new ReentrantLock();
    final Condition productores  = cerrojo.newCondition();
    final Condition consumidores  = cerrojo.newCondition();
    
    public pcMonitor(int numSlots) {
        this.numSlots = numSlots;
        this.items = new int[numSlots];
    }
    
    public void put(int x) {
        cerrojo.lock();
        try {
            while (cont == items.length) {
                this.productores.await();
            }
            items[putptr] = x;
            
            if (++putptr == items.length)
                putptr = 0;
            
            ++cont;
            this.consumidores.signalAll();
        } catch (Exception ex) {}
        cerrojo.unlock();
    }
    
    public int take() {
        cerrojo.lock();
        try {
            while (cont == 0) {
                this.consumidores.await();
            }
            
            int x = items[takeptr];
            
            if (++takeptr == items.length)
                takeptr = 0;
            
            --cont;
            this.productores.signalAll();
            return x;
        } catch (Exception ex) {}
        cerrojo.unlock();
        return -1;
    }
}
