//
// Created by Evgeniya Zemlyanaya on 16.03.2022.
//

#include "Dict.h"

Dict::Dict() {
    head = nullptr;
    current = nullptr;
}


Node* Dict::getHead() { return this->head; }

bool Dict::is_empty() {
    return head == nullptr;
}

void Dict::add(Node* node) {
    if (this->is_empty()) {
        head = node;
        current = node;
    } else {
        current->next = node;
        current = node;
    }
}

void Dict::addOrIncrement(const std::string& value) {
    if (is_empty()) {
        add(new Node(value));
    }
    else {
        Node* node = head;

        do {
            if (node->value == value) {
                node->freq += 1;
                break;
            }
            node = node->next;
        }
        while (node != nullptr);

        if (node == nullptr) add(new Node(value));
    }
}

void Dict::sort() {
    Node *prev1, *p1, *prev2, *p2, *temp;
    prev1 = p1 = head;

    while (p1->next) {
        prev2 = p2 = p1->next;
        while (p2) {
            if (compare(p1, p2)) {
                if (p1 == head) {
                    temp = p1->next;
                    p1->next = p2->next;
                    p2->next = temp;
                    prev2->next = p1;

                    temp = p1;
                    p1 = p2;
                    p2 = temp;

                    prev2 = p2;
                    p2 = p2->next;

                    head = p1;
                }
                else {
                    temp = p1->next;
                    p1->next = p2->next;
                    p2->next = temp;
                    prev2->next = p1;
                    prev1->next = p2;

                    temp = p1;
                    p1 = p2;
                    p2 = temp;

                    prev2 = p2;
                    p2 = p2->next;
                }
            }
            else {
                prev2 = p2;
                p2 = p2->next;
            }
        }

        prev1 = p1;
        p1 = p1->next;
    }
}

bool Dict::compare(Node *a, Node* b) {
    return a->value > b->value || a->value == b->value && a->freq >= b->freq;
}
std::ostream &operator<<(std::ostream &os, Dict* p) {
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
