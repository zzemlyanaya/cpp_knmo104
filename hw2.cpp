//
// Created by zzemlyanaya on 06.10.2021.
//

#include <windows.h>
#include <iostream>

using namespace std;

void solveFirst(double x, double y, double a) {
    double side = a/2;
    if (abs(x) < side && abs(y) < side){
        cout << "Точка строго внутри" << endl;
    }
    else if(abs(x) == side || abs(y) == side){
        cout << "Точка на границе" << endl;
    }
    else {
        cout << "Точка вне прямоугольника" << endl;
    }

}

bool is_simple(int n) {
    if (n == 1) return false;
    if (n%2 == 0) return false;
    int i;
    for (i = 3; (i*i <= n) && (n%i != 0); i+=2);
    if (i*i > n) return true;

    return false;
}

void solveSecond(int a, int b) {
    if (is_simple(a) && is_simple(b) && abs(a-b) == 2){
        cout << "Это числа-близнецы" << endl;
    }
    else {
        cout << "Это не числа-близнецы" << endl;
    }
}

int dels_sum(int n) {
    int sum = 1;
    for (int i = 2; i < n; i++) {
        if (n%i == 0) sum += i;
    }

    return sum;
}

void solveThird(int a, int b) {
    if (dels_sum(a) == b && dels_sum(b) == a) {
        cout << "Это дружественные числа" << endl;
    }
    else {
        cout << "Это не дружественные числа" << endl;
    }
}

bool can_part(int k, int n) {
    int i = 1; int take = 0;
    bool can = false;
    do {
        k--;
        if (k%n == 0) {
            can = true;
            take = k/n;
            k -= take;
        }
        else {
            can = false;
        }
        i++;
    } while (i <= n && can);

    return can;
}

void solveFourth(int n) {
    int i = 0;
    while(!can_part(++i, n));
    cout << "Наименьшее возможное количество рыб: " << i << endl;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    double x, y, a; // point p(x,y) and length of the square a

    int n1, n2, k;

    int n = 1;
    cout << "Номер задачи для теста:" << endl;
    cin >> n;
    while (n != -1) {
        switch(n) {
            case 1: {
                cin >> x >> y >> a;
                solveFirst(x, y, a);
                break;
            }
            case 2: {
                cin >> n1 >> n2;
                solveSecond(n1, n2);
                break;
            }
            case 3: {
                cin >> n1 >> n2;
                solveThird(n1, n2);
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