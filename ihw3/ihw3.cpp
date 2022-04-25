//
// Created by Evgeniya Zemlyanaya on 25.04.2022.
//

#include <fstream>
#include <iostream>
#include <cmath>

using namespace std;

typedef double (*fun)(double, double);

double f(double x, double eps) {
    double sum = 0, t = x;
    for (int n = 1; fabs(t) > eps; ++n) {
        sum += t;
        t *= x*x/(2*n*(2*n+1));
    }

    return sum;
}

double left_rectangles(double a, double b, double eps, fun f) {
    double h = b - a;
    double sum_cur = 0, sum_prev = b;

    while (fabs(sum_cur-sum_prev) > eps) {
        sum_prev = sum_cur;
        for (double x = a; x < b; x += h)  sum_cur += f(x, eps);

        sum_cur *= h;
        h /= 2;
    }

    return sum_cur;
}

double middle_rectangles(double a, double b, double eps, fun f) {
    double h = b - a;
    double sum_cur = a, sum_prev = b;

    while (fabs(sum_cur-sum_prev) > eps) {
        sum_prev = sum_cur;
        for (double x = a+h/2; x < b; x += h)  sum_cur += f(x, eps);

        sum_cur *= h;
        h /= 2;
    }

    return sum_cur;
}

double trapeziods(double a, double b, double eps, fun f) {
    double h = (b - a)/2;
    double sum_cur = h, sum_prev = 0;

    while (fabs(sum_cur-sum_prev) > eps) {
        sum_prev = sum_cur;
        for (double x = a; x < b; x += h)  sum_cur += f(x, eps);

        sum_cur *= h;
        h /= 2;
    }

    return sum_cur;
}

int main() {
    ifstream input ("input.txt");
    ofstream output ("output.txt");

    if (input.fail()) return -1;

    double a, b, eps;
    int method;

    input >> a >> b >> eps >> method;
    fun ff = &f;

//    switch (method) {
//        case 1:
//            output << "Left rectangles: " << left_rectangles(a, b, eps, ff) << endl;
//            break;
//        case 2:
//            output << "Middle rectangles: " << middle_rectangles(a, b, eps, ff) << endl;
//            break;
//        case 3:
//            output << "Trapeziods: " << trapeziods(a, b, eps, ff) << endl;
//            break;
//        default:
//            break;
//    }

    output << "Left rectangles: " << left_rectangles(a, b, eps, ff) << endl;
    output << "Middle rectangles: " << middle_rectangles(a, b, eps, ff) << endl;
    output << "Trapeziods: " << trapeziods(a, b, eps, ff) << endl;
    return 0;
}