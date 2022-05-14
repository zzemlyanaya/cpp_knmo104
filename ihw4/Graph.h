//
// Created by Evgeniya Zemlyanaya on 14.05.2022.
//

#ifndef HW_GRAPH_H
#define HW_GRAPH_H

#include <iostream>

class Graph {

private:
    int V, R;
    int** matrix;

public:
    Graph(int V, int R);
    friend std::istream& operator>>(std::istream& in, Graph* graph);
    bool is_tree();
};


#endif //HW_GRAPH_H
