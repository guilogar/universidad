#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <cstring>
#include <fstream>
#include <iomanip>

#include "polinomio.cpp"
using namespace std;

void print_polinomio(polinomio p)
{
    for (int i = p.grado(); i > 0; i--) {
        cout << p.coeficiente(i) << "(x^" << i << ")" << " + ";
    }
    cout << p.coeficiente(0) << "(x^" << 0 << ")" << endl;
}

int get_max_grado(polinomio c, polinomio p) {
    int grado_max = c.grado();
    if(p.grado() > grado_max)
        grado_max = p.grado();
    return grado_max;
}

int main(void)
{
    polinomio c (1);
    c.coeficiente(0, 1);
    c.coeficiente(1, 1);
    
    polinomio p (1);
    p.coeficiente(0, -1);
    p.coeficiente(1, 1);
    
    polinomio t = c * p;
    print_polinomio(t);
    p = c;
    polinomio q = c * p;
    print_polinomio(q);
    
    return 0;
}
