//
// Created by Evgeniya Zemlyanaya on 16.03.2022.
//

#include "SimpleList.h"

struct ListNode {
    SimpleList* value;
    ListNode* next;

    ListNode();
    ListNode(SimpleList* list);
};
