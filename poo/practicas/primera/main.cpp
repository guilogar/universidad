#include "cadena.hpp"
#include "fecha.hpp"

using namespace std;

/*
 *void funtoguapa(Cadena& c) {
 *    //c.~Cadena();
 *}
 */

int main(int argc, const char *argv[]) {
    
    const Cadena cad("abcd");
    Cadena cad1(3, "abc");
    Cadena cad2 = "jijiji";
    
    //std::cout << ((cad != cad1) ? "Holiii" : "adiuuuuu") << std::endl;
    //cad[0] = 'b'; // Da error, como deberia de haberlo.
    
    std::cout << cad[0] << std::endl;
    
    return 0;
}
