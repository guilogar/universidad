#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <cstring>
#include <fstream>
#include <iomanip>
//#include <cstdint>

#include "cronometro.h"

using namespace std;
ofstream file;

void inser_directa(int *array, int tamano)
{
    for (int i = 0; i < tamano; i++) {
        for (int j = 0; j < tamano; j++) {
            int x = array[j];
            if(x > array[j + 1]) {
                array[j] = array[j + 1];
                array[j + 1] = x;
            }
        }
    }
}

void permutaciones_inser_directa(int *array, int n) {
    int total_num_perm = 0;
    int num_perm;
    int array_perms[n];
    double t;
    cronometro c;
    // Aqui abro el archivo. El ios::trunc indica que si no existe, lo crea. Y que si existe el archivo, lo limpia por dentro.
    file.open("inser_directa.txt", ios::trunc);
    
    for (int i = 0; i < n; i++) {
        c.activar();
        t = 0;
        num_perm = 0;
        do {
            memcpy(array_perms, array, (sizeof (int)) * i);
            
            //print_array(array_perms, i);
            inser_directa(array_perms, i);
            //print_array(array_perms, i);
            
            num_perm++;
            total_num_perm++;
        } while (next_permutation(array, array + i));
        c.parar();
        t = c.tiempo();
        
        cout << "Con tamaño " << (i) << " tiene " << num_perm << " permutaciones y tarda ";
        cout << t << "segundos.";
        cout << "\n";
	// Aqui se mete la informacion en el fichero. Basicamente se redirije el flujo de salida a un fichero.
        file << (i + 1) << "  " << t << "\n";
    }
    // Aqui se cierra el fichero. Es muy importante cerrarlo. El c++ a veces lo cierra por ti y otra veces da un error de memoria.
    // Por eso, cierralo tu siempre mejor, asi el mundo no explota.
    file.close();
    cout << "El numero de permutaciones total es => " << total_num_perm << ".\n";
}

int main(int argc, const char *argv[])
{
    //int N = 20000;
    int N = 9;
    int numeros[N];
    for (int i = 0; i < N; i++)
    {
        numeros[i] = i;
    }
    permutaciones_inser_directa(numeros, N);
    return 0;
}
