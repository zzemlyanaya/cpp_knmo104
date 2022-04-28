//
// Created by Evgeniya Zemlyanaya on 16.03.2022.
//

#include "Node.h"

SimpleNode::SimpleNode() {
    coeff = 0;
    deg = 0;
    next = nullptr;
}

SimpleNode::SimpleNode(int deg) {
    this->deg = deg;
    coeff = 1;
    next = nullptr;
}

SimpleNode::SimpleNode(int deg, int coeff) {
    this->deg = deg;
    this->coeff = coeff;
    next = nullptr;
}

SimpleNode::SimpleNode(SimpleNode *n) {
    this->deg = n->deg;
    this->coeff = n->coeff;
    this->next = n->next;
}



std::istream &operator>>(std::istream &is, SimpleNode *n) {
    is >> n->coeff >> n->deg;
    return is;
}

