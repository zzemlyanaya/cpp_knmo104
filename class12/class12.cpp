//
// Created by zzemlyanaya on 02.03.2022.
//

#include "interactor.h"
#include "windows.h"

using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    if (inputFile.fail()) return -1;

    int size;
    Resort* resorts = read(inputFile, size);
    doMagic(size, resorts);
    write(outputFile, size, resorts);
}

