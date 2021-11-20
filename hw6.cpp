//
// Created by zzemlyanaya on 10.11.2021.
//

#include <windows.h>
#include <iostream>
#include <string>

using namespace std;

void solveFirst(int n) {
    int a[100]; int i = 0;

    while (i++ < n) cin >> a[i];

    for(i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (a[i] == a[j]) {
                cout << "Есть совпадающие элементы" << endl;
                return;
            }
        }
    }

    cout << "Все элементы уникальны" << endl;
}

// MMM = 3000
// IV = 4
// MCDLIXIV = 1463
void solveSecond(int n) {
    int arabs[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    string romes[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    string res = "";
    for (int i = 0; i < 13; i += 1) {
        while (n >= arabs[i]){
            n -= arabs[i];
            res += romes[i];
        }
    }
    cout << res << endl;
}

void solveThird(string ar1, string ar2) {
    int n = ar1.length();
    int m = ar2.length();
    if (n != m) {
        cout << "Это не точные зеркальные копии" << endl;
        return;
    }

    int i = 0;
    while (ar1[i] == ar2[m-i-1] && i <= m-i-1) i++;
    cout << "Это ";
    if (i < m-i-1) cout << "не ";
    cout << "точные зеркальные близнецы" << endl;
}


int main() {
    SetConsoleOutputCP(CP_UTF8);
    int k;
    string s1, s2;

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
                cin.get();
                getline(cin, s1);
                getline(cin, s2);
                solveThird(s1, s2);
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
