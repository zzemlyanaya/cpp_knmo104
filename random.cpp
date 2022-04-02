//
// Created by zzemlyanaya on 17.11.2021.
//

#include <iostream>
#include <cmath>

using namespace std;

void sieve(int N) {
    int n = N/32, k = 0;
    int* ar = new int[n + 1];

    for (int i = 0; i <= n; ++i) ar[i] = 0xffff; // 65535

    for (int i = 2; i <= N; i++) {
        if (ar[i / 32] & (0x8000 >> i % 32)) { // 32768
            cout << i << " ";

            for (int j= 2 * i; j <= N; j += i) ar[j / 32] &= ~0x8000 >> j % 32;
        }
    }

    cout << endl;
}

int main() {

    int N;
    cout << "Input natural number to sieve or -1 to stop:\n";
    while (cin >> N && N != -1) {
        sieve(N);
    }

    return 0;
}
