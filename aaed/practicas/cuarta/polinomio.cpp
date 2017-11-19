#include <cassert>
#include "polinomio.h"
#include <iostream>

polinomio::polinomio(int grado) {
    assert(grado >= 0);
    grado_pol = grado;
    *coeficientes = *new double[grado_pol];
}

/*
 *polinomio::polinomio(const polinomio& p) {
 *    for (int i = 0; i <= p.grado(); i++)
 *    {
 *       this->coeficiente(i, p.coeficiente(i));
 *    }
 *}
 */

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
    assert(n <= grado_pol);
    
    return coeficientes[n];
}

void polinomio::coeficiente(unsigned n, double c) {
    assert(n <= grado_pol);
    std::cout << coeficientes[0];

    coeficientes[n] = c;
}

polinomio operator +(const polinomio& p, const polinomio& q) {
    int grado_max = p.grado();
    
    if(q.grado() > grado_max) {
        grado_max = q.grado();
    }
    
    std::cout << "grado_max" << grado_max << std::endl;
    polinomio po (grado_max);
    for (int i = 0; i <= grado_max; i++)
    {
        po.coeficiente(i, p.coeficiente(i) + q.coeficiente(i));
        std::cout << "c(i)" << po.coeficiente(i) << std::endl;
    }
    return po;
}

/*
 *polinomio polinomio::operator -(const polinomio& p) {
 *    int grado_max = this->grado();
 *    
 *    if(p.grado() > grado_max) {
 *        grado_max = p.grado();
 *    }
 *    
 *    polinomio po (grado_max);
 *    for (int i = 0; i <= grado_max; i++)
 *    {
 *        po.coeficiente(i, this->coeficiente(i) - p.coeficiente(i));
 *    }
 *    return po;
 *}
 *
 *polinomio polinomio::operator *(const polinomio& p) {
 *    polinomio po (this->grado() + p.grado());
 *    
 *    for (int i = 0; i <= this->grado(); i++) {
 *        polinomio pp(this->grado() + p.grado());
 *        for (int j = 0; j <= p.grado(); j++) {
 *            pp.coeficiente(i + j, this->coeficiente(i) * p.coeficiente(j));
 *        }
 *        //po = po + pp;
 *    }
 *    return po;
 *}
 */
