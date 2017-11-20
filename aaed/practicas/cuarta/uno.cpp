#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <cstring>
#include <fstream>
#include <iomanip>

#include "polinom.cpp"
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

polinomio sum_resta_polinomio(polinomio c, polinomio p, int op)
{
    int grado_max = get_max_grado(c, p);
    polinomio po (grado_max);
    for (int i = 0; i <= grado_max; i++)
    {
        if(op == 0)
            po.coeficiente(i, c.coeficiente(i) + p.coeficiente(i));
        else
            po.coeficiente(i, c.coeficiente(i) - p.coeficiente(i));
    }
    return po;
}

polinomio mult_polinomio(polinomio c, polinomio p)
{
    polinomio po (c.grado() + p.grado());
    
    for (int i = 0; i <= c.grado(); i++) {
        polinomio pp(c.grado() + p.grado());
        for (int j = 0; j <= p.grado(); j++) {
            pp.coeficiente(i + j, c.coeficiente(i) * p.coeficiente(j));
        }
        po = sum_resta_polinomio(po, pp, 0);
    }
    return po;
}

polinomio deriv_polinomio(polinomio c) {
    int grado = c.grado() - 1;
    
    if(grado < 1)
        grado = 0;
    
    polinomio po (grado);
    for (int i = c.grado(); i > 0; i--) {
        po.coeficiente(i-1, c.coeficiente(i) * i);
    }
    return po;
}

int main(void)
{
    polinomio c (3);
    c.coeficiente(0, 1);
    c.coeficiente(1, 5);
    c.coeficiente(2, 3);
    
    polinomio p (1);
    p.coeficiente(0, -1);
    p.coeficiente(1, 1);
    
    //print_polinomio(sum_resta_polinomio(c, p, 0));
    print_polinomio(deriv_polinomio(c));
    
    return 0;
}
