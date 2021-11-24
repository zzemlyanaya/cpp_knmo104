//
// Created by zzemlyanaya on 24.11.2021.
//

#include <iostream>
#include <cmath>

using namespace std;

// a: n x k
// b: k x r
// c: n x r
void mul(int** a, int** b, int** c, int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            c[i][j] = 0;
            for(int k =0; k < n; k++) {
                c[i][j] += a[i][k]*b[k][j];
            }
        }
    }
}

int main() {

}
