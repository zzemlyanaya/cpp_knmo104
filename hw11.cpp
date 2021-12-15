//
// Created by zzemlyanaya on 15.12.2021.
//

#include <windows.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

ifstream inputFile("input.txt");
ofstream outputFile("output.txt");

int** read_matrix(int&n, int& m) {
    inputFile >> n;
    inputFile >> m;

    int** a = new int*[n];

    for (int i = 0; i < n; ++i) {
        a[i] = new int[m];
        for (int j = 0; j < m; ++j) {
            inputFile >> a[i][j];
        }
    }
    return a;
}

void print_matrix(int** a, int n, int m) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            outputFile << a[i][j] << ' ';
        }
        outputFile << endl;
    }
}

void solveFirst() {
    int k, n, m;
    inputFile >> k;
    int i = 0;

    int mmax = 0, max_ind, cur;

    while(k-i) {
        int** a = read_matrix(n, m);
        cur = 0;
        for (int j = 0; j < n; ++j) {
            cur += a[j][j];
        }
        if (cur > mmax) {
            mmax = cur;
            max_ind = i+1;
        }
        i++;
    }

    outputFile << "Максимальный след " << mmax << " у матрицы #" << max_ind << endl;
}

void solveSecond(int n) {
    bool color;
    for (int i = n; i > 0; i--) {
        color = i%2 == 0; //нечётные -> чёрные -> 0
        for (int j = 0; j < n; ++j) {
            outputFile << color << " ";
            color = !color;
        }
        outputFile << endl;
    }
}

void solveThird() {
    int n, m;
    int **a = read_matrix(n, m);
    int k, l;
    inputFile >> k >> l;
    k--; l--;

    for (int i  = k; i < n-1; i++) {
        for (int j = 0; j < m; j++)
            a[i][j] = a[i + 1][j];
    }

    for (int i = 0; i < n; i++) {
        for (int j = l; j < m - 1; j++)
            a[i][j] = a[i][j + 1];
    }

    print_matrix(a, n-1, m-1);
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
                solveFirst();
                break;
            }
            case 2: {
                cin >> k;
                solveSecond(k);
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
