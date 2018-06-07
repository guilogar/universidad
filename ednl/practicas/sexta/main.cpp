#include <iostream>
#include "../grafos/grafoPMC.h"
#include "../grafos/alg_grafoPMC.h"
#include "../grafos/alg_grafo_E-S.cpp"
#include "./ej1.cpp"
#include "./ej2.cpp"

int main(int argc, const char *argv[])
{
    GrafoP<int> g(10);
    g[0] = {0, 50, 2, 60, 9, 20, 5, 2, GrafoP<int>::INFINITO, GrafoP<int>::INFINITO};
    g[1] = {5, 0, 6, 3, GrafoP<int>::INFINITO, GrafoP<int>::INFINITO, GrafoP<int>::INFINITO,
                        GrafoP<int>::INFINITO, GrafoP<int>::INFINITO, GrafoP<int>::INFINITO};
    
    g[7] = {1, 8, 1, 1, GrafoP<int>::INFINITO, GrafoP<int>::INFINITO, GrafoP<int>::INFINITO,
                        GrafoP<int>::INFINITO, GrafoP<int>::INFINITO, GrafoP<int>::INFINITO};
    
    std::cout << g << std::endl;
    
    vector<GrafoP<int>::vertice> dij;
    vector<GrafoP<int>::vertice> dijInv;
    /*
     *std::cout << Dijkstra<int>(g, 0, dij) << std::endl;
     *std::cout << DijkstraInv<int>(g, 3, dijInv) << std::endl;
     */
    
    std::cout << g << std::endl;
    //std::cout << dij << std::endl;
    //std::cout << dijInv << std::endl;
    
    pseudoCentroGrafo(g);
    
    return 0;
}
