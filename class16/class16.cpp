//
// Created by Evgeniya Zemlyanaya on 13.04.2022.
//

#include <iostream>
#include <cmath>

using namespace std;

// 0 10 0.0001 (10-x)

double fun(double x) {
    return (10-x);
}

double simpson(double a, double b, double e, double (*f)(double x))
{
    double x, h;
    double f_sum, new_sum, cur_sum, prev_sum;

    cur_sum = 0;
    h = b - a;
    f_sum = f(a) + f(b);

    do {
        prev_sum = cur_sum;
        h /= 2;
        new_sum = 0;
        x = a + h;

        do {
            new_sum += 2*f(x);
            x += 2*h;
        } while (x < b);

        f_sum += new_sum;
        cur_sum = (f_sum + new_sum) * h/3;
    } while (fabs(prev_sum - cur_sum) > e);

    return cur_sum;
}

double simpson_integral(double a, double b, double eps, double (*f)(double x)) {
    double h = b - a;
    double sum_prev = 0, sum_cur = (h/6) * (f(a) + f(b));
    double f_sums = f(a) + f(b);
    double coeff1;

    while (fabs(sum_cur-sum_prev) > eps) {
        sum_prev = sum_cur;
        coeff1 = 4;

        for (double x = a + h / 2; x < b; x += h)  f_sums += (coeff1 = 6-coeff1)*f(x);

        sum_cur = (h/6)*f_sums;
        h /= 2;
    }

    return sum_cur;
}

int main() {

    double a, b, eps;
    cin >> a >> b >> eps;

    double (*f)(double);
    f = &fun;

    cout << simpson_integral(a, b, eps, f) << endl;
    cout << simpson(a, b, eps, f) << endl;

}
