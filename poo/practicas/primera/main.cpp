#include "fecha.hpp"
#include "cadena.hpp"

using namespace std;

int main(int argc, const char *argv[]) {
    
    const Cadena cad("abcd");
    Cadena cad1(3, "abc");
    Cadena cad2 = "jijiji";
    
    
    std::cout << cad1 << std::endl;
    cad1.at(1) = 'p';
    std::cout << cad1 << std::endl;
    
    std::cout << cad1 << std::endl;
    cad1[0] = 'r';
    std::cout << cad1 << std::endl;
    
    cad1 += "123456789 asd khbsaf f ";
    std::cout << cad1 << std::endl;
    std::cout << "=========================0" << std::endl;
    /*
     *cad[0] = 'o';
     *cad.at(0) = 'o';
     */
    
    return 0;
}
