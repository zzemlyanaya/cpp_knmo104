//
// Created by Evgeniya Zemlyanaya on 04.05.2022.
//

#include <iostream>

using namespace std;

int main() {

    int V, res = 0, count;
    cin >> V;

    int** matrix = new int*[V];
    for (int i = 0; i < V; ++i) {
        matrix[i] = new int[V];
        count = 0;
        for (int j = 0; j < V; ++j) {
            cin >> matrix[i][j];
            if (matrix[i][j] == 1) count++;
        }
        if (count == 0) res++;
    }

    cout << res;

    return 0;
}
