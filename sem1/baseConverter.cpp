//
// Created by zzemlyanaya on 27.10.2021.
//
#include <windows.h>
#include <iostream>
#include <cmath>

using namespace std;

void convertZ(int a, int a_base, int b_base) {
    int a10 = 0;
    int power = 1;
    while (a > 0) {
        a10 += a%10 * power;
        power = power * a_base;
        a /= 10;
    }

    power = 1;
    while (a10 >= power*b_base) power *= b_base;
    while (power) {
        cout << a10/power;
        a10 -= power*(a10/power);
        power /= b_base;
    }
}

void convertR(int a, int a_base, int b_base) {
    double a10 = 0;
    int power = 1;
    while (a >= power) power *= a_base;

    while (a > 0) {
        a10 += double (a%10) / power;
        power /= a_base;
        a /= 10;
    }

    int scale = 1;
    while (a10 != 0 && scale < 5) {
        a10 *= b_base;
        cout << trunc(a10);
        a10 = a10 - trunc(a10);
        scale++;
    }
}

void convert(double a, int a_base, int b_base) {
    int aZ = trunc(a);
    double aR = a-(double)aZ;
    double temp = aR;
    while (temp != 0) {
        aR *= 10;
        temp = aR-trunc(aR);
    }

    convertZ(aZ, a_base, b_base);
    cout << ",";
    convertR((int)aR, a_base, b_base);
}

int main() {
    SetConsoleOutputCP(CP_UTF8);

    double a;
    int a_base, b_base;
    cin >> a >> a_base >> b_base;
    convert(a, a_base, b_base);

    return 0;
}
