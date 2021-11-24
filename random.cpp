//
// Created by zzemlyanaya on 17.11.2021.
//

#include <iostream>
#include <cmath>

using namespace std;

int queens[100];
int res = 0;

void solve(int n, int bound) {
    if (n >= bound) {
        res++;
        return;
    }

    for(int row = 0, column; row < bound; row++){
        for(column = 0; column < n; column++) {
            if (queens[column] == row || abs(queens[column] - row) == n - column)
                break;
        }
        if(column == n) {
            queens[n] = row;
            solve(n + 1, bound);
        }
    }
}


int main()
{
    int bound;
    cin >> bound;
    for(int i = 0; i < bound; i++) queens[i] = 0;
    solve(0, bound);
    cout << res;
}