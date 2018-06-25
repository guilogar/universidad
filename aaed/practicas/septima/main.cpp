#include <iostream>
#include <cstring>
#include <algorithm>
#include "listaCircular.h"
#include "pila.h"

using namespace std;
void imprimir_lista(ListaCircular<int> l) {
    ListaCircular<int>::posicion p = l.inipos();
    int number = 0;
    
    if(p != POS_NULA)
    {
        //p = l.anterior(p);
        number = l.elemento(p);
        cout << number << "; ";
        p = l.siguiente(p);
        
        while(p != l.inipos())
        {
            //p = l.anterior(p);
            number = l.elemento(p);
            cout << number << "; ";
            p = l.siguiente(p);
        }
    }
    cout << endl;
}


int num_aleat_int(int a, int b)
{
    return (a + (rand() % (b - a + 1)));
}

int zafo(ListaCircular<int> &lista, ListaCircular<int>::posicion p) {
    
    int number = 0;
    while(lista.siguiente(p) != p)
    {
        number = lista.elemento(p);
        std::cout << number << std::endl;
        lista.eliminar(p);
        
        if(number % 2 == 0) {
            for (int i = 0; i < number; i++) {
                p = lista.siguiente(p);
            }
        } else {
            for (int i = 0; i < number; i++) {
                p = lista.anterior(p);
            }
        }
    }
    std::cout << std::endl;
    number = lista.elemento(p);
    std::cout << number << std::endl;
    
    std::cout << "se terminooo" << std::endl;
    return number;
}

int main(int argc, const char *argv[])
{
    /*
     *ListaCircular<int> l;
     *
     *srand(time(0));
     *
     *for(int i = 1; i < 6; i++) {
     *    int num = num_aleat_int(1, 6);
     *    l.insertar(num, l.inipos());
     *    //l.insertar(i, l.inipos());
     *}
     *
     *imprimir_lista(l);
     *zafo(l, l.inipos());
     */
    //int ganador = zafo(l, l.inipos());
    //std::cout << "El ganador es => " << ganador << "." << std::endl;
    
    ListaCircular<Pila<int>> l;
    srand(time(0));
    
    for(int i = 1; i <= 10; i++) {
        
        Pila<int> p;
        p.push(num_aleat_int(1, 10));
        p.push(num_aleat_int(1, 10));
        p.push(num_aleat_int(1, 10));
        p.push(num_aleat_int(1, 10));
        l.insertar(p, l.fin());
    }
    l.~ListaCircular();
    return 0;
}
