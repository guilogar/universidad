#include <iostream>
#include <cstring>
#include <algorithm>
#include "listaCircular.h"

using namespace std;
void imprimir_lista(ListaCircular<int> l) {
    ListaCircular<int>::posicion p = l.inipos();
    int number = 0;
    
    if(p != POS_NULA)
    {
        p = l.anterior(p);
        number = l.elemento(p);
        cout << number << "; ";
        //p = l.siguiente(p);
        
        while(p != l.inipos())
        {
            p = l.anterior(p);
            number = l.elemento(p);
            cout << number << "; ";
            //p = l.siguiente(p);
        }
    }
    cout << endl;
}


int num_aleat_int(int a, int b)
{
    return (a + (rand() % (b - a + 1)));
}

int zafo(ListaCircular<int> lista, ListaCircular<int>::posicion p) {
    
    ListaCircular<int>::posicion aux = p;
    
    while(lista.inipos() != POS_NULA)
    {
        int number = lista.elemento(aux);
        std::cout << lista.elemento(aux) << std::endl;
        
        if(number % 2 == 0) {
            for (int i = 0; i < number; i++) {
                aux = lista.siguiente(aux);
            }
        } else {
            for (int i = 0; i < number; i++) {
                aux = lista.anterior(aux);
            }
        }
        lista.eliminar(aux);
    }
    std::cout << "se terminoooo" << std::endl;
    return lista.elemento(lista.inipos());
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
    
    imprimir_lista(l);
    zafo(l, l.inipos());
    
    /*
     *ListaCircular<int>::posicion p = l.inipos();
     *while(p != l.fin()) {
     *    int number = l.elemento(p);
     *    cout << number << "; ";
     *    p = l.siguiente(p);
     *}
     *cout << endl;
     */
    
    return 0;
}
