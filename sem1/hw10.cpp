//
// Created by zzemlyanaya on 08.12.2021.
//

#include <windows.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void solveFirst(int n) {
    int** a = new int*[n];
    for (int i = 0; i < n; ++i) {
        a[i] = new int[n];
        for (int j = 0; j < n; ++j) {
            if (i != j) a[i][j] = 0;
            else a[i][j] = 1;
        }
        cout << endl;
    }
}

int** read_matrix(int&n, int& m) {
    ifstream inputFile("input.txt");

    if(!inputFile.good()) {
        cout << "Could not read the file" << endl;
        return 0;
    }

    inputFile >> n;
    inputFile >> m;

    int** a = new int*[n];

    for (int i = 0; i < n; ++i) {
        a[i] = new int[m];
        for (int j = 0; j < m; ++j) {
            inputFile >> a[i][j];
        }
    }

    inputFile.close();
    return a;
}

void print_matrix(int** a, int n, int m) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
}

void solveSecond() {
    int n, m;
    int **a = read_matrix(n, m);

    int max_d = 0;
    int d_ind = 0;
    int mmin, mmax, min_ind, max_ind;

    for (int i = 0; i < n; ++i) {
        mmin = INT_MAX, mmax = INT_MIN;
        min_ind = 0, max_ind = 0;
        for (int j = 0; j < m; ++j) {
            if (a[i][j] < mmin) {
                mmin = a[i][j];
                min_ind = j;
            }
            if (a[i][j] > mmax) {
                mmax = a[i][j];
                max_ind = j;
            }
        }
        if (abs(max_ind-min_ind) > max_d) {
            max_d = abs(max_ind-min_ind);
            d_ind = i+1;
        }
    }

    cout << d_ind << endl;
}

void solveThird() {
    int n, m;
    int **a = read_matrix(n, m);

    int* max_row = new int[n];
    int* min_col = new int[m];

    for (int i = 0; i < n; ++i) {
        int mmax = INT_MIN;
        for (int j = 0; j < m; ++j) {
            if (a[i][j] > mmax) {
                mmax = a[i][j];
                max_row[i] = j;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        int mmin = INT_MAX;
        for (int j = 0; j < m; ++j) {
            if (a[j][i] < mmin) {
                mmin = a[j][i];
                min_col[i] = j;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        if (i == min_col[max_row[i]]) cout << i + 1 << " " << max_row[i] + 1 << endl;
    }
}


int main() {
    SetConsoleOutputCP(CP_UTF8);
    int k;
    string s;

    int n = 1;
    cout << "Номер задачи для теста:" << endl;
    cin >> n;
    while (n != -1) {
        switch(n) {
            case 1: {
                cin >> k;
                solveFirst(k);
                break;
            }
            case 2: {
                solveSecond();
                break;
            }
            case 3: {
                solveThird();
                break;
            }
//            case 4: {
//                cin >> s >> k;
//                solveFourth(s, k);
//                break;
//            }
            default:
                break;
        }
        cout << "Номер задачи для теста:" << endl;
        cin >> n;
    }

    return 0;
}
