//
// Created by zzemlyanaya on 20.10.2021.
//

#include <windows.h>
#include <iostream>
#include <string>

using namespace std;

void solveFirst(double x, double eps) {
    double current = x;
    double sum = 0;
    double f = 2;
    while (fabs(current) > eps) {
        sum += x;
        current = -current*x*x/(3*f*(f+1));
        f += 2;
    }

    cout << sum << endl;
}

void solveSecond(int n) {
    double mmin = INT32_MAX;
    double cur;
    string res;
    for(int i = 0; i < n; i++) {
        cin >> cur;
        if (cur < mmin) {
            mmin = cur;
            res = to_string(i+1);
        }
        else if (cur == mmin) {
            res += " " + to_string(i+1);
        }
    }

    cout << res << endl;
}

int gcd (int a, int b) {
    while (a!=0 && b!=0) {
        if (a>b) {
            a=a%b;
        }
        else b=b%a;
    }
    return a+b;
}

void solveThird(int a, int b) {
    string z = "";
    int sa = a < 0 ? -1 : 1;
    int sb = b < 0 ? -1 : 1;
    if (sa * sb == -1) z += "-";
    a *= sa; b *= sb;

    z += to_string(a/b) + ".";

    while(b%2 == 0) {
        b = b / 2;
        a = a * 5;
    }
    while (b%5 == 0) {
        b = b / 5;
        a = a * 2;
    }

    int c = gcd(a,b);
    a = a/c;
    b = b/c;

    if (b == 1) {
        z += to_string(a);
        cout << z << endl;
        return;
    }

    string period = "";
    if (a > b) {
        period = to_string((a - a % b) / b);
        a = a % b;
        if (a == 0) {
            z += period;
            cout << z << endl;
            return;
        }
        period = period + "(";
    } else {
        period = "(";
    }

    while (a%10 == 0)
        a=a/10;

    int i = a;
    while (true) {
        int j = 0;
        while (i < b) {
            i = i * 10;
            j = j + 1;
            if (j > 1)
                period += "0";
        }

        int check = i - a;
        if ((check % b) == 0) {
            period += to_string((check) / b);
            break;
        }
        else {
            j = i % b;
            period += to_string((i - j) / b);
            i = j;
        }
    }

    period += ")";
    z += period;

    cout << z << endl;
}

void solveFourth(int n, double eps) {
    double x, y;
    string res = "";
    for (int i = 0; i < n; ++i) {
        cin >> x >> y;
        if (fabs(x) < eps && fabs(y) < eps) res += to_string(i+1) + " ";
    }

    cout << "В окрестности лежат точки: " << res << endl;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    double x, eps;
    int k, m;

    int n = 1;
    cout << "Номер задачи для теста:" << endl;
    cin >> n;
    while (n != -1) {
        switch(n) {
            case 1: {
                cin >> x >> eps;
                solveFirst(x, eps);
                break;
            }
            case 2: {
                cin >> k;
                solveSecond(k);
                break;
            }
            case 3: {
                cin >> k >> m;
                solveThird(k, m);
                break;
            }
            case 4: {
                cin >> k >> eps;
                solveFourth(k, eps);
                break;
            }
            default:
                break;
        }
        cout << "Номер задачи для теста:" << endl;
        cin >> n;
    }

    return 0;
}