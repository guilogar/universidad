#include <iostream>
#include "../grafos/grafoPMC.h"
#include "../grafos/alg_grafoPMC.h"

template <typename tCoste> matriz<tCoste> agenciaTransportes(GrafoP<tCoste> tren, GrafoP<tCoste> autobus,
                                                     typename GrafoP<tCoste>::vertice ciudadTransbordo)
{
    
    typedef typename GrafoP<tCoste>::vertice vertice;
    const size_t n = tren.numVert();
    
    GrafoP<tCoste> tarifaMinima(n, 0);
    
    vector<vertice> dijAutobus;
    vector<vertice> dijTren;
    vector<tCoste> autobusHastaTransbordo = DijkstraInv(autobus, ciudadTransbordo, dijAutobus);
    vector<tCoste> trenHastaTransbordo = DijkstraInv(tren, ciudadTransbordo, dijTren);
    vector<tCoste> autobusHastaFinal = Dijkstra(autobus, ciudadTransbordo, dijAutobus);
    vector<tCoste> trenHastaFinal = Dijkstra(tren, ciudadTransbordo, dijTren);
    
    
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            if(i == j) {
                tarifaMinima[i][j] = 0;
            }
            else {
                if(autobusHastaTransbordo[i] > trenHastaTransbordo[i]) {
                    if(autobusHastaFinal[j] > trenHastaFinal[j]) {
                        tarifaMinima[i][j] = suma(trenHastaTransbordo[i], trenHastaFinal[j]);
                    } else {
                        tarifaMinima[i][j] = suma(trenHastaTransbordo[i], autobusHastaFinal[j]);
                    }
                } else {
                    if(autobusHastaFinal[j] > trenHastaFinal[j]) {
                        tarifaMinima[i][j] = suma(autobusHastaTransbordo[i], trenHastaFinal[j]);
                    } else {
                        tarifaMinima[i][j] = suma(autobusHastaTransbordo[i], autobusHastaFinal[j]);
                    }
                }
            }
        }
    }
    
    matriz<tCoste> flo(n, 0);
    return Floyd(tarifaMinima, flo);
}
