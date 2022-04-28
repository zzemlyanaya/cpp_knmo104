//
// Created by Evgeniya Zemlyanaya on 16.03.2022.
//

#include "SimpleList.h"

SimpleList::SimpleList() {
    head = nullptr;
    current = nullptr;
}


SimpleNode* SimpleList::getHead() { return this->head; }

bool SimpleList::is_empty() {
    return head == nullptr;
}

void SimpleList::add(SimpleNode* node) {
    if (this->is_empty()) {
        head = node;
        current = node;
    } else {
        current->next = node;
        current = node;
    }
}

std::ostream &operator<<(std::ostream &os, SimpleList* p) {
    if (p->is_empty()) {
        os << "Empty list";
        return os;
    }

    SimpleNode* cur = p->getHead();
    do {
        os << cur->value << " ";
        cur = cur->next;
    } while (cur != nullptr);

    return os;
}

