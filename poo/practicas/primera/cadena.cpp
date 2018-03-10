#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "cadena.hpp"

void Cadena::initCadena(int tamanio, const char cad[]) {
    
    (tamanio < 0) ? throw TamanioInvalido () : tamanio_ = tamanio;
    
    cad_ = new char[tamanio_];
    
    for (int i = 0; i < tamanio_ && cad[i] != '\0'; i++) {
        cad_[i] = cad[i];
    }
}

Cadena::Cadena(int tamanio, const char caracter) {
    char c[tamanio];
    for (int i = 0; i < tamanio; i++) c[i] = caracter;
    
    initCadena(tamanio, c);
}

Cadena::Cadena(int tamanio, const char cad[]) {
    initCadena(tamanio, cad);
}

Cadena::Cadena(const char cad[]) {
    int tamanio = 0;
    while (cad[tamanio++] != '\0');
    initCadena(tamanio, cad);
}

Cadena::Cadena(int tamanio) {
    initCadena(tamanio);
}

std::ostream& operator <<(std::ostream& os, Cadena& c) {
    for (int i = 0; i < c.length(); i++) {
        os << c[i];
    }
    return os;
}

const char Cadena::operator [](int pos) {
    return (pos >= tamanio_) ? throw TamanioInvalido () : cad_[pos];
}

int Cadena::length() const {
    return tamanio_;
}



int main(int argc, const char *argv[])
{
    //Cadena cad(3, "abc");
    Cadena cad("jijiji");
    std::cout << cad << std::endl;
    return 0;
}
