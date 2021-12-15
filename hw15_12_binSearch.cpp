#include <windows.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//int binSearch()...
bool binSearch(int* a, int n, int e) {
    int fst = 0, lst = n-1;
    int current;
    while (fst <= lst) {
        current = (fst+lst)/2;
        if (a[current] == e) return true; //return current;
        if (a[current] < e) {
            fst = current+1;
        }
        else {
            lst = current-1;
        }
    }

    return false; //return -1;
}

// int binSearch2()...
bool binSearch2(int* a, int n, int e) {
    if (n == 1) return a[0] == e; // ? 0 : -1;

    int current = n/2;
    if (a[current] == e) return true; // return current;
    if(a[current] < e) return binSearch2(a+current, n-current, e); //+current;
    if(a[current] > e) return binSearch2(a, current, e);
}

int main() {
    int n, e;
    cin >> n;
    int* array = new int[n];
    for (int i = 0; i < n; ++i) {
        cin >> array[i];
    }
    cin >> e;

    cout << binSearch2(array, n, e);

    return 0;
}