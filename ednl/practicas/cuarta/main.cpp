#include "auxiliar.h"

int main(int argc, const char *argv[])
{
    Abb<int> b;
    
    b.insertar(5);
    b.insertar(25);
    b.insertar(1);
    b.insertar(80);
    b.insertar(500);
    b.insertar(3);
    b.insertar(8);
    b.insertar(200);
    
    //printAbb(b);
    b.eliminarSubArbol(25);
    //printAbb(b);
    
    Abin<int> a = (Abin<int>) b;
    
    std::cout << a.elemento(a.raizB()) << std::endl;
    std::cout << a.elemento(a.hijoIzqdoB(a.raizB())) << std::endl;
    std::cout << a.elemento(a.hijoIzqdoB(a.hijoIzqdoB(a.raizB()))) << std::endl;
    return 0;
}
