//
// Created by zzemlyanaya on 20.03.2022.
//

#include "SparsePoly.h"
#include "windows.h"

using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);

    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    if (inputFile.fail()) return -1;

    SparsePoly p1 = SparsePoly();
    SparsePoly p2 = SparsePoly();
    int p1_deg, p2_deg;
    Node* t = new Node();

    inputFile >> p1_deg;
    while (p1_deg--) {
        inputFile >> t;
        p1.add(new Node(t));
    }
    inputFile >> p2_deg;
    while (p2_deg--) {
        inputFile >> t;
        p2.add(new Node(t));
    }

    outputFile << "p1: " << &p1 << "p2: " << &p2;

    SparsePoly sum = p1 + p2;
    SparsePoly mul = p1 * p2;

    outputFile << "p1 + p2: " << &sum;
    outputFile << "p1 * p2: " << &mul;

    return 0;
}