//
// Created by Evgeniya Zemlyanaya on 16.03.2022.
//

#include "Node.h"

Node::Node() {
    value = "";
    freq = 0;
    next = nullptr;
}

Node::Node(std::string value) {
    this->value = value;
    freq = 1;
    next = nullptr;
}

