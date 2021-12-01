#include <windows.h>
#include <iostream>
#include <string>

using namespace std;

void doMagic(string s) {

}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    int n;
    cout << "Введите порядок матрицы: " << endl;
    cin >> n;
    cout << "Введите матрицу: " << endl;

    int a[100][100];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }

    bool upper = true;
    for (int i = 0; i < n && upper; ++i) {
        for (int j = 0; j < i && (upper = (0 == a[i][j])); ++j);
    }
    cout << upper;
    return 0;
}