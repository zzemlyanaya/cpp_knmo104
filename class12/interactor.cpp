//
// Created by zzemlyanaya on 02.03.2022.
//

#include "interactor.h"

Resort* read(ifstream& inputFile, int& size) {
    inputFile >> size;
    Resort* resorts = new Resort[size];
    Resort resort;
    int ind = 0;
    for (int i = 0; i < size; ++i) {
        inputFile >> resort.name >> resort.region >> resort.distance >> resort.height;
        if (resort.distance <= 100)
            resorts[ind++] = resort;
    }
    size = ind;
    return resorts;
}

void write(ofstream& outputFile, int& size, Resort* resorts) {
    for (int i = 0; i < size; ++i) {
        outputFile << resorts[i].name << " " << resorts[i].region << " "
                    << resorts[i].distance << " " << resorts[i].height << endl;
    }
}

bool is_less(Resort a, Resort b) {
    if (a.height != b.height) return a.height < b.height;
    if (a.region != b.region) return a.region < b.region;
    if (a.distance != b.distance) return a.distance < b.distance;
    return a.name <= b.name;
}

void swap(Resort* a, Resort* b) {
    Resort t = *a;
    *a = *b;
    *b = t;
}

void quickSort(Resort* arr, int left, int right) {
    int i = left, j = right;
    Resort mid = arr[(left + right) / 2];

    while (i <= j) {
        while (is_less(arr[i], mid)) i++;
        while (!is_less(arr[j], mid)) j--;

        if (i <= j) {
            swap(&arr[i], &arr[j]);
            i++;
            j--;
        }
    }
    if (left < j) quickSort(arr, left, j);
    if (i < right) quickSort(arr, i, right);
}

void doMagic(int& size, Resort* resorts) {
    quickSort(resorts, 0, size);
}
