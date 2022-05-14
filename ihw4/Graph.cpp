//
// Created by Evgeniya Zemlyanaya on 14.05.2022.
//

#include "Graph.h"

Graph::Graph(int V, int R) {
    this->V = V;
    this->R = R;
    matrix = new int*[V];
    for (int i = 0; i < V; ++i) matrix[i] = new int[V]{0};

}

std::istream &operator>>(std::istream &in, Graph *graph) {
    int x, y;
    for (int i = 0; i < graph->R; ++i) {
        in >> x >> y;
        graph->matrix[x-1][y-1] = 1;
        graph->matrix[y-1][x-1] = 1;
    }
    return in;
}

// tree = connected & ribs = vertex-1
bool Graph::is_tree() {
    if (this->R != this->V-1) return false;

    int* queue = new int[this->V]{0};
    bool* visited = new bool[this->V]{false};

    int current = 1, head = 0;
    visited[0] = true;

    while (head < current) {
        int node = queue[head++];

        for (int i = 0; i < this->V; i++) {
            if (this->matrix[node][i] && !visited[i]) {
                queue[current++] = i;
                visited[i] = true;
            }
        }
    }

    for (int i = 0; i < this->V; ++i) if (!visited[i]) return false;

    delete[]queue;
    delete[]visited;

    return true;
}