//
// Created by zzemlyanaya on 24.11.2021.
//

#include <windows.h>
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int solveFirst(int n) {
    if (n / 10)
        return solveFirst(n / 10) + 1;
    else
        return 1;
}

bool solveSecond(int n, int lst) {
    if (n < 10) return n > lst;
    return n%10 > lst && solveSecond(n/10, n%10);
}

string int_to_sym(int n) {
    if (n < 10) return to_string(n);
    switch (n) {
        case 10: return "A";
        case 11: return "B";
        case 12: return "C";
        case 13: return "D";
        case 14: return "E";
        case 15: return "F";
        default: return "";
    }
}

string solveThird(int n, int p) {
    if (p > n) return int_to_sym(n);
    return solveThird(n / p, p) + int_to_sym(n%p);
}

static int mmax(int*A, int i)
{
    if (i == 1) return A[0];
    return max(mmax(A, i-1), A[i-1]);
}

void solveFourth(int n) {
    int a[100];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << mmax(a, n) << endl;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    int k, p;

    int n = 1;
    cout << "Номер задачи для теста:" << endl;
    cin >> n;
    while (n != -1) {
        switch(n) {
            case 1: {
                cin >> k;
                cout << solveFirst(k) << endl;
                break;
            }
            case 2: {
                cin >> k;
                cout << solveSecond(k, -1) << endl;
                break;
            }
            case 3: {
                cin >> k >> p;
                cout << solveThird(k, p) << endl;
                break;
            }
            case 4: {
                cin >> k;
                solveFourth(k);
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

