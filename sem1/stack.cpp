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

void push(item** top, int d){
    item* q = new item();
    q -> data = d;
    if(top == NULL)
        *top = q;
    else{
        q -> next = *top;
        *top = q;
    }
}

void delete_last(item** top){
    item* q = *top;
    *top = q -> next;
    delete(q);
}

void print_all(item* top){
    while (top != NULL){
        cout << top->data << " ";
        top = top->next;
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    item* top = NULL;
    string s = "";
    getline(cin, s);
    while(s != ""){
        if (s[0] == '-') {
            if (top == NULL) {
                cout << "ERROR";
                return 0;
            }
            else
                delete_last(&top);
        }
        else
            push(&top, std::stoi(s.substr(1)));
        getline(cin, s);
    }

    if(top == NULL)
        cout << "EMPTY";
    else{
        item* f = NULL;
        while (top != NULL) {
            push(&f, top->data);
            top = top->next;
        }
        print_all(f);
    }
    return 0;
}
