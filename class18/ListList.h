//
// Created by Evgeniya Zemlyanaya on 16.03.2022.
//

#include <fstream>
#include <iostream>
#include "ListNode.h"

class ListList {
    ListNode* head;
    ListNode* current;

public:
    ListList();

    ListNode* getHead();
    bool is_empty();
    void add(ListNode* node);

    friend std::ostream& operator<<(std::ostream& os, ListList* p);
};