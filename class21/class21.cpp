//
// Created by Evgeniya Zemlyanaya on 27.04.2022.
//

#include <iostream>
#include <cmath>

using namespace std;

# define my_sizeof(type) ((char *)(&type+1)-(char*)(&type))


void count_lvls(int** tree, int* branch, int* res, int count) {
    res[count]++;
    if (branch == nullptr) return;

    for (int i = 1; i <= branch[0]; ++i) {
        count_lvls(tree, tree[branch[i]], res, count+1);
    }
}

int main() {

    int v, r, temp;
    cin >> v;

    int** tree = new int*[v];
    int* list;

    for (int i = 0; i < v; ++i) {
        cin >> r;
        if (r == 0)
            list = nullptr;
        else {
            list = new int[r + 1];
            list[0] = r;
            for (int j = 1; j <= r; ++j) {
                cin >> temp;
                list[j] = temp-1;
            }
        }
        tree[i] = list;
    }

    cout << "----- tree -----" << endl;
    for (int i = 0; i < v; ++i) {
        cout << i+1 << " : ";
        if (tree[i] == nullptr) cout << "no children" << endl;
        else {
            for (int j = 1; j <= tree[i][0]; ++j) {
                cout << tree[i][j]+1 << " ";
            }
            cout << endl;
        }
    }

    int* res = new int[v];
    int count = 0;
    count_lvls(tree, tree[0], res, count);

    cout << "----- levels counted -----" << endl;
    for (int i = 0; i < v; ++i) {
        if (res[i] == 0) break;
        cout << i << " : " << res[i] << endl;
    }

    return 0;
}

//3
//2 2 3
//0
//0

//7
//3 2 3 4
//2 5 6
//0
//1 7
//0
//0
//0