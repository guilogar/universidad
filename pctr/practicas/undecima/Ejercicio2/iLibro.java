import java.rmi.Remote;
import java.rmi.RemoteException;

public interface iLibro extends Remote {
    
    public String getNombre() throws RemoteException;
    public double getNumPaginas() throws RemoteException;
    public String getSiglas() throws RemoteException;
    public boolean equals(Libro l) throws RemoteException;
}
