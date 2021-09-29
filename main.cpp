#include <windows.h>
#include <iostream>

using namespace std;

void doMagicYears(int years) {
    int last = years%10;
    if (years%100 == 11 || years%100 == 12 || years%100 == 13 || years%100 == 14)
        cout << years << " лет";
    else if (last == 1)
        cout << years << " год";
    else if (last == 2 || last == 3 || last == 4)
        cout << years << " года";
    else
        cout << years << " лет";
}

void doMagicGoat(double a, double l) {
    double pi = 2*acos(0.0);
    double res = 0;
    if (l <= a/2) {
        res = pi*l*l;
    }
    else if (l*l >= 2*a*a/4) {
        res = a*a;
    }
    else {
        double cos_half = a/(2*l);
        double cos_full = 2*cos_half*cos_half - 1;
        double phi = acos(cos_full);
        double seg = 0.5*l*l*(phi - sin(phi));
        res = pi*l*l - seg*4;
    }

    cout << "Съедено " << res;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);

    double a = 0; double l = 0;
    while (a != -1 || l != -1) {
        cin >> a >> l;
//        doMagicYears(y);
        doMagicGoat(a, l);
        cout << "\n";
    }

    return 0;
}