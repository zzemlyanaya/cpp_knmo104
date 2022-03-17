//
// Created by zzemlyanaya on 09.03.2022.
//

#include "geometry.h"
#include <fstream>

using namespace std;

int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    if (inputFile.fail()) return -1;

    Line* n = new Line();
    Line* m = new Line();

    inputFile >> n->a >> n->b >> n->c;
    inputFile >> m->a >> m->b >> m->c;

    Point* p = new Point();
    outputFile << n->is_intersect(m, n, *p) << endl << p->x << " " << p->y << endl;
}
