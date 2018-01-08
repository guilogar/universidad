#ifndef BiCola_ENLA_H
#define BiCola_ENLA_H
#include <cassert>

template <typename T>
class BiCola {
    public:
        BiCola(); // constructor
        BiCola(const BiCola<T>& c); // ctor. de copia
        BiCola<T>& operator =(const BiCola<T>& c); // asignación
        bool vacia() const;
        const T& tope() const;
        void popInicial();
        void popFinal();
        void push(const T& x);
        ~BiCola(); // destructor
    private:
        struct nodo {
            T elto;
            nodo* sig;
            nodo(const T& e, nodo* c = 0): elto(e), sig(c) {}
        };
        nodo* tope_;
        nodo* begin_;
        void copiar(const BiCola<T>& c);
};

template <typename T>
inline BiCola<T>::BiCola() : tope_(0), begin_(0) { }

template <typename T>
BiCola<T>::BiCola(const BiCola<T>& c) : tope_(0), begin_(0)
{
    copiar(c);
}

template <typename T>
BiCola<T>& BiCola<T>::operator =(const BiCola<T>& c)
{
    if (this != &c) { // evitar autoasignación
        this->~BiCola(); // vaciar la BiCola actual
        copiar(c);
    }
    return *this;
}

template <typename T>
inline bool BiCola<T>::vacia() const
{ return (!begin_); }

template <typename T>
inline const T& BiCola<T>::tope() const
{
    assert(!vacia());
    return tope_->elto;
}

template <typename T>
inline void BiCola<T>::popInicial()
{
    assert(!vacia());
    nodo* c = begin_;
    begin_ = begin_->sig;
    delete c;
}

template <typename T>
inline void BiCola<T>::popFinal()
{
    assert(!vacia());
    nodo* c = begin_;
    while(c->sig != tope_) {
        c = c->sig;
    }
    delete c->sig;
    tope_ = c;
}

template <typename T>
inline void BiCola<T>::push(const T& x)
{
    if(begin_ == 0) {
        begin_ = tope_= new nodo(x, 0);
    } else {
        tope_->sig = new nodo(x, 0);
        tope_ = tope_->sig;
    }
}

// Destructor: vacía la BiCola
template <typename T>
BiCola<T>::~BiCola()
{
    nodo* c;
    while (tope_) {
        c = tope_->sig;
        delete tope_;
        tope_ = c;
    }
}

// Método privado
template <typename T>
void BiCola<T>::copiar(const BiCola<T>& c)
{
    if (!c.vacia()) {
        begin_ = new nodo(c.tope()); // copiar el primer elto
        
        // Copiar el resto de elementos hasta el fondo de la BiCola.
        nodo* p = begin_; // recorre la BiCola destino
        nodo* q = c.begin_->sig; // 2º nodo, recorre la BiCola origen
        while (q) {
            p->sig = new nodo(q->elto);
            p = p->sig;
            q = q->sig;
        }
    }
}
#endif // BiCola_ENLA_H
