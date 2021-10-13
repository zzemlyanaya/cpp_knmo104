//
// Created by zzemlyanaya on 13.10.2021.
//

#include <windows.h>
#include <iostream>
#include <sstream>

using namespace std;

void solveFirst(int n) {
    int current = n;
    for(; current; current/=10) {
        int k = current%10;
        if (k != 0 && n%k == 0) break;
    }
    cout << "Число " << n;
    if (current == 0) cout << " не";
    cout << " делится на свои цифры" << endl;
}

void solveSecond(int n) {
    int mmax = 0;
    for(int i=9; i >= 0; i--){
        int current = n;
        for(; current; current/=10) {
            if (current % 10 == i)
                mmax = mmax*10 + i;
        }
    }
    cout << mmax << endl;
}

int p(int x, int a) {
    if (a == 0) x = 1;
    while (--a > 0) x *= x;
    return x;
}

void solveThird(int n) {
    int cur = 1, prev = 1, temp, len=2;
    int r = 1;
    int ans = 1;
    for (int i = 2; i < n && len != n; i++) {
        temp = cur;
        cur += prev;
        prev = temp;

        if (cur >= p(10, r)) r++;
        len += r;

        //нельзя писать len--, т.к. это будет менять len даже если мы не заходим в цикл
        while (len > n) {
            cur /= 10;
            len--;
        }

        if (len == n) ans = cur%10;
    }
    cout << ans << endl;
}

void solveFourth(int n) {
    int sum = 1;
    for (int i = 2; i < n; i++) {
        if (n%i == 0) sum += i;
    }
    cout << "Это";
    if (sum != n) cout << " не";
    cout << " совершенное число" << endl;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    int k;

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
                cin >> k;
                solveSecond(k);
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