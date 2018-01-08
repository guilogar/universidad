#include <stdlib.h>
#include <iostream>
#include <cstdlib>
#include <ctime>

#include "pila.h"
#include "cola.h"
#include "bicola.h"

#define N 10

using namespace std;

bool is_isomorphic(Cola<int> c, Pila<int> p) {
    bool is_iso = true;
        cout << c.tope();
        //cout << p.tope();
        return true;
    while(!c.vacia() && !p.vacia()) {
        if(c.tope() != p.tope()) {
            is_iso = false;
        }
        c.pop();
        p.pop();
    }
    
    if(!c.vacia() || !p.vacia()) {
        is_iso = false;
    }
    
    return is_iso;
}

int main()
{
    Cola<int> c;
    BiCola<int> b;
    for (int i = 0; i < N; i++) {
        c.push(i);
        b.push(i);
        cout << c.tope();
    }
    cout << endl;
    
    /*
     *b.popFinal();
     *cout << c.tope();
     *b.popFinal();
     *cout << c.tope();
     */
    
    Pila<int> p;
    for (int j = N - 1; j >= 0; j--) {
        p.push(j);
        cout << p.tope();
    }
    cout << endl;
    
    if(is_isomorphic(c, p))
        cout << "Son isomorfos chaval, asumelo.";
    else
        cout << "=(";
    
    return 0;
}
