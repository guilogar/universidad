#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <algorithm>

using namespace std;

int num_aleat_int(int a, int b)
{
    return (a + (rand() % (b - a + 1)));
}

double num_aleat_double(double a, double b)
{
    return (a + ((double) rand() / RAND_MAX) * (b - a));
}

double dado_aleatorio()
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

double num_aleat_muy_grande(long n) {
    double y = 0;
    
    for (int i = 0; i < n; i++) {
        y += 4 * sqrt(1 - pow(num_aleat_double(0, 1), 2));
    }
    return (double) y / n;
}

double perm_pseudo_aleat(int num_natu, long n) {
    double perm_ord = 0;
    int numeros[num_natu];
    
    for (int i = 1; i <= num_natu; i++) {
        numeros[i - 1] = i;
    }

    for (long i = 1; i <= n; i++) {
        random_shuffle(numeros, numeros + num_natu);
        
        if(!next_permutation(numeros, numeros + num_natu)) {
            perm_ord++;
        }
    }
    return perm_ord;
}

int main(int argc, const char *argv[])
{
    int a, b;
    srand(time(0));
    
    /*
     *cout << "Dime el número a => ";
     *cin >> a;
     *cout << "Dime el número b => ";
     *cin >> b;
     *
     *cout << "El número aleatorio discreto es => " << num_aleat_int(a, b) << "." << endl;
     *
     *dado_aleatorio();
     *
     *cout << "Dime el número a continuo => ";
     *cin >> a;
     *cout << "Dime el número b continuo => ";
     *cin >> b;
     *
     *cout << "El número aleatorio continuo es => " << num_aleat_double(a, b) << "." << endl;
     */
    
    /*
     *double res = num_aleat_muy_grande(10000000L);
     *std::cout << "Y la media de tantos numeros es => " << res << std::endl;
     */
    
    double resu = perm_pseudo_aleat(6, 10000000L);
    std::cout << "Existen " << resu << " de permutaciones ordenadas." << std::endl;
    return 0;
}
