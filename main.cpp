#include <windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

ifstream input("input.txt");
ofstream output("output.txt");

struct Vec {
    int* coords;
    int by_y;

    int inner_product(int m, Vec a) {
        int s = 0;
        for (int i = 0; i < m; ++i) s += coords[i]*a.coords[i];
        return s;
    }
};

void merge_sort(Vec* list, int n) {
    if (n == 1) return;

    int halfLen = n/2 + n%2;

    merge_sort(list, halfLen);
    merge_sort(list + halfLen, halfLen);

    for (int i = 0; i < halfLen; ++i) {
        if (list[i].by_y > list[i + halfLen].by_y) {
            Vec temp = list[i];
            list[i] = list[i + halfLen];
            list[i + halfLen] = temp;
        }
    }
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    int n, m;

    // input format:
    // m
    // y_1, ..., y_m
    // n
    // s_1_1, ..., s_1_m
    // ...
    // s_n_1, ..., s_n_m

    input >> m;
    Vec y;
    int* y_coords = new int[m];
    for (int i = 0; i < m; ++i) {
        input >> y_coords[i];
    }
    y.coords = y_coords;

    input >> n;
    Vec* vectors = new Vec[n];
    int count = 0;
    bool ok = true;

    for (int i = 0; i < n; ++i) {
        int* coords = new int[m];
        input >> coords[0];
        ok = true;

        for (int j = 1; j < m && ok; ++j) {
            input >> coords[j];
            if (coords[j] < coords[j-1]) ok = false;
        }

        if (ok) {
            Vec v;
            v.coords = coords;
            v.by_y = v.inner_product(m, y);
            vectors[count++] = v;
        }
    }

    merge_sort(vectors, count);
    for (int i = 0; i < count; ++i) {
        cout << vectors[i].by_y << endl;
    }
    return 0;
}