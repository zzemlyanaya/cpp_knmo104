//
// Created by Evgeniya Zemlyanaya on 16.03.2022.
//

#include "Node.h"

Node::Node() {
    value = -1;
    freq = 0;
    next = nullptr;
}

Node::Node(int value) {
    this->value = value;
    freq = 1;
    next = nullptr;
}

