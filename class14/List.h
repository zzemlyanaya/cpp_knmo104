//
// Created by Evgeniya Zemlyanaya on 16.03.2022.
//

#include <fstream>
#include <iostream>
#include "Node.h"

class List {
    Node* head;
    Node* current;

public:
    List();

    Node* getHead();
    bool is_empty();
    void add(Node* node);

    friend std::ostream& operator<<(std::ostream& os, List* p);
};