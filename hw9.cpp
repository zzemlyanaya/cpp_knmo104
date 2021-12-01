//
// Created by zzemlyanaya on 01.12.2021.
//
#include <windows.h>
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

void solveFirst(int n1, int n2, int m1, int m2) {
    if (n1 != m1 || n2 != m2) {
        cout << "Недопустимые размеры массивов" << endl;
        return;
    }
    float C[100][100];
    float t;
    for (int i = 0; i < n1; ++i) {
        for(int j = 0; j < n2; ++j) {
            cin >> C[i][j];
        }
    }
    for (int i = 0; i < n1; ++i) {
        for(int j = 0; j < n2; ++j) {
            cin >> t;
            C[i][j] += t;
        }
    }

    for (int i = 0; i < n1; ++i) {
        for(int j = 0; j < n2; ++j) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }
}

void solveSecond(int n, int m) {
    float current = 0, row = 0;
    int counter = 0;
    for (int i = 0; i < n; ++i) {
        row = 0;
        for(int j = 0; j < m; ++j) {
            cin >> current;
            row += current;
        }
        if (row == 0) counter++;
    }

    cout << counter << endl;
}


void solveThird(int n) {
    float A[100][100];
    for (int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cin >> A[i][j];
        }
    }

    float sum;
    int strong = 0;
    int ok = true;
    for (int i = 0; i < n && ok; ++i) {
        sum = 0;
        for (int j = 0; j < n; ++j) {
            if (i == j) continue;
            sum += abs(A[i][j]);
        }
        ok = abs(A[i][i]) >= sum;
        if (abs(A[i][i]) > sum) strong++;
    }

    cout << (ok && strong > 0) << endl;
}

/**
16 2 0 -2
4 20 1 0
2 0 10 0
-4 0 4 32

2 -1.8 0.4
3 2 -1.1
1 -1 7.3

1 0 0
0 1 0
0 0 1
 */



void solveFourth(int n) {
    int A[100][100];
    int cur;
    for (int i = 0; i < n-1; ++i) {
        cur = 1;
        for (int j = i; j < n-1; ++j) {
            A[i][j] = cur;
            cur++;
        }
    }

    for (int i = n-2; i >= 0; --i) {
        cur = n-1;
        for (int j = i-1; j >= 0; --j) {
            A[i][j] = cur;
            cur--;
        }
    }

    for (int i = 0; i < n-1; ++i) {
        for (int j = 0; j < n-1; ++j) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    int k, p, q, r;

    int n = 1;
    cout << "Номер задачи для теста:" << endl;
    cin >> n;
    while (n != -1) {
        switch(n) {
            case 1: {
                cin >> k >> p >> q >> r;
                solveFirst(k, p, q, r);
                break;
            }
            case 2: {
                cin >> k >> p;
                solveSecond(k, p);
                break;
            }
            case 3: {
                cin >> k;
                solveThird(k);
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
