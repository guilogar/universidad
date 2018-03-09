#include <iostream>
#include <sstream>
#include <regex>

#include "fecha.hpp"

const std::string Fecha::diasSemana[7] = {"Domingo", "Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado"};
const std::string Fecha::meses[12] = {"Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre"};

void Fecha::initFecha(int dia = 0, int mes = 0, int anio = 0) {
    std::time_t calendario = std::time(0);
    std::tm* tiempoDescompuesto = std::localtime(&calendario);
    
    (dia == 0) ? dia_ = tiempoDescompuesto->tm_mday : dia_ = dia;
    (mes == 0) ? mes_ = ++tiempoDescompuesto->tm_mon : mes_ = mes;
    (anio == 0) ? anio_ = tiempoDescompuesto->tm_year + 1900 : anio_ = anio;
    
    if(anio_ < 0 || mes_ < 0 || dia_ < 0)
        throw Invalida ("Día o mes o año totalmente incorrectos.");
    
    if(dia_ > 31 || mes_ > 12)
        throw Invalida ("Día o mes totalmente incorrectos.");
    
    if(mes_ == 2 && dia_ > 29)
        throw Invalida ("Día imposible para el mes actual.");
    
    if(mes_ == 2 && dia_ > 28 && anio_ % 4 == 0 && (anio_ % 400 == 0 || anio_ % 100 != 0))
        throw Invalida ("Día imposible para el mes actual.");
    
    if(anio_ < AnnoMinimo || anio_ > AnnoMaximo) {
        std::stringstream ss;
        ss << "El año no puede ser menor de " << AnnoMinimo << " y mayor de " << AnnoMaximo << ".";
        throw Invalida (ss.str());
    }
}

Fecha::Fecha(int dia, int mes, int anio) {
    initFecha(dia, mes, anio);
}

Fecha::Fecha(int dia, int mes) {
    initFecha(dia, mes);
}

Fecha::Fecha(int dia) {
    initFecha(dia);
}

Fecha::Fecha() {
    initFecha();
}

Fecha::Fecha(const Fecha& f) {
    initFecha(f.dia(), f.mes(), f.anio());
}

Fecha::Fecha(const std::string& s) {
    if ( std::regex_match(s, std::regex("[0-9]{1,2}[/][0-9]{1,2}[/][0-9]{1,4}")) ) {
        int cont = 0, index = 0;
        int fecha[3];
        
        std::regex rgx("[0-9]{1,4}");
        std::smatch match;
        
        while(std::regex_search(s.begin()+cont, s.end(), match, rgx) && index < 3) {
            cont += 3;
            fecha[index++] = stoi(match[0]);
        }
        initFecha(fecha[0], fecha[1], fecha[2]);
    } else {
        initFecha(-1, -1, -1);
    }
}

int Fecha::dia() const {
    return dia_;
}
int Fecha::diaSemana() const {
    struct tm hoy = obtenerStructTime();
    time_t time = mktime(&hoy);
    std::tm* tiempoDescompuesto = std::localtime(&time);
    
    return tiempoDescompuesto->tm_wday;
}
int Fecha::mes() const {
    return mes_;
}
int Fecha::anio() const {
    return anio_;
}

std::ostream& operator <<(std::ostream& os, const Fecha& f) {
    //os << "Estamos a " << f.dia() << " de " << f.mes() << " del año " << f.anio() << ", por la gracia de dios.";
    
    os << Fecha::diasSemana[f.diaSemana()] << ", " << f.dia() << " de " << Fecha::meses[f.mes() - 1] << " de " << f.anio();
    return os;
}

// Empieza la sobrecarga de operadores.
// Sobrecarga operador igual (=).
Fecha Fecha::operator =(const Fecha& f) {
    if(this != &f) {
        this->~Fecha();
        initFecha (f.dia(), f.mes(), f.anio());
    }
    return *this;
}

// Sobrecarga operador pre-incremento (++Fecha).
Fecha Fecha::operator ++() {
    struct tm hoy = obtenerStructTime();
    
    time_t manana = mktime(&hoy) + numSegundosIncremento;
    std::tm* tiempoDescompuesto = std::localtime(&manana);
    
    int dia = tiempoDescompuesto->tm_mday;
    int mes = tiempoDescompuesto->tm_mon + 1;
    int anio = tiempoDescompuesto->tm_year + 1900;
    
    initFecha(dia, mes, anio);
    
    return *this;
}

// Sobrecarga operador post-incremento (Fecha++).
Fecha Fecha::operator ++(int f) {
    Fecha self(*this);
    ++(*this);
    return self;
}

// Sobrecarga operador pre-decremento (--Fecha).
Fecha Fecha::operator --() {
    struct tm hoy = obtenerStructTime();
    
    time_t ayer = mktime(&hoy) - numSegundosIncremento;
    std::tm* tiempoDescompuesto = std::localtime(&ayer);
    
    int dia = tiempoDescompuesto->tm_mday;
    int mes = tiempoDescompuesto->tm_mon + 1;
    int anio = tiempoDescompuesto->tm_year + 1900;
    tiempoDescompuesto->tm_wday;
    
    initFecha(dia, mes, anio);
    
    return *this;
}

// Sobrecarga operador post-decremento (Fecha--).
Fecha Fecha::operator --(int f) {
    Fecha self(*this);
    --(*this);
    return self;
}

// Sobrecarga operador suma (Fecha + int).
Fecha Fecha::operator +(int f) {
    Fecha suma(*this);
    for (int i = 0; i < f; i++) {
        ++(suma);
    }
    return suma;
}

// Sobrecarga operador resta (Fecha - int).
Fecha Fecha::operator -(int f) {
    Fecha resta(*this);
    for (int i = 0; i < f; i++) {
        --(resta);
    }
    return resta;
}

// Sobrecarga operador += .
Fecha Fecha::operator +=(int f) {
    for (int i = 0; i < f; i++) {
        ++(*this);
    }
    return *this;
}

// Sobrecarga operador -= .
Fecha Fecha::operator -=(int f) {
    for (int i = 0; i < f; i++) {
        --(*this);
    }
    return *this;
}

// Destructor.
Fecha::~Fecha() { }

// Metodo privado.
tm Fecha::obtenerStructTime() const {
    struct tm hoy = { 0 };
    hoy.tm_mday = dia_;
    hoy.tm_mon = mes_ - 1;
    hoy.tm_year = anio_ - 1900;
    hoy.tm_isdst = -1;
    
    return hoy;
}

int main(int argc, const char *argv[])
{
    try {
        Fecha hoy;
        
        std::cout << hoy << std::endl;
        std::cout << "==============" << std::endl;
        
        ++hoy;
        
        std::cout << hoy << std::endl;
        std::cout << "==============" << std::endl;
        
        hoy--;
        hoy--;
        hoy = hoy + 5;
        
        std::cout << hoy << std::endl;
        std::cout << "==============" << std::endl;
        
        hoy += 5;
        
        std::cout << hoy << std::endl;
        std::cout << "==============" << std::endl;
        
    } catch(Fecha::Invalida e) {
        std::cout << e.porque() << std::endl;
    }
    
    /*
     *Fecha anteayer("07/03/2018");
     *
     *std::cout << anteayer << std::endl;
     *std::cout << "==============" << std::endl;
     */
    
    return 0;
}



