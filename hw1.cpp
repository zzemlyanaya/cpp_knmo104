//
// Created by zzemlyanaya on 05.10.2021.
//

#include <windows.h>
#include <iostream>

using namespace std;

void solveFirst(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4) {
    double left = max(x1, x3);
    double top = min(y2, y4);
    double right = min(x2, x4);
    double bottom = max(y1, y3);

    double width = right - left;
    double height = top - bottom;

    double ans;

    if (width < 0 || height < 0) {
        cout << "Нет точек пересечения" << endl;
        ans = 0;
    }
    else {
        cout << "Прямоугольники пересекаются" << endl;
        ans = width * height;
    }
    cout << "Площадь пересечения: " << ans << endl;
}

double square(double a) { return a*a; }

void solveSecond(double x, double y, double xa, double ya, double xb, double yb) {
    double ans;
    double interval_len = square(xb-xa) + square(yb-ya);
    // косое произведение**2/длина отрезка
    double s = square((xa-x)*(yb-y)-(xb-x)*(ya-y))/interval_len;
    // скалярное произведение векторов (ba, bp) >= 0 и векторов (ab, ap) >= 0
    if ((xb-xa)*(x-xa) + (yb-ya)*(y-ya) >= 0 && (xa-xb)*(x-xb) + (ya-yb)*(y-yb) >=0)
        ans = sqrt(s);
    else {
        double ap = sqrt(square(xa-x) +square(ya-y));
        double bp = sqrt(square(xb-x) + square(yb-y));
        ans = min(ap, bp);
    }

    cout << "Расстояние: " << ans << endl;

}

void solveThird(int day, int month, int year) {
    int oneIfVis = 0;
    if ((year%400 == 0) || (year%4 == 0) && (year%100 != 0))
        oneIfVis = 1;
    int months[12] = { 31, 27+oneIfVis, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int ans = day;

    for (int i = 0; i < month-1; i++)
        ans += months[i];

    cout << "Прошло " << ans << " д." << endl;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    double x1, y1, x2, y2; // left-bottom & right-top of the 1st rectangle
    double x3, y3, x4, y4; // same for the 2nd one

    double x, y, xa, ya, xb, yb; // point p(x,y) and interval [a;b]

    int day, month, year;

    int n = 1;
    cout << "Номер задачи для теста:" << endl;
    cin >> n;
    while (n != -1) {
        switch(n) {
            case 1: {
                cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
                solveFirst(x1, y1, x2, y2, x3, y3, x4, y4);
                break;
            }
            case 2: {
                cin >> x >> y >> xa >> ya >> xb >> yb;
                solveSecond(x, y, xa, ya, xb, yb);
                break;
            }
            case 3: {
                cin >> day >> month >> year;
                solveThird(day, month, year);
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
