//
// Created by Evgeniya Zemlyanaya on 14.05.2022.
//

#include "Graph.h"

using namespace std;

int main()
{
    int V, R;
    cin >> V >> R;

    Graph* graph = new Graph(V, R);
    cin >> graph;

    bool ans = graph->is_tree();

    cout << ans;
}

//3 2
//1 2
//2 3

//5 7
//1 2
//1 5
//2 3
//2 5
//3 5
//3 4
//4 5

//12 11
//1 2
//1 3
//1 4
//2 5
//2 6
//4 7
//4 8
//5 9
//5 10
//7 11
//7 12