//
// Created by Evgeniya Zemlyanaya on 16.03.2022.
//

#include <fstream>
#include <iostream>
#include "Node.h"

class Dict {
    Node* head;
    Node* current;

    bool compare(Node* a, Node* b);

public:
    Dict();

    Node* getHead();
    bool is_empty();
    void add(Node* node);
    void addOrIncrement(const std::string& value);
    void sort();

    friend std::ostream& operator<<(std::ostream& os, Dict* p);
};