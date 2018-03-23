#include <iostream>

#ifndef IMPORTS
#define IMPORTS

#include "abin.h"
//#include "abinModified.h"
#include "abin_E-S.h"

#endif

#include "auxiliar.h"

using namespace std;

/*
 *void ensenar(Abin<int>::nodo nodo, Abin<int>& A) {
 *    std::cout << A.elemento(nodo) << std::endl;
 *}
 */
void ensenar() {
    std::cout << "fbkjasb fjkasbffbkjasb fjkasbf  " << std::endl;
}

int main(int argc, const char *argv[])
{
    Abin<int> Propio;
    Propio.insertarRaizB(0);
    Propio.insertarHijoIzqdoB(Propio.raizB(), 1);
    Propio.insertarHijoDrchoB(Propio.raizB(), 2);
    
    Abin<int>::nodo unoPropio = Propio.hijoIzqdoB(Propio.raizB());
    Abin<int>::nodo dosPropio = Propio.hijoDrchoB(Propio.raizB());
    
    Propio.insertarHijoIzqdoB(unoPropio, 3);
    Propio.insertarHijoDrchoB(dosPropio, 4);
    
    
    Abin<int>::nodo tresPropio = Propio.hijoIzqdoB(unoPropio);
    Abin<int>::nodo cuatroPropio = Propio.hijoDrchoB(dosPropio);
    
    Propio.insertarHijoIzqdoB(tresPropio, 5);
    Propio.insertarHijoDrchoB(cuatroPropio, 6);
    
    Abin<int> Prop;
    Prop.insertarRaizB(0);
    Prop.insertarHijoIzqdoB(Prop.raizB(), 1);
    Prop.insertarHijoDrchoB(Prop.raizB(), 2);
    
    Abin<int>::nodo uno = Prop.hijoIzqdoB(Prop.raizB());
    Abin<int>::nodo dos = Prop.hijoDrchoB(Prop.raizB());
    
    Prop.insertarHijoIzqdoB(uno, 3);
    Prop.insertarHijoDrchoB(dos, 4);
    
    
    Abin<int>::nodo tres = Prop.hijoIzqdoB(uno);
    Abin<int>::nodo cuatro = Prop.hijoDrchoB(dos);
    
    Prop.insertarHijoIzqdoB(tres, 5);
    Prop.insertarHijoDrchoB(cuatro, 6);
    
    std::cout << ((arbolesBinSimil(Propio, Prop)) ? "wiii" : ":(") << std::endl;
    
    
    //Propio.preordenAbin(Propio.raizB(), Propio, ensenar);
    Propio.preordenAbin(Propio.raizB(), Propio);
    arbolReflec(Propio);
    Propio.preordenAbin(Propio.raizB(), Propio);
    
    return 0;
}
