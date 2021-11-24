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
    cout << "Введите степени многочленов: " << endl;
    cin >> n;
    cout << "Введите многочлен: " << endl;

    int P[100]{0};

    for (int i = 0; i <= n; ++i) {
        cin >> P[i];
    }
    return 0;
}