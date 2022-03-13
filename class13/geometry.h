//
// Created by zzemlyanaya on 09.03.2022.
//

#include<math.h>

struct Point {
    double x, y;
    Point();
    Point(double x, double y);
};

class Line {
public:
    double a, b, c;

    Point ZERO_POINT = Point(-42, -42);

    Line();
    Line(double a, double b, double c);

    bool is_intersect(Line* m, Line* n, Point &p);
};
