#include <iostream>
#include "Agen.hpp"
#include "abin.h"

// Ejercicio 1
bool arbolesBinSimil(Abin<int> A, Abin<int> B);
bool arbolesBinSimilRec(Abin<int>::nodo nodoA, Abin<int> A, Abin<int>::nodo nodoB, Abin<int> B);

bool arbolesBinSimil(Abin<int> A, Abin<int> B)
{
    return (A.arbolVacioB() && B.arbolVacioB()) ? true : arbolesBinSimilRec(A.raizB(), A, B.raizB(), B);
}

bool arbolesBinSimilRec(Abin<int>::nodo nodoA, Abin<int> A, Abin<int>::nodo nodoB, Abin<int> B)
{
    
    if(nodoA != Abin<int>::NODO_NULO && nodoB != Abin<int>::NODO_NULO)
    {
        bool igualIzq = arbolesBinSimilRec(A.hijoIzqdoB(nodoA), A, B.hijoIzqdoB(nodoB), B);
        bool igualDer = arbolesBinSimilRec(A.hijoDrchoB(nodoA), A, B.hijoDrchoB(nodoB), B);
        return igualIzq && igualDer;
    } else
        return (nodoA == Abin<int>::NODO_NULO && nodoB == Abin<int>::NODO_NULO);
}

// Ejercicio 2
Abin<int> arbolReflec(Abin<int> A);
Abin<int> arbolReflecRec(Abin<int>::nodo nodo, Abin<int> A);

Abin<int> arbolReflec(Abin<int> A) {
    Abin<int> B;
    return arbolReflecRec(A.raizB(), A, B.raizB(), B);
}

Abin<int> arbolReflecRec(Abin<int>::nodo nodoA, Abin<int> A, Abin<int>::nodo nodoB, Abin<int> B) {
    if(nodoA != Abin<int>::NODO_NULO) {
        B.elemento(nodoB) = A.elemento(nodoA);
        
        /*
         *A = arbolReflecRec(A.hijoIzqdoB(nodo), A);
         *A = arbolReflecRec(A.hijoDrchoB(nodo), A);
         *
         *Abin<int>::nodo izq = A.hijoIzqdoB(nodo);
         *Abin<int>::nodo der = A.hijoDrchoB(nodo);
         *
         *if(izq != Abin<int>::NODO_NULO) {
         *    A.eliminarHijoIzqdoB(nodo);
         *    if(der != Abin<int>::NODO_NULO)
         *        A.insertarHijoIzqdoB(der, A.elemento(der));
         *}
         *if(der != Abin<int>::NODO_NULO) {
         *    A.eliminarHijoDrchoB(nodo);
         *    if(izq != Abin<int>::NODO_NULO)
         *        A.insertarHijoDrchoB(izq, A.elemento(izq));
         *}
         *
         */
    }
    return A;
}
