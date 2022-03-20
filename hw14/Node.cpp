//
// Created by Evgeniya Zemlyanaya on 16.03.2022.
//

#include "Node.h"

Node::Node() {
    coeff = 0;
    deg = 0;
    next = nullptr;
}

Node::Node(int deg) {
    this->deg = deg;
    coeff = 1;
    next = nullptr;
}

Node::Node(int deg, int coeff) {
    this->deg = deg;
    this->coeff = coeff;
    next = nullptr;
}

Node::Node(Node *n) {
    this->deg = n->deg;
    this->coeff = n->coeff;
    this->next = n->next;
}



std::istream &operator>>(std::istream &is, Node *n) {
    is >> n->coeff >> n->deg;
    return is;
}

