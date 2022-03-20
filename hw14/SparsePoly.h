//
// Created by zzemlyanaya on 20.03.2022.
//

#include "Node.h"

class SparsePoly {
    Node* head;
    Node* current;

    void sparse();

public:
    SparsePoly();

    Node* getHead();
    bool is_zero();
    void add(Node* node);

    friend std::ostream& operator<<(std::ostream& os, SparsePoly* p);
    SparsePoly operator+(SparsePoly rgh);
    SparsePoly operator*(SparsePoly rgh);
};

