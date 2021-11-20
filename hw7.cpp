//
// Created by zzemlyanaya on 20.11.2021.
//
#include <windows.h>
#include <iostream>
#include <string>
#include <cmath>

#define PI 3.14159265

using namespace std;

void sort(double* a, double* b, double* c) {
    if(*a>*b) swap(*a,*b);
    if(*a>*c) swap(*a,*c);
    if(*b>*c) swap(*b,*c);
}

double dist(double a[], double b[]){
    return (a[0]-b[0])*(a[0]-b[0])+(a[1]-b[1])*(a[1]-b[1]);
}

void solveFirst(int n) {
    double points[100][2];
    for (int i = 0; i < n; i++) {
        cin >> points[i][0] >> points[i][1];
    }

    double mangle = 0, ma, mb, mc;
    for(int p1 = 0; p1 < n; p1++) {
        for(int p2 = p1 + 1; p2 < n; p2++) {
            for(int p3 = p2 + 1; p3 < n; p3++) {
                double a = dist(points[p1], points[p2]);
                double b = dist(points[p2], points[p3]);
                double c = dist(points[p1], points[p3]);
                sort(&a, &b, &c);
                double angle = acos((a+b-c)/(2*sqrt(a)*sqrt(b)))* 180.0 / PI;
                if (c > a+b && angle > mangle) {
                    mangle = angle;
                    ma = sqrt(a); mb = sqrt(b); mc = sqrt(c);
                }
            }
        }
    }

    if (mangle == 0) {
        cout << "Не найден тупоугольный треугольник" << endl;
    } else {
        cout << "Наибольший треугольник со сторонами " << ma << " " << mb << " " << mc
             << " и углом " << mangle << endl;
    }
}

void solveSecond() {
    cout << "Введите длины массивов и затем сами массивы" << endl;
    int n, m;
    cin >> n >> m;
    int a[100], b[100];
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < m; ++i) cin >> b[i];

    int ia, ib;
    for(ia = ib = 0; ia < n && ib < m; ib++) {
        if (a[ia] == b[ib]) ia++;
    }
    if (ia > 0) cout << "Да" << endl;
    else cout << "Нет" << endl;
}

void solveThird(int n) {
    for (int line = 1; line <= n; line++) {
        int C = 1;
        for (int i = 1; i <= line; i++){
            if (line == n) cout << C << " ";
            C = C * (line - i) / i;
        }
    }
    cout << endl;
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
                solveSecond();
                break;
            }
            case 3: {
                cin >> k;
                solveThird(k);
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
