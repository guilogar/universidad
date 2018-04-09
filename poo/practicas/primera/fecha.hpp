#include <cstring>
#include <ctime>
#include <iostream>

class Fecha {
    public:
        static const char * diasSemana[];
        static const char * meses[];
        
        Fecha(int dia = 0, int mes = 0, int anio = 0);
        Fecha(const char s[]);
        
        int dia() const;
        int mes() const;
        int anio() const;
        
        //friend inline std::ostream& operator <<(std::ostream& os, const Fecha& f);
        //friend std::basic_ostream<char>& operator <<(std::basic_ostream<char>& os, const Fecha& f);
        
        //operator const char*();
        
        char* cadena() const;
        
        static const int AnnoMinimo = 1902;
        static const int AnnoMaximo = 2037;
        
        Fecha operator =(const Fecha& f);
        
        Fecha operator ++();
        Fecha operator ++(int f);
        Fecha operator --();
        Fecha operator --(int f);
        
        Fecha operator +(int f) const;
        Fecha operator -(int f) const;
        
        Fecha operator +=(int f);
        Fecha operator -=(int f);
        
        bool operator ==(const Fecha& f) const;
        bool operator !=(const Fecha& f) const;
        bool operator  >(const Fecha& f) const;
        bool operator  <(const Fecha& f) const;
        bool operator >=(const Fecha& f) const;
        bool operator <=(const Fecha& f) const;
        
        class Invalida {
            public:
                Invalida(const char * motivo = "") : motivo_(motivo) {}
                const char* por_que() const {
                    return motivo_;
                }
            private:
                const char* motivo_;
        };
    private:
        int dia_, mes_, anio_;
        double numSegundosIncremento = 86400;
        
        tm obtenerStructTime() const;
        int diaSemana() const;
};

const char * Fecha::diasSemana[7] = {"Domingo", "Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado"};
const char * Fecha::meses[12] = {"Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre"};

Fecha::Fecha(int dia, int mes, int anio) {
    time_t calendario = time(0);
    tm* tiempoDescompuesto = localtime(&calendario);
    
    (dia == 0) ? dia_ = tiempoDescompuesto->tm_mday : dia_ = dia;
    (mes == 0) ? mes_ = ++tiempoDescompuesto->tm_mon : mes_ = mes;
    (anio == 0) ? anio_ = tiempoDescompuesto->tm_year + 1900 : anio_ = anio;
    
    if(anio_ < 0 || mes_ < 0 || dia_ < 0)
        throw Invalida ("Día o mes o año totalmente incorrectos.");
    
    if(dia_ > 31 || mes_ > 12)
        throw Invalida ("Día o mes totalmente incorrectos.");
    
    if(mes_ == 2 && dia_ > 29)
        throw Invalida ("Día imposible para el mes actual.");
    
    if(mes_ == 2 && dia_ > 28 && !(anio_ % 4 == 0 && (anio_ % 400 == 0 || anio_ % 100 != 0))) {
        throw Invalida ("Día imposible para el mes actual.");
    }
    
    if(anio_ < AnnoMinimo || anio_ > AnnoMaximo) {
        throw Invalida ("El año no puede ser menor de 1902 ni mayor de 2037.");
    }
}

Fecha::Fecha(const char s[]) {
    int dia, mes, anio;
    bool correct_format = (sscanf(s, "%d/%d/%d", &dia, &mes, &anio) == 3);
    (correct_format) ? *this = Fecha(dia, mes, anio) : throw Invalida("Formato Incorrecto.");
}

int Fecha::dia() const {
    return dia_;
}
int Fecha::mes() const {
    return mes_;
}
int Fecha::anio() const {
    return anio_;
}

// Empieza la sobrecarga de operadores.
// Sobrecarga operador const char* .
char* Fecha::cadena() const {
    char* fecha = new char[250];
    char* dia_str = new char[2];
    char* anio_str = new char[4];
    
    strcpy(fecha, "");
    
    strcat(fecha, Fecha::diasSemana[this->diaSemana()]);
    strcat(fecha, ", ");
    
    sprintf(dia_str, "%02d", this->dia());
    strcat(fecha, dia_str);
    
    strcat(fecha, " de ");
    strcat(fecha, Fecha::meses[this->mes() - 1]);
    strcat(fecha, " de ");
    
    sprintf(anio_str, "%04d", this->anio());
    strcat(fecha, anio_str);
    
    return fecha;
}

// Sobrecarga operador igual (=).
Fecha Fecha::operator =(const Fecha& f) {
    dia_ = f.dia();
    mes_ = f.mes();
    anio_ = f.anio();
    return *this;
}

// Sobrecarga operador pre-incremento (++Fecha).
Fecha Fecha::operator ++() {
    *this += 1;
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
    *this -= 1;
    return *this;
}

// Sobrecarga operador post-decremento (Fecha--).
Fecha Fecha::operator --(int f) {
    Fecha self(*this);
    --(*this);
    return self;
}

// Sobrecarga operador suma (Fecha + int).
Fecha Fecha::operator +(int f) const {
    Fecha suma(*this);
    suma += f;
    return suma;
}

// Sobrecarga operador resta (Fecha - int).
Fecha Fecha::operator -(int f) const {
    Fecha resta(*this);
    resta -= f;
    return resta;
}

// Sobrecarga operador += .
Fecha Fecha::operator +=(int f) {
    struct tm fecha = obtenerStructTime();
    
    time_t manana = mktime(&fecha) + (numSegundosIncremento * f);
    tm* tiempoDescompuesto = localtime(&manana);
    
    int dia = tiempoDescompuesto->tm_mday;
    int mes = tiempoDescompuesto->tm_mon + 1;
    int anio = tiempoDescompuesto->tm_year + 1900;
    
    *this = Fecha(dia, mes, anio);
    
    return *this;
}

// Sobrecarga operador -= .
Fecha Fecha::operator -=(int f) {
    (*this) += (f*-1);
    return *this;
}

bool Fecha::operator ==(const Fecha& f) const {
    return (this->dia() == f.dia() && this->mes() == f.mes() && this->anio() == f.anio());
}

bool Fecha::operator !=(const Fecha& f) const {
    return !(*this == f);
}

bool Fecha::operator >(const Fecha& f) const {
    if(this->anio() == f.anio()) {
        if(this->mes() == f.mes())
            return (this->dia() > f.dia());
        return (this->mes() > f.mes());
    }
    return (this->anio() > f.anio());
}

bool Fecha::operator >=(const Fecha& f) const {
    return (*this > f || *this == f);
}

bool Fecha::operator <(const Fecha& f) const {
    return !(*this >= f);
}

bool Fecha::operator <=(const Fecha& f) const {
    return !(*this > f);
}

// Metodo privado.
tm Fecha::obtenerStructTime() const {
    struct tm hoy = { 0 };
    hoy.tm_mday = dia_;
    hoy.tm_mon = mes_ - 1;
    hoy.tm_year = anio_ - 1900;
    hoy.tm_isdst = -1;

    return hoy;
}
int Fecha::diaSemana() const {
    tm fecha = obtenerStructTime();
    time_t time = mktime(&fecha);
    tm* tiempoDescompuesto = localtime(&time);
    
    return tiempoDescompuesto->tm_wday;
}
