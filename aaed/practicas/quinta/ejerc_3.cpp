#include <stdlib.h>
#include <iostream>
#include "pila.h"

using namespace std;
Pila<int> invert_sec_pila(int a, int b, Pila<int> p) {
    
}

int main() {
    
    Pila<int> p;
    for (int i = 0; i < 50; i++) {
        p.push(i);
    }
    for (int i = 0; i < 50; i++) {
        cout << "Pilita => " << p.tope() << endl;
        p.pop();
    }
    
    return 0;
}
