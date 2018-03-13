
#include "fecha.hpp"

int main(int argc, const char *argv[])
{
    try {
        Fecha hoy {}, copia_hoy{hoy};	// Predeterminado, de copia
        Fecha mi_nacimiento{29, 12, 1958};
        Fecha mannana = ++hoy;	// pre-incremento
        Fecha ayer = --copia_hoy;	// pre-decremento
        
        // Nota: Hay que hacerlo en sentencias separadas.
        std::cout << "Hoy es " << --hoy;	// Conversión a const char*
        std::cout << ", mañana será " << mannana;
        std::cout << " y ayer fue " << ayer << std::endl;
        
        hoy += 7;			// Prueba de suma con asignación
        std::cout << "Dentro de una semana será: " << hoy << std::endl;
        hoy += 365 * 3;
        std::cout << "Dentro de 3 años y 1 semana será: " << hoy << std::endl;
        hoy -= 365 * 3 + 7;
        std::cout << "Volvemos a hoy: " << hoy << std::endl;
    } catch(Fecha::Invalida e) {
        std::cout << e.por_que() << std::endl;
    }

    return 0;
}
