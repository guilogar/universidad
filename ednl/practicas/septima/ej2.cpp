#include <iostream>
#include "../grafos/grafoPMC.h"
#include "../grafos/alg_grafoPMC.h"

template <typename tCoste> double laberinto(int n, vector<vector<bool>> paredes,
                                            typename GrafoP<tCoste>::vertice entrada,
                                            typename GrafoP<tCoste>::vertice salida)
{
    GrafoP<tCoste> G(n*n);
    typedef typename GrafoP<tCoste>::vertice vertice;
    const size_t n_vertices = G.numVert();
    
    for (size_t i = 0; i < n_vertices; i++) {
        for (size_t j = 0; j < n_vertices; j++) {
            //if(i == j) G[i][j] == GrafoP<tCoste>::INFINITO;
            if(paredes[i][j]) {
                G[i][j] = GrafoP<tCoste>::INFINITO;
                //G[j][i] = GrafoP<tCoste>::INFINITO;
            }
        }
    }
    
    for (size_t i = 0; i < n_vertices; i++) {
        
    }
}
