//
// Created by Evgeniya Zemlyanaya on 16.03.2022.
//

#include "List.h"

List::List() {
    head = nullptr;
    current = nullptr;
}


Node* List::getHead() { return this->head; }

bool List::is_empty() {
    return head == nullptr;
}

void List::add(Node* node) {
    if (this->is_empty()) {
        head = node;
        current = node;
    } else {
        current->next = node;
        current = node;
    }
}

std::ostream &operator<<(std::ostream &os, List* p) {
    if (p->is_empty()) {
        os << "Empty list";
        return os;
    }

    Node* cur = p->getHead();
    do {
        os << "\"" << cur->value << "\"" << " : " << cur->freq << std::endl;
        cur = cur->next;
    } while (cur != nullptr);

    return os;
}

