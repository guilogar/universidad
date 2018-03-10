
class Cadena {
    public:
        void initCadena(int tamanio = 0, const char cad[] = "");
        
        Cadena(int tamanio, const char caracter);
        Cadena(int tamanio, const char cad[]);
        Cadena(const char cad[]);
        Cadena(int tamanio = 0);
        Cadena(Cadena& c);
        
        friend std::ostream& operator <<(std::ostream& os, Cadena& c);
        const char operator[](int pos);
        
        int length() const;
        
        class TamanioInvalido { };
    private:
        int tamanio_;
        char * cad_;
};
