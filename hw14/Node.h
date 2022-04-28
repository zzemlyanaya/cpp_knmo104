//
// Created by Evgeniya Zemlyanaya on 16.03.2022.
//

#include <fstream>
#include <iostream>

struct SimpleNode {
    int coeff;
    int deg;
    SimpleNode* next;

    SimpleNode();
    SimpleNode(int deg);
    SimpleNode(int deg, int coeff);
    SimpleNode(SimpleNode* n);

    friend std::istream& operator>>(std::istream& is, SimpleNode* n);
};
