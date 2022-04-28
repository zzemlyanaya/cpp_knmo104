//
// Created by zzemlyanaya on 20.03.2022.
//

#include "SparsePoly.h"

SparsePoly::SparsePoly() {
    head = nullptr;
    current = nullptr;
}

SimpleNode *SparsePoly::getHead() { return this->head; }

bool SparsePoly::is_zero() {
    return head == nullptr;
}

void SparsePoly::add(SimpleNode *node) {
    if (this->is_zero()) {
        head = node;
        current = node;
    } else {
        current->next = node;
        current = node;
    }
}

std::ostream &operator<<(std::ostream &os, SparsePoly *p) {
    if (p->is_zero()) {
        os << "Zero polynome";
        return os;
    }

    SimpleNode* cur = p->getHead();
    do {
        if (cur->coeff != 0) {
            if (cur->coeff != 1 || cur->deg == 0) os << cur->coeff;
            if (cur->deg != 0) os << "x";
            if (cur->deg > 1) os << "^" << cur->deg << " "; else os << " ";
        }
        cur = cur->next;
    } while (cur != nullptr);

    os << std::endl;
    return os;
}

SparsePoly SparsePoly::operator+(SparsePoly rgh) {
    if (this->is_zero()) return rgh;
    if (rgh.is_zero()) return *this;

    SparsePoly res = SparsePoly();
    SimpleNode* p1 = new SimpleNode(this->head);
    SimpleNode* p2 = new SimpleNode(rgh.head);

    do {
        if (p1->deg < p2->deg) {
            res.add(new SimpleNode(p1));
            p1 = p1->next;
        } else if (p1->deg == p2->deg) {
            p1->coeff += p2->coeff;
            res.add(new SimpleNode(p1));
            p1 = p1->next;
            p2 = p2->next;
        } else {
            res.add(new SimpleNode(p2));
            p2 = p2->next;
        }
    } while (p1 != nullptr && p2 != nullptr);

    while (p1 != nullptr) {
        res.add(new SimpleNode(p1));
        p1 = p1->next;
    }
    while (p2 != nullptr) {
        res.add(new SimpleNode(p2));
        p2 = p2->next;
    }

    return res;
}

SparsePoly SparsePoly::operator*(SparsePoly rgh) {
    if (this->is_zero()) return *this;
    if (rgh.is_zero()) return rgh;

    SparsePoly res = SparsePoly();

    SimpleNode* p1 = new SimpleNode(this->head);
    SimpleNode* p2 = new SimpleNode(rgh.head);

    while (p1 != nullptr) {
        while (p2 != nullptr) {
            int coeff, deg;
            coeff = p1->coeff * p2->coeff;
            deg = p1->deg + p2->deg;

            res.add(new SimpleNode(deg, coeff));
            p2 = p2->next;
        }
        p2 = rgh.head;
        p1 = p1->next;

    }

    res.sparse();

    return res;
}

void SparsePoly::sparse() {
    SimpleNode *p1, *p2, *dup;
    p1 = this->head;
    while (p1 != nullptr && p1->next != nullptr) {
        p2 = p1;

        while (p2->next != nullptr) {

            if (p1->deg == p2->next->deg) {
                p1->coeff = p1->coeff + p2->next->coeff;
                dup = p2->next;
                p2->next = p2->next->next;
                delete (dup);
            } else
                p2 = p2->next;
        }
        p1 = p1->next;
    }

}
