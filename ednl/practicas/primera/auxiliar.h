#ifndef IMPORTS
#define IMPORTS

#include "abin.h"
#include "abin_E-S.h"

#endif

#ifndef AUXILIAR_H
#define AUXILIAR_H

int numNodosRec(Abin<int>::nodo nodo, Abin<int> A)
{
    if(nodo == Abin<int>::NODO_NULO)
        return 0;
    else
        return (1 + numNodosRec(A.hijoIzqdoB(nodo), A) + numNodosRec(A.hijoDrchoB(nodo), A));
}

int numNodosArbol(Abin<int> A)
{
    return numNodosRec(A.raizB(), A);
}

#endif
