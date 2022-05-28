//
// Created by Evgeniya Zemlyanaya on 25.05.2022.
//

#include "Stack.h"
#include "CharUtils.h"
#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

/** Shunting-Yard tests
 * 3 + 4 -> 3 4 + -> 7
 * ( 3 + 5 ) * 7 -> 3 5 + 7 * -> 56
 * 3 + 4 * 5 / (3 + 2) -> 3 4 5 * 3 2 + / + -> 7
 * 5 + 3 * 6 - ( 5 / 3 ) + 7 -> 5 3 6 * + 5 3 / - 7 + -> 28....
 * (8+2*5)/(1+3*2-4)-5+(9/(1+2)+1)*3 -> ... -> 13
 * ((7-6.35)/6.5+9.9)/((1.2/36+1.2/0.25-21/16)/(169/24)) -> ... -> 20
 * ((13.75+9+1/6)*1.2)/((10.3-8-1/2)*(5/9))+((6.8-3-3/5)*(35/6))/((3+2/3-3-1/6)*56)-27-1/6 -> ... -> 1
 */

double calculateRNP(string expression);

int main() {
    string infix, token;
    getline(cin, infix);
    int i = 0;

    Stack<char> operators = Stack<char>(infix.length());
    string output;

    while (i < infix.length()) {
        while (infix[i] == ' ') {
            i++;
        }

        if (isNumber(infix[i])) {
            while (isNumber(infix[i])) {
                token += infix[i];
                i++;
            }
            output += token + " ";
            token = "";
        }

        else if (infix[i] == '(') {
            operators.push(infix[i]);
            i++;
        }

        else if (infix[i] == ')') {
            while (!operators.isEmpty() && operators.peek() != '(') {
                output += operators.pop();
                output += " ";
            }
            operators.pop();
            i++;
        }

        else if (isOperator(infix[i])) {
            while (!operators.isEmpty() && getPriority(operators.peek()) >= getPriority(infix[i])) {
                output += operators.pop();
                output += " ";
            }

            operators.push(infix[i]);
            i++;
        }
    }

    while(!operators.isEmpty()) {
        output += operators.pop();
        output += " ";
    }

    cout << output << endl;
    cout << calculateRNP(output);

    return 0;
}

double calculateRNP(string expression) {
    int i = 0;
    double v1, v2;
    string token;
    char op;
    Stack<double> stack = Stack<double>(expression.length());

    while (i < expression.length()){
        while (isspace(expression[i])){
            i++;
        }

        if (isNumber(expression[i])){
            while (isNumber(expression[i])){
                token += expression[i];
                i++;
            }

            stack.push(atof(token.c_str()));
            token = "";
        }

        else if (isOperator(expression[i])){
            op = expression[i];
            switch (op) {
                case '+':
                    v1 = stack.pop();
                    v2 = stack.pop();
                    stack.push(v2+v1);
                    break;
                case '-':
                    v1 = stack.pop();
                    v2 = stack.pop();
                    stack.push(v2-v1);
                    break;
                case '*':
                    v1 = stack.pop();
                    v2 = stack.pop();
                    stack.push(v2*v1);
                    break;
                case '/':
                    v1 = stack.pop();
                    v2 = stack.pop();

                    if (v1 == 0) throw runtime_error("Division by zero");

                    stack.push(v2/v1);
                    break;

                case '^':
                    v1 = stack.pop();
                    v2 = stack.pop();

                    if (v1 == 0 && v2 == 0) throw runtime_error("Zero in zero power");

                    stack.push(pow(v2, v1));
                default:
                    break;
            }
            i++;
        }
        else {
            i++;
        }
    }

    return stack.pop();
}

