//
// Created by Evgeniya Zemlyanaya on 28.05.2022.
//

#include "CharUtils.h"


bool isNumber(char chr) {
    return isdigit(chr) || chr == '.';
}

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int getPriority(char chr) {
    switch (chr) {
        case '^': return 3;
        case '*': return 2;
        case '/': return 2;
        case '+': return 1;
        case '-': return 1;
        default: return -1;
    }
}