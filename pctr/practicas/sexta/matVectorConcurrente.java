import java.lang.*;
import java.util.*;
import java.util.concurrent.*;

public class matVectorConcurrente implements Runnable {
    
    private static int matriz[][];
    private static int vector[][];
    private static int res[][];
    private static int tareas = Runtime.getRuntime().availableProcessors();
    private int limiteInferior = 0;
    private int limiteSuperior = 0;
    
    public matVectorConcurrente(int linf, int lsup) {
        this.limiteInferior = linf;
        this.limiteSuperior = lsup;
    }
    
    public void run() {
        for (int i = this.limiteInferior; i <= this.limiteSuperior; i++) {
            res[i][0] = 0;
            for (int j = 0; j < matriz[i].length; j++) {
                res[i][0] += (matriz[i][j] * vector[j][0]);
            }
        }
    }
    
    public static void printVector(int vector[]) {
        for (int i = 0; i < vector.length; i++) {
            System.out.print("| " + vector[i] + " |");
        }
    }
    
    public static void printMatriz(int matriz[][]) {
        for (int i = 0; i < matriz.length; i++) {
            printVector(matriz[i]);
            System.out.println();
        }
    }
    
    public static int[][] mulMatrizVector(int matriz[][]) throws InterruptedException {
        ExecutorService pool = Executors.newCachedThreadPool();
        int linf = 0;
        int lsup = 0;
        for (int i = 0; i < tareas && i < matriz.length; i++) {
            lsup = linf + (matriz.length / tareas);
            if(matriz.length >= tareas) {
                lsup -= 1;
            }
            pool.execute(new matVectorConcurrente(linf, lsup));
            linf = lsup + 1;
        }
        if(matriz.length > tareas && matriz.length % tareas != 0) {
            lsup = linf + (matriz.length % tareas) - 1;
            pool.execute(new matVectorConcurrente(linf, lsup));
        }
        pool.shutdown();
        pool.awaitTermination(1L, TimeUnit.DAYS);
        return res;
    }
    
    public static void main (String[] args) throws InterruptedException {
        int maxNum = 2;
        
        Scanner c = new Scanner(System.in);
        
        System.out.print("Introduzca el numero de filas de la matriz => ");
        int numFilas = c.nextInt();
        System.out.println();
        
        System.out.print("Introduzca el numero de columnas de la matriz => ");
        int numColumnas = c.nextInt();
        System.out.println();
        
        System.out.print("Introduzca el tamaño del vector => ");
        int tamVector = c.nextInt();
        System.out.println();
        
        if(numColumnas != tamVector) {
            System.out.println("No se puede realizar la multiplicación, ya que el numero " +
                               "de columnas y de filas de la matriz y el vector son distintas.");
            return;
        }
        matriz = new int[numFilas][numColumnas];
        vector = new int[tamVector][1];
        res = new int[numFilas][1];
        
        for (int i = 0; i < numFilas; i++) {
            for (int j = 0; j < numColumnas; j++) {
                matriz[i][j] = new Random().nextInt(maxNum);
            }
        }
        for (int i = 0; i < tamVector; i++) {
            vector[i][0] = new Random().nextInt(maxNum);
        }
        System.out.println("Matriz");
        printMatriz(matriz);
        System.out.println("------");
        System.out.println("Vector");
        printMatriz(vector);
        System.out.println("------");
        System.out.println();
        
        long start = System.currentTimeMillis();
        System.out.println("Res");
        printMatriz(mulMatrizVector(matriz));
        System.out.println("---");
        long end = System.currentTimeMillis();
        //utilsFile.writeInFile("info", "matVectorConcurrente.txt", tamVector + " " + (end-start) + "\n");
    }
}
