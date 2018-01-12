#include <iostream>
#include <cstring>
//#include "listaDoble.h"
//#include "listaEnla.h"
#include "listaCircular.h"

using namespace std;

/*
 *void imprimir_lista(ListaCircular<int> l) {
 *    
 *    while(l.inipos() != 0) {
 *        int number = l.elemento(l.inipos());
 *        l.eliminar(l.inipos());
 *        cout << number << " | ";
 *    }
 *    cout << endl;
 *}
 */

int main(int argc, const char *argv[])
{
    Lista<int> l;
    
    for(int i = 0; i < 10; i++) {
        l.insertar(i, l.primera());
        //l.insertar(i, l.inipos());
    }
    
    int p = l.elemento(l.inipos());
    
    while(p != 0) {
        cout << p << "; ";
        p = l.elemento(l.siguiente(l.buscar(p)));
    }
    p = l.elemento(l.fin());
    cout << endl;
    cout << p << "; ";
    return 0;
}
