//
// Created by zzemlyanaya on 17.11.2021.
//

#include <iostream>
#include <cmath>

using namespace std;

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void quickSort(int* arr, int left, int right) {
    int i = left, j = right;
    int mid = arr[(left + right) / 2];

    while (i <= j) {
        while (arr[i] < mid) i++;
        while (arr[j] > mid) j--;

        if (i <= j) {
            swap(&arr[i], &arr[j]);
            i++;
            j--;
        }
    }
    if (left < j) quickSort(arr, left, j);
    if (i < right) quickSort(arr, i, right);
}