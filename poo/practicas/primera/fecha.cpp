#include <iostream>
#include <sstream>
#include "fecha.hpp"

int Fecha::dia() const {
    return dia_;
}
int Fecha::mes() const {
    return mes_;
}
int Fecha::anio() const {
    return anio_;
}

void Fecha::initFecha(int dia = 0, int mes = 0, int anio = 0) {
    std::time_t calendario = std::time(nullptr);
    std::tm* tiempo_descompuesto = std::localtime(&calendario);
    
    (dia == 0) ? dia_ = tiempo_descompuesto->tm_mday : dia_ = dia;
    (mes == 0) ? mes_ = ++tiempo_descompuesto->tm_mon : mes_ = mes;
    (anio == 0) ? anio_ = tiempo_descompuesto->tm_year + 1900 : anio_ = anio;
    
    
    if(anio < 0 || mes < 0 || dia < 0)
        throw FechaInvalida ();
    
    if(dia > 31 || mes > 12)
        throw FechaInvalida ();
    
    if(mes == 2 && dia > 29)
        throw FechaInvalida ();
    
    if(mes == 2 && dia > 28 && anio % 4 == 0 && (anio % 400 == 0 || anio % 100 != 0))
        throw FechaInvalida ();
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
    Fecha(f.dia(), f.mes(), f.anio());
}

std::string Fecha::toString() {
    std::stringstream ss;
    ss << "Estamos a " << dia_ << " de " << mes_ << " de " << anio_ << ", por la gracia de dios.";
    return ss.str();
}

Fecha::~Fecha() {
    //delete tiempo_descompuesto;
}

Fecha& Fecha::operator =(const Fecha& f) {
    if(this != &f) {
        this->~Fecha();
        Fecha(f.dia(), f.mes(), f.anio());
    }
    return *this;
}

int main(int argc, const char *argv[])
{
    Fecha hoy;
    std::cout << hoy.toString() << std::endl;
    return 0;
}



