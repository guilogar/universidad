#include <cstring>
#include <ctime>

class Fecha {
    public:
        static const std::string diasSemana[];
        static const std::string meses[];
        
        void initFecha(int dia, int mes, int anio);
        
        Fecha(int dia, int mes, int anio);
        Fecha(int dia, int mes);
        Fecha(int dia);
        Fecha(const Fecha& f);
        Fecha(const std::string& s);
        Fecha();
        
        int dia() const;
        int diaSemana() const;
        int mes() const;
        int anio() const;
        
        friend std::ostream& operator <<(std::ostream& os, const Fecha& f);
        
        static const int AnnoMinimo = 1902;
        static const int AnnoMaximo = 2037;
        
        Fecha operator =(const Fecha& f);
        
        Fecha operator ++();
        Fecha operator ++(int f);
        Fecha operator --();
        Fecha operator --(int f);
        
        Fecha operator +(int f);
        Fecha operator -(int f);
        
        Fecha operator +=(int f);
        Fecha operator -=(int f);
        
        ~Fecha();
        
        class Invalida {
            public:
                Invalida(std::string motivo = "") : motivo_(motivo) {}
                std::string porque() const {
                    return motivo_;
                }
            private:
                std::string motivo_;
        };
    private:
        int dia_, mes_, anio_;
        int numSegundosIncremento = 86400;
        
        tm obtenerStructTime() const;
};
