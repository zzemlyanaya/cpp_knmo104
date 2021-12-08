#include <windows.h>
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

bool is_ok(int num) {
    int res = 0, p = 0;
    int n = num;
    while (n != 0) {
        n /= 10;
        ++p;
    }
    n = num;
    while (n != 0) {
        res += floor(pow(n % 10, p));
        n /= 10;
    }

    return res == num;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    int n, m;
    cout << "Введите размерность матрицы: " << endl;
    cin >> n >> m;
    cout << "Введите матрицу: " << endl;

    int a[100][100];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }

    int res[100]{0};
    int count = 0;

    for (int i = 0; i < n; ++i) {
        bool notFound = true;
        // нам нужны только номера строк, так что при нахождении нет смысла проверять остальное
        for (int j = 0; j < m && notFound; ++j){
            if (is_ok(a[i][j])) {
                // нужно же было номера строк вывести, да?
                // res[count] = a[i][j]; чтобы выводить сами числа Армстронга
                notFound = !notFound;
                res[count] = i+1;
                count++;
            }
        }
    }

    for (int i = 0; i < count; ++i) {
        cout << res[i] << " ";
    }
    return 0;
}