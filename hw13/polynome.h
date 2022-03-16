//
// Created by zzemlyanaya on 12.03.2022.
//

#include <cmath>
#include <iostream>

using namespace std;

class Polynome {
public:
    int deg;
    double* coeff; // from a_0 to a_n
    
    Polynome();
    Polynome(int deg);
    Polynome(int deg, double* coeff);
    Polynome(Polynome* p);

    friend ostream& operator<<(ostream& os, Polynome p);
    friend istream& operator>>(istream& is, Polynome& p);
    Polynome operator+(Polynome rgh);
    Polynome operator-(Polynome rgh);
    Polynome operator*(Polynome rgh);
    Polynome operator/(double t);
    Polynome operator/(Polynome rgh);

    double at(double x);
    Polynome derivative();

private:
    bool isZero();
    void reduce();
};
