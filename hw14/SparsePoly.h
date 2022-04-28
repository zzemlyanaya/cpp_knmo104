//
// Created by zzemlyanaya on 20.03.2022.
//

#include "Node.h"

class SparsePoly {
    SimpleNode* head;
    SimpleNode* current;

    void sparse();

public:
    SparsePoly();

    SimpleNode* getHead();
    bool is_zero();
    void add(SimpleNode* node);

    friend std::ostream& operator<<(std::ostream& os, SparsePoly* p);
    SparsePoly operator+(SparsePoly rgh);
    SparsePoly operator*(SparsePoly rgh);
};

