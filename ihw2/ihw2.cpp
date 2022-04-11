//
// Created by Evgeniya Zemlyanaya on 08.04.2022.
//

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

int main() {
    int N, M;
    cin >> N;

    int* a = new int[N];
    for (int i = 0; i < N; ++i) cin >> a[i];

    cin >> M;

    int n = (1 << (N - 1));
    int sum, b;

    for (b = 1; b < n; b++) {
        sum = a[0];

        for (int i = 0; i < N-1; i++) {
            if ((b >> i) & 1)
                sum += a[i + 1];
            else
                sum -= a[i + 1];
        }

        if (sum == M) {
            cout << a[0];
            for (int i = 0; i < N-1; i++) cout << (((b >> i) & 1) ? '+' : '-') << a[i + 1];

            cout << "=" << M << endl;
            break;
        }
    }

    if (b == n) cout << "No solution\n";

    return 0;
}