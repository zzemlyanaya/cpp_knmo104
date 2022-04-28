//
// Created by Evgeniya Zemlyanaya on 16.03.2022.
//

#include <fstream>
#include <iostream>
#include "SimpleNode.h"

class SimpleList {
    SimpleNode* head;
    SimpleNode* current;

public:
    SimpleList();

    SimpleNode* getHead();
    bool is_empty();
    void add(SimpleNode* node);

    friend std::ostream& operator<<(std::ostream& os, SimpleList* p);
};