#include <iostream>
#include "../grafos/grafoPMC.h"
#include "../grafos/alg_grafoPMC.h"
#include "../grafos/pilaenla.h"

template <typename tCoste> bool grafoAciclico(const GrafoP<tCoste> G) {
    
    typedef typename GrafoP<tCoste>::vertice vertice;
    const size_t n = G.numVert();
    Pila<tCoste> pila;
    bool ac = true;
    vector<tCoste> vac(n, 0);
    
    for (size_t i = 0; i < n; i++) {
        vector<bool> marcas(n, false);
        marcas[i] = true;
        for (size_t j = 0; j < n; j++) {
            if(i != j && G[i][j] != GrafoP<tCoste>::INFINITO) {
                if(!marcas[j]) {
                    pila.push(j);
                }
            }
        }
        while(!pila.vacia()) {
            vertice v = pila.tope();
            pila.pop();
            //std::cout << v << std::endl;
            if(!marcas[v]) {
                for (size_t k = 0; k < n; k++) {
                    if(i == k && G[v][k] != GrafoP<tCoste>::INFINITO) {
                        vac[i]++;
                    }
                    else if(G[v][k] != GrafoP<tCoste>::INFINITO) {
                        pila.push(i);
                        //std::cout << "v => " << v << ", i => " << i << ", k => "<< k << std::endl;
                    }
                }
            }
            /*
             *if(!marcas[v]) {
             *    marcas[v] = true;
             *    for (size_t i = 0; i < n; i++) {
             *        if(v != i && G[v][i] != GrafoP<tCoste>::INFINITO) {
             *            pila.push(i);
             *        }
             *    }
             *    std::cout << "====================" << std::endl;
             *} else if(v == i) {
             *    vac[v]++;
             *}
             */
        }
    }
    std::cout << vac << std::endl;
    return false;
}
