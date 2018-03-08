#include <cstring>
#include <ctime>

class Fecha {
    public:
        Fecha(int dia, int mes, int anio);
        Fecha(int dia, int mes);
        Fecha(int dia);
        Fecha(const Fecha& f);
        Fecha();
        int dia() const;
        int mes() const;
        int anio() const;
        std::string toString();
        
        Fecha& operator =(const Fecha& f);
        ~Fecha();
        
        class FechaInvalida {};
        
        void initFecha(int dia, int mes, int anio);
    private:
        int dia_, mes_, anio_;
};
