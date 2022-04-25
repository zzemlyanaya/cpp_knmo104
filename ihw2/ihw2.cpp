//
// Created by zzemlyanaya on 17.11.2021.
//

#include <iostream>
#include <cmath>

using namespace std;


int check(int mask, int i) {
    return mask & (0x800000 >> (i & 31));
}

int main() {

    int N, M;
    cin >> N;

    int* a = new int[N];
    for (int i = 0; i < N; ++i) cin >> a[i];

    cin >> M;

    int n = (N >> 5), sum;
    int* mask = new int[n+1] {0};
    bool found = false, mask_is_complete = false;

    do {
        sum = a[0];

        for (int j = 1; j < N; ++j) {
            if (check(mask[j >> 5], j) == 0)
                sum += a[j];
            else
                sum -= a[j];
        }

        if (sum == M) {
            cout << a[0];
            for (int j = 1; j < N; j++)
                cout << ((check(mask[j >> 5], j) == 0) ? "+" : "-" ) << a[j];
            cout << "=" << M << endl;
            found = true;
        }

        for (int i = 0; i <= n; ++i) {
            if (i == 0) {
                mask[i] += 1;
                if (mask[i] == 0xffffff && mask[i+1] == 0xffffff)  {
                    mask_is_complete = true;
                    break;
                }
            }

            if (mask[i] == 0xffffff) {
                mask[i] = 0;
                mask[i+1] += 1;
            }
        }

    } while (!mask_is_complete && !found);

    if (!found) cout << "No solution!" << endl;

    return 0;
}

// 4 1 1 1 1 4
// 4 2 5 9 2 8
// 8 1 2 3 4 9 8 2 5 6
// 33 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 33
// 33 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 5 5