#include <iostream>
#include <cstring>
//#include "listaDoble.h"
//#include "listaEnla.h"
#include "listaCircular.h"

using namespace std;

void imprimir_lista(ListaCircular<int> l) {
    
    
    while(l.inipos() != 0) {
        int number = l.elemento(l.inipos());
        l.eliminar(l.inipos());
        cout << number << " | ";
    }
    cout << endl;
}

int main(int argc, const char *argv[])
{
    ListaCircular<int> l;
    
    for(int i = 1; i < 10; i++) {
        l.insertar(i, l.inipos());
    }
    ListaCircular<int>::posicion p = l.inipos();
    int z = l.elemento(p);
    std::cout << z << std::endl;
    /*
     *int q = 60;
     *
     *while(q != 0) {
     *    cout << p << "; ";
     *    //p = l.elemento(l.siguiente(l.buscar(p)));
     *    p = l.elemento(l.anterior(l.buscar(p)));
     *    q--;
     *}
     */
    
    
    
    return 0;
}
