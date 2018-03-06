#ifndef IMPORTS
#define IMPORTS

#include "abin.h"
#include "abin_E-S.h"

#endif

#ifndef AUXILIAR_H
#define AUXILIAR_H

// Primero
int numNodosArbol(Abin<int> A);
int numNodosRec(Abin<int>::nodo nodo, Abin<int> A);

int numNodosArbol(Abin<int> A)
{
    return numNodosRec(A.raizB(), A);
}

int numNodosRec(Abin<int>::nodo nodo, Abin<int> A)
{
    if(nodo == Abin<int>::NODO_NULO)
        return 0;
    else
        return (1 + numNodosRec(A.hijoIzqdoB(nodo), A) + numNodosRec(A.hijoDrchoB(nodo), A));
}


// Segundo
int alturaArbol(Abin<int> A);
int alturaRec(Abin<int>::nodo nodo, Abin<int> A);

int alturaArbol(Abin<int> A)
{
    return alturaRec(A.raizB(), A);
}

int alturaRec(Abin<int>::nodo nodo, Abin<int> A)
{
    if(nodo == Abin<int>::NODO_NULO)
        return -1;
    else
    {
        int izq = 1 + alturaRec(A.hijoIzqdoB(nodo), A);
        int der = 1 + alturaRec(A.hijoDrchoB(nodo), A);
        if(izq > der)
            return izq;
        else
            return der;
    }
}

// Tercero
int profundidadNodoRec(Abin<int>::nodo nodo, Abin<int> A);
int profundidadNodoIterativo(Abin<int>::nodo nodo, Abin<int> A);

int profundidadNodoRec(Abin<int>::nodo nodo, Abin<int> A)
{
    if(nodo == Abin<int>::NODO_NULO)
        return -1;
    else
    {
        return 1 + profundidadNodoRec(A.padreB(nodo), A);
    }
}

int profundidadNodoIterativo(Abin<int>::nodo nodo, Abin<int> A) {
    int cont = 0;
    if(nodo == Abin<int>::NODO_NULO || nodo == A.raizB())
        return 0;
    else
    {
        while(nodo != Abin<int>::NODO_NULO && nodo != A.raizB()) {
            nodo = A.padreB(nodo);
            cont++;
        }
        return cont - 1;
    }
}

// Seis

// Siete













#endif
