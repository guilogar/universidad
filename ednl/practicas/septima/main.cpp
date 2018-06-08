#include <iostream>
#include "../grafos/grafoPMC.h"
#include "../grafos/alg_grafoPMC.h"
#include "../grafos/alg_grafo_E-S.cpp"
#include "./ej1.cpp"
#include "./ej2.cpp"
#include "./ej3.cpp"
#include "./ej6.cpp"
#include "./ej8.cpp"

int main(int argc, const char *argv[])
{
    // Ejercicio 1 -- Para resolver este ejercicio, aplicar o DijkstraOpuesto pasandole el origen
    // o bien, el destino.
    GrafoP<int> g(10);
    g[0] = {0, 50, 2, 60, 9, 20, 5, 2, GrafoP<int>::INFINITO, GrafoP<int>::INFINITO};
    g[1] = {5, 0, 6, 3, GrafoP<int>::INFINITO, GrafoP<int>::INFINITO, 20,
                        GrafoP<int>::INFINITO, GrafoP<int>::INFINITO, GrafoP<int>::INFINITO};
    
    g[7] = {1, 8, 1, 1, GrafoP<int>::INFINITO, GrafoP<int>::INFINITO, GrafoP<int>::INFINITO,
                        GrafoP<int>::INFINITO, GrafoP<int>::INFINITO, GrafoP<int>::INFINITO};
    
    //std::cout << g << std::endl;
    
    vector<GrafoP<int>::vertice> dij;
    vector<GrafoP<int>::vertice> dijInv;
    /*
     *std::cout << DijkstraOpuesto<int>(g, 0, dij) << std::endl;
     *std::cout << DijkstraInvOpuesto<int>(g, 0, dijInv) << std::endl;
     */
    
    //std::cout << g << std::endl;
    
    // Ejercicio 2
    
    
    // Ejercicio 3
    vector<int> cantidadAlmacenadaCiudad(10, 0);
    almacen<int>(g, {5, 80, 0, 0, 0, 0, 60, 95, 1, 8},
                 {0, 5, 2, 3, 4, 5, 8, 9, 6, 7},
                 0, 20, cantidadAlmacenadaCiudad);
    
    // Ejercicio 6
    
    return 0;
}
