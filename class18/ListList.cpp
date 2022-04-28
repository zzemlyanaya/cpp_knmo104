//
// Created by Evgeniya Zemlyanaya on 16.03.2022.
//

#include "ListList.h"

ListList::ListList() {
    head = nullptr;
    current = nullptr;
}


ListNode* ListList::getHead() { return this->head; }

bool ListList::is_empty() {
    return head == nullptr;
}

void ListList::add(ListNode* node) {
    if (this->is_empty()) {
        head = node;
        current = node;
    } else {
        current->next = node;
        current = node;
    }
}

std::ostream &operator<<(std::ostream &os, ListList* p) {
    if (p->is_empty()) {
        os << "Empty list";
        return os;
    }

    int count = 1;
    ListNode* cur = p->getHead();
    do {
        os << count << " -> " << cur->value << std::endl;
        cur = cur->next;
        count++;
    } while (cur != nullptr);

    return os;
}

