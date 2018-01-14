#include <iostream>
#include <cstring>
#include <algorithm>
#include "listaCircular.h"

using namespace std;
void imprimir_lista(ListaCircular<int> l) {
    ListaCircular<int>::posicion p = l.inipos();
    int q = 10;
    while(p != l.fin()) {
        int number = l.elemento(p);
        cout << number << "; ";
        p = l.siguiente(p);
    }
    int number = l.elemento(p);
    cout << "            "<< number << "; ";
    p = l.siguiente(p);
    std::cout << std::endl;
    p = l.inipos();
    while(q != 0) {
        int number = l.elemento(p);
        cout << number << "; ";
        p = l.siguiente(p);
        q--;
    }
    cout << endl;
}


int num_aleat_int(int a, int b)
{
    return (a + (rand() % (b - a + 1)));
}

int main(int argc, const char *argv[])
{
    ListaCircular<int> l;
    
    srand(time(0));
    
    for(int i = 0; i < 6; i++) {
        l.insertar(num_aleat_int(1, 6), l.inipos());
    }
    imprimir_lista(l);
    
    return 0;
}
