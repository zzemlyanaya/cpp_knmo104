//
// Created by Evgeniya Zemlyanaya on 28.05.2022.
//
#include <iostream>
#include <iterator>
#include <sstream>
#include "Stack.h"
#include "CharUtils.h"
using namespace std;

bool TryParse(const string &symbol);

int main() {
    string infix, token;
    getline(cin, infix);
    istringstream iss(infix);

    string output;
    Stack<string> s = Stack<string>(infix.size());

    while(iss) {
        iss >> token;

        if(TryParse(token)) {
            output += token + " ";
        }

        else if(token == "(") {
            s.push(token);
        }

        else if(token == ")") {
            while(!s.isEmpty() && s.peek() != "(") {
                output += s.peek() + " ";
                s.pop();
            }
            s.pop();
        }

        else if(isOperator(token[0])) {
            while(!s.isEmpty() && getPriority(s.peek()[0]) >= getPriority(token[0])) {
                output += s.peek() + " ";
                s.pop();
            }
            s.push(token);
        }
    }

    while(!s.isEmpty()) {
        output += s.peek() + " ";
        s.pop();
    }

    cout << output;
    return 0;
}
bool TryParse(const string &symbol) {
    for(int i = 0; i < symbol.size(); i++) {
        if(!isdigit(symbol[i]))
            return false;
    }
    return true;
}