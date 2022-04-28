//
// Created by Evgeniya Zemlyanaya on 27.04.2022.
//

#include <iostream>
#include <cmath>
#include "ListList.h"

using namespace std;

# define my_sizeof(type) ((char *)(&type+1)-(char*)(&type))

// 4 3 1 0 0 0 1 0 0 0 1 1 1 1
// 4 6 1 1 1 0 0 0 1 0 0 1 1 0 0 1 0 1 0 1 0 0 1 0 1 1

void first() {
    int v, r, temp;
    cin >> v >> r;

    int count = 0;

    for (int i = 0; i < v; ++i) {
        for (int j = 0; j < r; ++j) {
            cin >> temp;
            if (temp) count++;
        }
    }

    if (count == v*(v-1))
        cout << "Complete" << endl;
    else
        cout << "Incomplete" << endl;
}

//4
//2 2 3
//3 1 3 4
//2 1 2
//1 2

//5
//1 2
//1 4
//1 4
//3 2 3 5
//1 4

void second() {
    int v, r, temp;
    cin >> v;

    int* refs = new int[v];
    for (int i = 0; i < v; ++i) refs[i] = i+1;
    int ref_p;

    ListList* initial_list = new ListList();

    for (int i = 0; i < v; ++i) {
        SimpleList* list = new SimpleList();
        cin >> r;
        ref_p  = 0;
        for (int j = 0; j < r; ++j) {
            cin >> temp;
            while (refs[ref_p] != temp && ref_p < v) list->add(new SimpleNode(++ref_p));
            if (ref_p < v && refs[ref_p] == temp) ref_p++;
        }
        while (ref_p < v) list->add(new SimpleNode(++ref_p));

        initial_list->add(new ListNode(list));
    }

    cout << initial_list;
}

int main() {

    int task;
    cin >> task;
    while (task != -1) {
        if (task == 1) first();
        else if (task == 2) second();
        else cout << "Unknown task number";
        cin >> task;
    }

    return 0;
}