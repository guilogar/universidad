#include <iostream>
#include <ctime>
#include "fecha.hpp"

Fecha::Fecha(int dia, int mes, int anio) {
    
    if(anio < 1 || mes < 1 || dia < 0)
        throw FechaInvalida ();
    
    if(dia > 31 || mes > 12)
        throw FechaInvalida ();
    
    if(mes == 2 && dia > 29)
        throw FechaInvalida ();
    
    if(mes == 2 && dia > 28 && anio % 4 == 0 && (anio % 400 == 0 || anio % 100 != 0))
        throw FechaInvalida ();
    
    
    dia_ = dia;
    mes_ = mes;
    anio_ = anio;
}

Fecha::Fecha(int dia, int mes) {
    int anio = tiempo_descompuesto->tm_year + 1900;
    Fecha(dia, mes, anio);
}

Fecha::Fecha(int dia) {
    int mes = tiempo_descompuesto->tm_mon + 1;
    Fecha(dia, mes);
}

Fecha::Fecha() {
    Fecha(tiempo_descompuesto->tm_mday);
}
