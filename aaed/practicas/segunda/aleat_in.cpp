#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int num_aleat_int(int a, int b)
{
    return (a + (rand() % (b - a + 1)));
}

int num_aleat_double(double a, double b)
{
    return (a + (rand() / RAND_MAX) * (b - a));
}

int dado_aleatorio()
{
    int v[] = {0, 0, 0, 0, 0, 0};
    
    for (long i = 0; i < 10000000L; i++) {
        int num = num_aleat_int(1, 6);
        v[num - 1] = ++v[num - 1];
    }
    
    for (int i = 0; i < 6; i++) {
        cout << "La cara " << i + 1 << " ha salido " << v[i] << " veces." << endl;
    }
    
    for (int i = 0; i < 6; i++) {
        cout << "La cara " << i + 1 << " ha salido con una frecuencia de " << (double) v[i] / 10000000L << "." << endl;
    }
}

int main(int argc, const char *argv[])
{
    int a, b;
    srand(time(0));
    
    cout << "Dime el número a => ";
    cin >> a;
    cout << "Dime el número b => ";
    cin >> b;
    
    cout << "El número aleatorio discreto es => " << num_aleat_int(a, b) << "." << endl;
    
    dado_aleatorio();
    
    cout << "Dime el número a continuo => ";
    cin >> a;
    cout << "Dime el número b continuo => ";
    cin >> b;
    
    cout << "El número aleatorio continuo es => " << num_aleat_double(a, b) << "." << endl;
    
    return 0;
}
