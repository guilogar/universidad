#include "auxiliar.h"
#include "abin_E-S.h"

using namespace std;

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
    
    /*
     *std::cout << ((arbolesBinSimil(Propio, Prop)) ? "wiii" : ":(") << std::endl;
     *
     *Propio.preordenAbin(Propio.raizB(), Propio);
     *Abin<int> P = arbolReflec(Propio);
     *std::cout << "======================" << std::endl;
     *P.preordenAbin(P.raizB(), P);
     */
    
    /*
     *Abin<nod> ArbolAritmetico;
     *ArbolAritmetico.insertarRaizB('x');
     *ArbolAritmetico.insertarHijoIzqdoB(ArbolAritmetico.raizB(), {'n', 1});
     *ArbolAritmetico.insertarHijoDrchoB(ArbolAritmetico.raizB(), '*');
     *
     *Abin<nod>::nodo suma = ArbolAritmetico.hijoDrchoB(ArbolAritmetico.raizB());
     *
     *ArbolAritmetico.insertarHijoIzqdoB(suma, {'n', 90});
     *ArbolAritmetico.insertarHijoDrchoB(suma, {'n', 9});
     *
     *double resultado = resArbolAritmetico(ArbolAritmetico);
     *std::cout << "Resultado => " << resultado << std::endl;
     */
    //std::cout << numSucesoresNodo(Propio.raizB(), Propio) << std::endl;
    std::cout << numNodosNostalgicosArbol(Propio) << std::endl;
    
    return 0;
}
