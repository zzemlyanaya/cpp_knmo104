#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;


int main() {
    int N, k, a, b;
    cin >> N >> k;

    int n = 1 << N;
    int mask = (1 << k) - 1;
    while (mask < n) {
        for (int i = 0; i < N; ++i) {
            if ((1 & (mask >> i))) cout << i+1 << " ";
        }
        cout << endl;

        if (mask == 0) break;

        a = mask & -mask; // find rightmost 1 bit
        b = mask + a; // find carry bit
        mask = ((mask^b) >> 2)/a | b; // get block of 1 that begins at the least-significant bit
    }

    return 0;
}

// 000111 : a = 000001 / b = 001000 / mask = 001111 -> 000011 -> 000011 -> 001011
// 001011 : a = 000001 / b = 001100 / mask = 000101 -> 000001 -> 000001 -> 001101
// 001101: a = 000001 / b = 001110 / mask = 000010 -> 000110 -> 000110 -> 001110
