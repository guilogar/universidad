#include <iostream>
#include <cstring>
#include <algorithm>
#include "listaCircular.h"

using namespace std;
void imprimir_lista(ListaCircular<int> l) {
    ListaCircular<int>::posicion p = l.inipos();
    while(p != l.fin()) {
        int number = l.elemento(p);
        cout << number << "; ";
        p = l.siguiente(p);
    }
    int number = l.elemento(p);
    cout << number << "; ";
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
    
    for(int i = 0; i < 5; i++) {
        int num = num_aleat_int(1, 6);
        l.insertar(num, l.inipos());
        std::cout << num << std::endl;
    }
    //imprimir_lista(l);
    
    ListaCircular<int>::posicion p = l.inipos();
    while(p != l.fin()) {
        int number = l.elemento(p);
        cout << number << "; ";
        p = l.siguiente(p);
    }
    cout << endl;
    
    return 0;
}
