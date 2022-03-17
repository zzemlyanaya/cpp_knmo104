//
// Created by Evgeniya Zemlyanaya on 17.03.2022.
//

#include "TPoint.h"

int main() {
    TPoint p1 = TPoint();
    TPoint p2 = TPoint();
    double t = 0;

    cout << "Enter p1 coordinates: " << endl;
    cin >> &p1;
    cout << "Enter p2 coordinates: " << endl;
    cin >> &p2;
    cout << "Enter a number: " << endl;
    cin >> t;


    TPoint sum = p1 + p2;
    TPoint dif = p1 - p2;
    TPoint mul_t = p1 * t;
    TPoint mul = p1 * p2;

    cout << "p1 + p2: " << &sum << endl;
    cout << "p1 - p2: " << &dif << endl;
    cout << "p1 * t: " << &mul_t << endl;
    cout << "p1 * p2: " << &mul << endl;
}