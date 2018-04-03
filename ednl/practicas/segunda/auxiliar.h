#include <iostream>
#include "Agen.hpp"
#include "abin.h"

struct nod {
    double operando;
    char operador;
    nod(char oper = 'n', double operand = 0.0): operando(operand), operador(oper) {}
};

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
Abin<int>& arbolReflecRec(Abin<int>::nodo nodoA, Abin<int> A, Abin<int>::nodo nodoB, Abin<int> &B);

Abin<int> arbolReflec(Abin<int> A)
{
    if(!A.arbolVacioB())
    {
        Abin<int> B;
        B.insertarRaizB(A.elemento(A.raizB()));
        return arbolReflecRec(A.raizB(), A, B.raizB(), B);
    }
    else
    {
        return A;
    }
}

Abin<int>& arbolReflecRec(Abin<int>::nodo nodoA, Abin<int> A, Abin<int>::nodo nodoB, Abin<int> &B)
{
    if(nodoA != Abin<int>::NODO_NULO)
    {
        Abin<int>::nodo izqA = A.hijoIzqdoB(nodoA);
        Abin<int>::nodo derA = A.hijoDrchoB(nodoA);
        
        if(izqA != Abin<int>::NODO_NULO)
        {
            B.insertarHijoDrchoB(nodoB, A.elemento(izqA));
        }
        if(derA != Abin<int>::NODO_NULO)
        {
            B.insertarHijoIzqdoB(nodoB, A.elemento(derA));
        }
        Abin<int>::nodo izqB = B.hijoIzqdoB(nodoB);
        Abin<int>::nodo derB = B.hijoDrchoB(nodoB);
        
        B = arbolReflecRec(izqA, A, derB, B);
        B = arbolReflecRec(derA, A, izqB, B);
    }
    return B;
}

// Ejercicio 3
double resArbolAritmetico(Abin<nod> A);
double resArbolAritmeticoRec(Abin<nod>::nodo nodo, Abin<nod> A);

double resArbolAritmetico(Abin<nod> A)
{
    return resArbolAritmeticoRec(A.raizB(), A);
}

double resArbolAritmeticoRec(Abin<nod>::nodo nodo, Abin<nod> A)
{
    if(nodo != Abin<nod>::NODO_NULO)
    {
        char operador = A.elemento(nodo).operador;
        
        if(operador == 'n')
        {
            return A.elemento(nodo).operando;
        }
        else
        {
            switch (operador)
            {
                case '+':
                    return resArbolAritmeticoRec(A.hijoIzqdoB(nodo), A) +
                           resArbolAritmeticoRec(A.hijoDrchoB(nodo), A);
                    break;
                case 'x':
                case '*':
                    return resArbolAritmeticoRec(A.hijoIzqdoB(nodo), A) *
                           resArbolAritmeticoRec(A.hijoDrchoB(nodo), A);
                    break;
                case '-':
                    return resArbolAritmeticoRec(A.hijoIzqdoB(nodo), A) -
                           resArbolAritmeticoRec(A.hijoDrchoB(nodo), A);
                    break;
                case '/':
                    return resArbolAritmeticoRec(A.hijoIzqdoB(nodo), A) /
                           resArbolAritmeticoRec(A.hijoDrchoB(nodo), A);
                    break;
                default:
                    return 0.0;
            }
        }
    }
    else
    {
        return 0.0;
    }
}

// Ejercicio 4


// Ejercicio nodos nostalgicos
int profundidadNodoRec(Abin<int>::nodo, Abin<int>);

int numSucesoresNodoRec(Abin<int>::nodo, Abin<int>);
int numSucesoresNodo(Abin<int>::nodo, Abin<int>);

bool nodoNostalgico(Abin<int>::nodo, Abin<int>);

int numNodosNostalgicosArbolRec(Abin<int>::nodo nodo, Abin<int> A);
int numNodosNostalgicosArbol(Abin<int> A);

int profundidadNodoRec(Abin<int>::nodo nodo, Abin<int> A)
{
    if( nodo == Abin<int>::NODO_NULO )
        return -1;
    else
        return 1 + profundidadNodoRec(A.padreB(nodo), A);
}

int numSucesoresNodoRec(Abin<int>::nodo nodo, Abin<int> A)
{
    if(nodo == Abin<int>::NODO_NULO)
    {
        return 0;
    }
    else
    {
        return 1 + numSucesoresNodoRec(A.hijoIzqdoB(nodo), A) + numSucesoresNodoRec(A.hijoDrchoB(nodo), A);
    }
}

int numSucesoresNodo(Abin<int>::nodo nodo, Abin<int> A)
{
    return numSucesoresNodoRec(A.hijoIzqdoB(nodo), A) + numSucesoresNodoRec(A.hijoDrchoB(nodo), A);
}

bool nodoNostalgico(Abin<int>::nodo nodo, Abin<int> A)
{
    return (profundidadNodoRec(nodo, A) > numSucesoresNodo(nodo, A));
}

int numNodosNostalgicosArbolRec(Abin<int>::nodo nodo, Abin<int> A)
{
    if(nodo == Abin<int>::NODO_NULO)
        return 0;
    else
    {
        int nos = (nodoNostalgico(nodo, A)) ? 1 : 0;
        return nos + numNodosNostalgicosArbolRec(A.hijoIzqdoB(nodo), A) + numNodosNostalgicosArbolRec(A.hijoDrchoB(nodo), A);
    }
}

int numNodosNostalgicosArbol(Abin<int> A)
{
    return numNodosNostalgicosArbolRec(A.raizB(), A);
}
