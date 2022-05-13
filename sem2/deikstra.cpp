//
// Created by Evgeniya Zemlyanaya on 11.05.2022.
//

void deikstra(int v, int start, int finish, int** graph) {
    int* dist = new int[v];
    bool* visited = new bool[v]{ false };
    int* path = new int[v];

    visited[start] = true;
    for (int i = 0; i < v; ++i) {
        if (graph[start][i] == -1) dist[i] = INF;
        else dist[i] = graph[start][i];
    }

    for (int i = 0; i < v; ++i) {
        int cur = -1;

        for (int j = 0; j < v; ++j)
            if (!visited[j] && (cur == -1 || dist[j] < dist[cur]))
                cur = j;

        if (cur == -1 || dist[cur] == INF)
            break;

        visited[cur] = true;

        for (int j = 0; j < v; ++j) {
            if (graph[cur][j] == -1) continue;

            int len = graph[cur][j];
            if (dist[cur] + len < dist[j]) {
                dist[j] = dist[cur] + len;
                path[j] = cur;
            }
        }
    }

    cout << dist[finish] << endl;
    for (int i = finish; i != start; i = path[i]) {
        cout << i << " ";
    }
    cout << 0;
}

int main() {
    int v, finish;
    cin >> v;

    int ** graph = new int*[v];
    for (int i = 0; i < v; ++i) {
        graph[i] = new int[v];
        for (int j = 0; j < v; ++j) {
            cin >> graph[i][j];
        }
    }

    cin >> finish;

    deikstra(v, 0, finish, graph);

    return 0;
}

//6
//-1 7 9 -1 -1 14
//7 -1 10 15 -1 -1
//9 10 -1 11 -1 2
//-1 15 11 -1 6 -1
//-1 -1 -1 6 -1 9
//14 -1 2 -1 9 -1
