
#ifndef ListaCircular_h
#define ListaCircular_h

#define POS_NULA 0
#include <cassert>

template <typename T>
class ListaCircular
{
    struct nodo; // declaración adelantada privada
    public:
        typedef nodo* posicion; // posición de un elemento
        ListaCircular(); // constructor, requiere ctor. T()
        ListaCircular(const ListaCircular<T>& l); // ctor. de copia, requiere ctor. T()
        ListaCircular<T>& operator =(const ListaCircular<T>& l); // asignación de
        void insertar(const T& x, posicion p);
        void eliminar(posicion p);
        const T& elemento(posicion p) const; // acceso a elto, lectura
        T& elemento(posicion p); // acceso a elto, lectura/escritura
        posicion buscar(const T& x) const; // T requiere operador ==
        posicion inipos() const;
        posicion siguiente(posicion p) const;
        posicion anterior(posicion p) const;
        ~ListaCircular(); // destructor
    private:
        struct nodo
        {
            T elto;
            nodo* sig;
            nodo* ant;
            nodo(const T& e, nodo* p = 0, nodo* q = 0): elto(e), sig(p), ant(q) {}
        };
        nodo* L; // ListaCircular enlazada de nodos
        void copiar(const ListaCircular<T>& l);
};

// Método privado
template <typename T>
void ListaCircular<T>::copiar(const ListaCircular<T> &l)
{
    /*
     *L = new nodo(T());
     *for (nodo* r = l.L->sig; r; r = r->sig)
     *{
     *    copia->sig = new nodo(r->elto);
     *    copia = copia->sig;
     *}
     */
}

template <typename T>
inline ListaCircular<T>::ListaCircular() : L(new nodo(T()))
{}

template <typename T>
inline ListaCircular<T>::ListaCircular(const ListaCircular<T>& l)
{
    copiar(l);
}

template <typename T>
ListaCircular<T>& ListaCircular<T>::operator =(const ListaCircular<T>& l)
{
    if (this != &l)
    {
        this->~ListaCircular();
    }
    
    return *this;
}

template <typename T> inline
void ListaCircular<T>::insertar(const T& x, ListaCircular<T>::posicion p)
{
    p->sig = new nodo(x, p->sig, p);
    L->ant = p;
}

template <typename T>
inline void ListaCircular<T>::eliminar(ListaCircular<T>::posicion p)
{
    assert(p->sig);
    nodo* q = p->sig;
    p->sig = q->sig;
    delete q;
}

/*
 *template <typename T> inline
 *const T& ListaCircular<T>::buscar(ListaCircular<T>::posicion p) const
 *{
 *    assert(p->sig);
 *    return p->sig->elto;
 *}
 */

template <typename T>
typename ListaCircular<T>::posicion ListaCircular<T>::buscar(const T& x) const
{
    nodo* q = L;
    bool encontrado = false;
    
    while (q->sig && !encontrado)
        if (q->sig->elto == x)
            encontrado = true;
        else
            q = q->sig;
    
    return q;
}

template <typename T>
inline T& ListaCircular<T>::elemento(ListaCircular<T>::posicion p)
{
    assert(p->sig);
    return p->sig->elto;
}

template <typename T>
typename ListaCircular<T>::posicion ListaCircular<T>::inipos() const
{

    if(L != 0) {
        return L;
    } else {
        return POS_NULA;
    }
}

template <typename T> inline
typename ListaCircular<T>::posicion ListaCircular<T>::siguiente(ListaCircular<T>::posicion p) const
{
    assert(p->sig);

    if(p->sig == 0) {
        return L;
    }
    return p->sig;
}

template <typename T>
typename ListaCircular<T>::posicion ListaCircular<T>::anterior(ListaCircular<T>::posicion p) const
{
    /*
     *nodo* q;
     *assert(p != L); // p no es la primera posición
     *for (q = L; q->sig != p; q = q->sig);
     *return q;
     */
    return p->ant;
}

// Destructor: destruye el nodo cabecera y vacía la ListaCircular
template <typename T> ListaCircular<T>::~ListaCircular()
{
    nodo* q;
    
    while (L)
    {
        q = L->sig;
        delete L;
        L = q;
    }
}

#endif /* ListaCircular_h */
