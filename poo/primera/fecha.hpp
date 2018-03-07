class Fecha {
    public:
        Fecha(int dia, int mes, int anio);
        Fecha(int dia, int mes);
        Fecha(int dia);
        Fecha(const Fecha&);
        Fecha();
        int dia() const;
        int mes() const;
        int anio() const;
        
        class FechaInvalida {};
    private:
        int dia_, mes_, anio_;
        std::time_t calendario = std::time(nullptr);
        std::tm* tiempo_descompuesto = std::localtime(&calendario);
};
