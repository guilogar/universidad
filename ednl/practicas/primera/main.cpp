#include <iostream>
#ifndef IMPORTS
#define IMPORTS

//#include "abin.h"

#endif

//#include "auxiliar.h"
#include "abinModified.h"
#include "abin_E-S.h"

using namespace std;

int main(int argc, const char *argv[])
{
    Abin<int> C;
    C.insertarRaizB(0);
    C.insertarHijoIzqdoB(C.raizB(), 1);
    C.insertarHijoDrchoB(C.raizB(), 2);
    
    Abin<int>::nodo uno = C.hijoIzqdoB(C.raizB());
    Abin<int>::nodo dos = C.hijoDrchoB(C.raizB());
    
    C.insertarHijoIzqdoB(dos, 3);
    C.insertarHijoDrchoB(dos, 4);
    
    Abin<int>::nodo tres = C.hijoIzqdoB(dos);
    Abin<int>::nodo cuatro = C.hijoDrchoB(dos);
    
    cout << "Y la altura es => " << C.alturaB() << endl;
    
    /*
     *Abin<int> A;
     *rellenarAbin(A, 3);
     *
     *imprimirAbin(A);
     *
     *cout << "El numero de nodos del Arbol Binario A es => " << numNodosArbol(A) << endl;
     *cout << "La altura del arbol es => " << alturaArbol(A) << endl;
     *
     *Abin<int> B;
     *B.insertarRaizB(0);
     *B.insertarHijoIzqdoB(B.raizB(), 1);
     *B.insertarHijoDrchoB(B.raizB(), 2);
     *
     *Abin<int>::nodo uno = B.hijoIzqdoB(B.raizB());
     *Abin<int>::nodo dos = B.hijoDrchoB(B.raizB());
     *
     *B.insertarHijoIzqdoB(dos, 3);
     *B.insertarHijoDrchoB(dos, 4);
     *
     *Abin<int>::nodo tres = B.hijoIzqdoB(dos);
     *Abin<int>::nodo cuatro = B.hijoDrchoB(dos);
     *
     *cout << "La profundidad del nodo \"cuatro\" con recursividad es => " << profundidadNodoRec(cuatro, B) << endl;;
     *cout << "La profundidad del nodo \"cuatro\" con iterativo es => " << profundidadNodoIterativo(cuatro, B) << endl;
     */
    
    return 0;
}
