//
// Created by Evgeniya Zemlyanaya on 16.03.2022.
//

#include "ListNode.h"

ListNode::ListNode() {
    value = new SimpleList();
    next = nullptr;
}

ListNode::ListNode(SimpleList* list) {
    this->value = list;
    next = nullptr;
}

