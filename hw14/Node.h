//
// Created by Evgeniya Zemlyanaya on 16.03.2022.
//

#include <fstream>
#include <iostream>

struct Node {
    int coeff;
    int deg;
    Node* next;

    Node();
    Node(int deg);
    Node(int deg, int coeff);
    Node(Node* n);

    friend std::istream& operator>>(std::istream& is, Node* n);
};
