#ifndef IMPORTS
#define IMPORTS

#include "abin.h"
#include "abin_E-S.h"

#endif
#include <iostream>
#include "auxiliar.h"

using namespace std;

int main(int argc, const char *argv[])
{
    Abin<int> A;
    rellenarAbin(A, 3);
    
    imprimirAbin(A);
    
    cout << "El numero de nodos del Arbol Binario A es => " << numNodosArbol(A) << endl;
    
    
    return 0;
}
