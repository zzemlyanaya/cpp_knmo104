//
// Created by Evgeniya Zemlyanaya on 20.04.2022.
//
#include <iostream>
#include <cmath>

using namespace std;

typedef double (*Fun)(double x);

double f(double x) { return 8*x*x*x+2; }
double dx_f(double x) { return 3*x*x; }
double ddx_f(double x) { return 6*x; }

double find_root(double a, double b, double eps, Fun f) {
    double x0, x1, x2;
    x0 = a, x1 = b;
    x2 = (x1*f(x0) - x0*f(x1)) / (f(x1)-f(x0));
    while(fabs(x2) > eps) {
        x0 = x1;
        x1 = x2;
        x2 = (x1*f(x0) - x0*f(x1)) / (f(x1)-f(x0));
    }

    return x2;
}

int main() {

    double a, b, eps;
    cin >> a >> b >> eps;
    Fun fun = &f;

    cout << "RESULT: " << find_root(a, b, eps, fun);

    return 0;
}

