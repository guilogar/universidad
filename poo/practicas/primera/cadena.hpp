#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

class Cadena {
    public:
        Cadena(int tamanio, const char cad[]);
        Cadena(int tamanio, const char caracter);
        Cadena(const char cad[]);
        Cadena(int tamanio = 0);
        Cadena(const Cadena& c);
        
        int length() const;
        
        Cadena& substr(int init = 0, int end = 0);
        
        char& at(int pos);
        char& operator[](int pos);
        
        /*
         *const char at(int pos);
         *const char operator[](int pos);
         */
        
        operator const char* () const { return cad_; }
        
        Cadena& operator =(const Cadena& c);
        Cadena& operator =(const char* c);
        Cadena& operator +(const char* c);
        Cadena& operator +=(const char* c);
        
        bool operator ==(const char* c);
        bool operator !=(const char* c);
        bool operator  >(const char* c);
        bool operator  <(const char* c);
        bool operator >=(const char* c);
        bool operator <=(const char* c);
        
        ~Cadena();
        
        class TamanioInvalido { };
    private:
        int tamanio_;
        char* cad_;
};

// Constructores
Cadena::Cadena(int tamanio, const char cad[]) {
    (tamanio < 0) ? throw TamanioInvalido () : tamanio_ = tamanio;
    
    cad_ = new char[tamanio_];
    for (int i = 0; i < tamanio_ && cad[i] != '\0'; i++) { cad_[i] = cad[i]; }
}

Cadena::Cadena(int tamanio, const char caracter) {
    (tamanio < 0) ? throw TamanioInvalido () : tamanio_ = tamanio;
    
    cad_ = new char(tamanio_);
    for (int i = 0; i < tamanio_; i++) { cad_[i] = caracter; }
    cad_[tamanio_] = '\0';
}

Cadena::Cadena(const char cad[]) {
    int tamanio = 0;
    cad_ = new char(strlen(cad));
    
    while (cad[tamanio] != '\0') {
        cad_[tamanio] = cad[tamanio];
        tamanio++;
    }
    tamanio_ = tamanio;
    cad_[tamanio_] = '\0';
}

Cadena::Cadena(int tamanio) {
    (tamanio < 0) ? throw TamanioInvalido () : tamanio_ = tamanio;
    
    cad_ = new char(tamanio_);
    for (int i = 0; i < tamanio_; i++) { cad_[i] = ' '; }
}

Cadena::Cadena(const Cadena& c) {
    cad_ = new char(c.length());
    strcpy(cad_, c);
}

// Metodo observador.
int Cadena::length() const {
    return tamanio_;
}

Cadena& Cadena::substr(int init, int end) {
    if (init + end >= tamanio_) throw std::out_of_range ("Tamaño maximo excedido.");
    
    //Cadena n;
    
    for (int i = init; i < init+end; i++) {
        //n += cad_[i];
    }
    //return n;
}

char& Cadena::at(int pos) {
    if(pos >= tamanio_) throw std::out_of_range ("Tamaño maximo excedido.");
    return (*this)[pos];
}

// Sobrecarga de operadores.
char& Cadena::operator [](int pos) {
    return *(cad_ + pos);
}

Cadena& Cadena::operator =(const char* c) {
    tamanio_ = strlen(c);
    cad_ = new char(tamanio_);
    strcpy(cad_, c);
    return *this;
}

Cadena& Cadena::operator +=(const char* c) {
    char* cc = new char(strlen(cad_));
    strcpy(cc, cad_);
    
    tamanio_ = strlen(cc) + strlen(c);
    cad_ = new char(tamanio_);
    
    strcpy(cad_, cc);
    strcat(cad_, c);
    
    return *this;
}

Cadena& Cadena::operator +(const char* c) {
    Cadena cad(*this);
    return (cad += c);
}

bool Cadena::operator >(const char* c) {
    int tamanioPropio = strlen(cad_);
    int tamanioAjeno = strlen(c);
    bool mayor = true;
    
    for (int i = 0; i < tamanioPropio && i < tamanioAjeno && mayor; i++) {
        mayor = (cad_[i] == c[i]);
    }
    return (mayor) ? (tamanioPropio > tamanioAjeno) : mayor;
}

bool Cadena::operator ==(const char* c) {
    int tamanioPropio = strlen(cad_);
    int tamanioAjeno = strlen(c);
    bool igual = true;
    
    for (int i = 0; i < tamanioPropio && i < tamanioAjeno && igual; i++) {
        igual = (cad_[i] == c[i]);
    }
    return (igual) ? (tamanioPropio == tamanioAjeno) : igual;
}

bool Cadena::operator !=(const char* c) {
    return !(Cadena(cad_) == Cadena(c));
}

bool Cadena::operator >=(const char* c) {
    return (Cadena(cad_) > Cadena(c) || Cadena(cad_) == Cadena(c));
}

bool Cadena::operator <(const char* c) {
    return !(Cadena(cad_) >= Cadena(c));
}

bool Cadena::operator <=(const char* c) {
    return !(Cadena(cad_) > Cadena(c));
}

// Destructor.
Cadena::~Cadena() {
    delete cad_;
    std::cout << cad_ << std::endl;
    std::cout << strlen(cad_) << std::endl;
    //if(cad_ != nullptr) {
        //cad_ = nullptr;
    //}
}
















