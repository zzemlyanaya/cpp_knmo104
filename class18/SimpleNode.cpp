//
// Created by Evgeniya Zemlyanaya on 16.03.2022.
//

#include "SimpleNode.h"

SimpleNode::SimpleNode() {
    value = -1;
    next = nullptr;
}

SimpleNode::SimpleNode(int value) {
    this->value = value;
    next = nullptr;
}

