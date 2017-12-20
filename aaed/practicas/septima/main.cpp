#include <iostream>
#include <cstring>
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
    
    for(int i = 0; i < 10; i++) {
        l.insertar(i, l.inipos());
    }
    //imprimir_lista(l);
    return 0;
}
