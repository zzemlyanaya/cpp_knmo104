//
// Created by Evgeniya Zemlyanaya on 17.03.2022.
//

#include "TPoint.h"

TPoint::TPoint() {
    x = y = z = 0;
}

TPoint::TPoint(double x, double y, double z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

ostream &operator<<(ostream &os, TPoint *p) {
    os << "(" << p->x << ";" << p->y << ";" << p->z << ")";
    return os;
}

istream &operator>>(istream &is, TPoint *p) {
    is >> p->x >> p->y >> p->z;
    return is;
}

TPoint TPoint::operator+(TPoint rgh) {
    return TPoint(this->x+rgh.x, this->y+rgh.y, this->z+rgh.z);
}

TPoint TPoint::operator-(TPoint rgh) {
    return TPoint(this->x-rgh.x, this->y-rgh.y, this->z-rgh.z);
}

TPoint TPoint::operator*(double t) {
    return TPoint(this->x*t, this->y*t, this->z*t);
}

TPoint TPoint::operator*(TPoint rgh) {
    return TPoint(this->x*rgh.x, this->y*rgh.y, this->z*rgh.z);
}
