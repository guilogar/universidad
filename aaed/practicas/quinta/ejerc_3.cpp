#include <stdlib.h>
#include <iostream>
#include <cstdlib>
#include <ctime>

#include "pila.h"

using namespace std;

void print_pila(Pila<int> p) {
    while(!p.vacia()) {
        int num = p.tope();
        p.pop();
        cout << "|" << num;
    }
    cout << "|"  << endl;
}

Pila<int> invert_sec_pila(int a, int b, Pila<int> p) {
    Pila<int> copy(p);
    Pila<int> range;
    Pila<int> guard;
    Pila<int> result;
    
    bool a_number_found = false;
    bool b_number_found = false;
    
    while(!copy.vacia() && !b_number_found) {
        int num = copy.tope();
        copy.pop();
        if (num != b) {
            guard.push(num);
        } else {
            b_number_found = !b_number_found;
            range.push(num);
        }
    }
    
    while(!copy.vacia() && !a_number_found) {
        int num = copy.tope();
        copy.pop();
        range.push(num);
        if (num == a) {
            a_number_found = !a_number_found;
        }
    }
    
    while(!range.vacia() && a_number_found && b_number_found) {
        int num = range.tope();
        range.pop();
        guard.push(num);
    }
    
    while(!copy.vacia()) {
        int num = copy.tope();
        copy.pop();
        guard.push(num);
    }
    
    if(a_number_found && b_number_found) {
        while(!guard.vacia()) {
            int num = guard.tope();
            guard.pop();
            result.push(num);
        }
        return result;
    }
    return p;
}

int main() {
    
    srand(time(0));
    Pila<int> p;
    for (int i = 0; i < 20; i++) {
        //p.push(rand());
        p.push(i);
    }
    //Pila<int> t = invert_sec_pila(0, 63, p);
    Pila<int> t = invert_sec_pila(5, 15, p);
    print_pila(p);
    print_pila(t);
    
    return 0;
}
