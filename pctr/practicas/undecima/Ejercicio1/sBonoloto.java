import java.rmi.Naming;
import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;
import java.util.Random;

public class sBonoloto extends UnicastRemoteObject implements iBonoloto {
    private int N = 6;
    private int bonoloto[] = new int[N];
    private static final long serialVersionUID = 1;
    
    public sBonoloto() throws RemoteException {
        for (int i = 0; i < this.bonoloto.length; i++) {
            this.bonoloto[i] = new Random().nextInt(49) + 1;
        }
    }
    
    public boolean comprobarApuesta(int[] apuesta) throws RemoteException {
        for (int i = 0; i < this.bonoloto.length; i++) {
            if(this.bonoloto[i] != apuesta[i])
                return false;
        }
        return true;
    }
    
    public int[] ensenioCombGanadora() {
        return this.bonoloto;
    }
    
    public static void main (String[] args) throws Exception {
        iBonoloto bonoRemoto = new sBonoloto();
        Naming.bind("ServerBonoloto", bonoRemoto);
        System.out.println("Servidor para recibir apuestas preparado.");
    }
}
