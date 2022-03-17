//
// Created by Evgeniya Zemlyanaya on 17.03.2022.
//

#include <iostream>

using namespace std;

class TPoint {
    double x, y, z;

public:
    TPoint();
    TPoint(double x, double y, double z);

    friend ostream& operator<<(ostream& os, TPoint* p);
    friend istream& operator>>(istream& is, TPoint* p);
    TPoint operator+(TPoint rgh);
    TPoint operator-(TPoint rgh);
    TPoint operator*(double t);
    TPoint operator*(TPoint rgh);
};
