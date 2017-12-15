import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.ReentrantLock;

public class Monitor {
    private int[] tenedores;
    private Condition[] arrayCondiciones;
    private ReentrantLock l;
    
    public Monitor(int n) {
        this.arrayCondiciones = new Condition[n];
        this.tenedores = new int[n];
        this.l = new ReentrantLock();
    }
    
    public void cojerTenedor(int id) {
        
    }
}
