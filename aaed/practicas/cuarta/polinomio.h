
#ifndef _POLINOMIO_
#define _POLINOMIO_

class polinomio{
    public:
        explicit polinomio(int grado);
        //polinomio(const polinomio& p);
        //~polinomio();
        
        void operator =(const polinomio& p);
        friend polinomio operator +(const polinomio& p, const polinomio& q);
        friend polinomio operator +(const polinomio& p, const polinomio& q);
        friend polinomio operator *(const polinomio& p, const polinomio& q);
        //polinomio operator /(const polinomio& p);
        
        int grado() const;
        double coeficiente(unsigned n) const;
        void coeficiente(int n, double c);
    private:
        int grado_pol;
        double *coeficientes;
};
#endif

