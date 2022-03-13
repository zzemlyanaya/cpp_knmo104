//
// Created by zzemlyanaya on 22.09.2021.
//

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

struct item {
    int data;
    item* next;
};

void print_all(item* top) {
    while (top != NULL) {
        cout << top->data << " ";
        top = top->next;
    }
}

void push(item** top, item** tail, int d) {
    item* q = new item();
    q->data = d;
    q->next = NULL;
    item* t = *tail;
    *tail = q;
    if (*top == NULL)
        *top = q;
    else
        t->next = q;
}

void delete_last(item** top) {
    item* q = *top;
    *top = q->next;
    delete(q);
}

int pop(item** top) {
    item* q = *top;
    *top = q->next;
    int a = q->data;
    delete(q);
    return a;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    item* top = NULL;
    item* tail = NULL;
    string s = "";
    getline(cin, s);
    while (s != "") {
        if (s[0] == '-') {
            if (top == NULL) {
                cout << "ERROR";
                return 0;
            }
            else
                pop(&top);
        }
        else
            push(&top, &tail, std::stoi(s.substr(1)));
        getline(cin, s);
    }

    if(top == NULL)
        cout << "EMPTY";
    else
        print_all(top);
    return 0;
}