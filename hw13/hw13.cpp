//
// Created by zzemlyanaya on 12.03.2022.
//

#include "polynome.h"
#include "windows.h"


int main() {
    SetConsoleOutputCP(CP_UTF8);

    int t;

    cout << "First polynome's deg:" << endl;
    cin >> t;
    Polynome p1 = Polynome(t);
    cout << "Coeff:" << endl;
    cin >> p1;

    cout << "Second polynome's deg:" << endl;
    cin >> t;
    Polynome p2 = Polynome(t);
    cout << "Coeff:" << endl;
    cin >> p2;

    cout << "Point:" << endl;
    cin >> t;

    cout << "p1: " << p1 << "\tat " << t << ": " << p1.at(t) << endl;
    cout << "p2: " << p2 << "\tat " << t << ": " << p2.at(t) << endl;

    cout << "derivative of p1: " << p1.derivative();
    cout << "derivative of p2: " << p2.derivative();

    Polynome sum = p1+p2;
    Polynome dif = p1-p2;
    Polynome mul = p1*p2;
    Polynome div = p1/t;
    Polynome gcd = p1.gcd(&p2);

    cout << "p1 + p2: " << sum;
    cout << "p1 - p2: " << dif;
    cout << "p1 * p2: " << mul;
    cout << "p1 / p2: " << div;
}