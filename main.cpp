#include <windows.h>
#include <iostream>

using namespace std;

int p(int x, int a) {
    if (a == 0) x = 1;
    while (--a > 0) x *= x;
    return x;
}

void doMagic(int n) {
    int ans = 0;
    int len = 0; int i, j;

    for (i=n; i > 0; i=i/10) len++;
    len--;

    if (n == 0) ans = 1;

    for (i=len; i >= 0; i--) {
        int k1 = n/p(10, i) % max(10, p(10, i-1));
        if (i == 0) k1 = n%10;

        if (k1%2 == 0) ans++;
        k1 = k1*p(10, i);

        for (j=i; j > 0; j--) {
            int k2 = n%p(10, j);
            if ((k1+k2)%2 == 0) ans++;
        }
    }

    cout << "Чётных чисел: " << ans << endl;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);

    int n = 0;
    cin >> n;
    while (n != -1) {
        doMagic(n);
        cin >> n;
    }

    return 0;
}