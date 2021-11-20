#include <windows.h>
#include <iostream>
#include <string>

using namespace std;

void doMagic(string s) {

}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    int n, m;
    cout << "Введите степени многочленов: " << endl;
    cin >> n >> m;
    cout << "Введите многочлены через enter: " << endl;

    int P[100]{0}, Q[100]{0};
    int R[201]{0};

    for (int i = 0; i <= n; ++i) {
        cin >> P[i];
    }
    for (int i = 0; i <= m; ++i) {
        cin >> Q[i];
    }

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            R[i + j] += (P[i]*Q[j]);
        }
    }
    for(int i = 0; i <= n+m; i++)
        cout << R[i] << " ";
    return 0;

    /** tests:
     1 2 / 1 6 / 3 -5 2 -> 3 13 -28 12
     1 2 / 3 5 / 5 -2 8 -> 15 19 14 40
     3 3 / 1 1 1 1 / 1 1 0 1 -> 1 2 2 3 2 1 1
     ***/
}