//
// Created by zzemlyanaya on 09.03.2022.
//

#include "geometry.h"

// -------------- Point --------------
Point::Point() {
    this->x = 0;
    this->y = 0;
}

Point::Point(double x, double y) {
    this->x = x;
    this->y = y;
}

// -------------- Utils --------------

const double EPS = 1e-9;

double det(double a, double b, double c, double d) {
    return a * d - b * c;
}

// -------------- Line --------------

Line::Line() {
    this->a = 0;
    this->b = 0;
    this->c = 0;
}

Line::Line(double a, double b, double c) {
    this->a = a;
    this->b = b;
    this->c = c;
}

bool Line::is_intersect(Line* m, Line* n, Point &p) {
    double zn = det(m->a, m->b, n->a, n->b);

    if (abs(zn) < EPS) {
        p = this->ZERO_POINT;
        return false;
    }
    p.x = - det(m->c, m->b, n->c, n->b) / zn;
    p.y = - det(m->a, m->c, n->a, n->c) / zn;
    return true;
}