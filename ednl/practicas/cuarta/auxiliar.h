//#include "../arboles/abb.h"
#include "abbModified.h"

#include <iostream>

template <typename T> void printAbb(Abb<T> A) {
    
    if(!A.vacio())
    {
        std::cout << A.elemento() << std::endl;
        printAbb(A.izqdo());
        printAbb(A.drcho());
    }
}


// Ejericio 6
typedef char T;
typedef Abb<T> Conjunto;

Conjunto DiferenciaConjuntos(Conjunto A, Conjunto B);
void DiferenciaConjuntosRec(Conjunto A, Conjunto B, Conjunto& C);
bool ElementoPerterneceConjunto(T elto, Conjunto B);
Conjunto UnionConjuntos(Conjunto A, Conjunto B);
Conjunto InterseccionConjuntos(Conjunto A, Conjunto B);

bool ElementoPerteneceConjunto(T elto, Conjunto B)
{
    if(B.vacio())
    {
        return false;
    }
    else
    {
        if(elto == B.elemento())
            return true;
        else
            return ElementoPerteneceConjunto(elto, B.izqdo()) ||
                   ElementoPerteneceConjunto(elto, B.drcho());
    }
}

Conjunto DiferenciaConjuntos(Conjunto A, Conjunto B)
{
    Conjunto C;
    DiferenciaConjuntosRec(A, B, C);
    
    return C;
}

void DiferenciaConjuntosRec(Conjunto A, Conjunto B, Conjunto& C)
{
    if(!A.vacio())
    {
        if(! ElementoPerteneceConjunto(A.elemento(), B))
            C.insertar(A.elemento());

        DiferenciaConjuntosRec(A.izqdo(), B, C);
        DiferenciaConjuntosRec(A.drcho(), B, C);
    }
}

