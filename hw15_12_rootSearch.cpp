#include <windows.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

float calc(float* p, int n, float x) {
    float val = p[0];
    for (int i = 1; i < n+1; ++i) {
        val *= x;
        val += p[i];
    }

    return val;
}

float searchRoot(float* p, int n, float eps, float a, float b) {
    if (abs(calc(p, n, a)) <= eps) return a;
    if (abs(calc(p, n, b)) <= eps) return b;

    float fst = a, lst = b;
    float current;
    while (fst <= lst) {
        current = (fst+lst)/2;
        float val = calc(p, n, current);

        if (abs(val) <= eps) return current;

        float valA = calc(p, n, fst);
        if (val*valA < 0) {
            lst = current;
        }
        else {
            fst = current;
        }
    }

    return (fst+lst)/2;
}

int main() {
    ifstream inputFile("input.txt");

    if(!inputFile.good()) {
        cout << "Could not read the file" << endl;
        return 0;
    }

    int n;
    float a, b;
    float eps;
    inputFile >> n;
    float* p = new float[n+1];
    for (int i = 0; i < n+1; ++i) {
        inputFile >> p[i];
    }
    inputFile >> eps;
    inputFile >> a >> b;

    cout << searchRoot(p, n, eps, a, b);

    return 0;
}