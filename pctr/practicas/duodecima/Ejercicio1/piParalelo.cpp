#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <thread>

using namespace std;

double getNumAleat(double a, double b) {
    return (a + ((double) rand() / RAND_MAX) * (b - a));
}

double getPi(int puntos) {
    double aciertos = 0;
    for (int i = 0; i < puntos; i++) {
        double x = getNumAleat(0, 1) * 2 - 1;
        double y = getNumAleat(0, 1) * 2 - 1;
        double z = x*x + y*y;
        
        if(z <= 1) {
            aciertos++;
        }
    }
    return (aciertos * 4) / puntos;
}

int main(int argc, const char *argv[]) {
    
    srand(time(0));
    double aproxPi = getPi(10000);
    cout << "La aproximación a pi es => " << aproxPi << endl;
    
    return 0;
}
