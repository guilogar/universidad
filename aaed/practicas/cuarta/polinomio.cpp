#include <cassert>
#include "polinomio.h"
#include <iostream>
#include <stdlib.h>

polinomio::polinomio(int grado) {
    assert(grado >= 0);
    grado_pol = grado;
    //coeficientes = (double *) malloc(sizeof(double) * grado);
    coeficientes = new double[grado];
}

void polinomio::operator =(const polinomio& p) {
    grado_pol = p.grado();
    for (int i = 0; i <= p.grado(); i++)
    {
       this->coeficiente(i, p.coeficiente(i));
    }
}

int polinomio::grado() const {
    int grad = 0;
    for (int i = 0; i <= grado_pol; i++) {
        if(coeficientes[i] != 0) {
            grad = i;
        }
    }
    return grad;
}

double polinomio::coeficiente(unsigned n) const {
    if(n > grado_pol)
        return 0;
    return coeficientes[n];
}

void polinomio::coeficiente(int n, double c) {
    assert(n <= grado_pol);
    
    coeficientes[n] = c;
}

polinomio operator +(const polinomio& p, const polinomio& q) {
    int grado_max = p.grado();
    
    if(q.grado() > grado_max) {
        grado_max = q.grado();
    }
    
    polinomio po (grado_max);
    for (int i = 0; i <= grado_max; i++)
    {
        po.coeficiente(i, p.coeficiente(i) + q.coeficiente(i));
    }
    return po;
}

polinomio operator -(const polinomio& p, const polinomio& q) {
    int grado_max = p.grado();
    
    if(q.grado() > grado_max) {
        grado_max = q.grado();
    }
    
    polinomio po (grado_max);
    for (int i = 0; i <= grado_max; i++)
    {
        po.coeficiente(i, p.coeficiente(i) - q.coeficiente(i));
    }
    return po;
}

polinomio operator *(const polinomio& p, const polinomio& q) {
    polinomio po (p.grado() + q.grado());
    
    for (int i = 0; i <= p.grado(); i++) {
        polinomio pp(p.grado() + q.grado());
        for (int j = 0; j <= q.grado(); j++) {
            pp.coeficiente(i + j, p.coeficiente(i) * q.coeficiente(j));
        }
        po = po + pp;
    }
    return po;
}
