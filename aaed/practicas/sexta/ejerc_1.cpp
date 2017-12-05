#include <stdlib.h>
#include <iostream>
#include <cstdlib>
#include <ctime>

#include "pila.h"
#include "cola.h"

#define N 10

using namespace std;

bool is_isomorphic(Cola<int> c, Pila<int> p) {
    bool is_iso = true;
    
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
    for (int i = 0; i < N; i++) {
        c.push(i);
        cout << i;
    }
    cout << endl;
    
    Pila<int> p;
    for (int j = N - 1; j > 0; j--) {
        p.push(j);
        cout << j;
    }
    cout << endl;
    
    if(is_isomorphic(c, p))
        cout << "Son isomorfos chaval, asumelo.";
    else
        cout << "=(";
    
    return 0;
}
