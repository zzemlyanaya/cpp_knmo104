#include <windows.h>
#include <iostream>

using namespace std;

void doMagic(string input) {
    string stack;
    stack += input[0];
    int sti = 0;
    int n = input.length();

    for (int  i = 1; i < n; i++) {
        char cur = input[i];
        switch (cur) {
            case '(':
            case '{':
            case '[':
            case '<': {
                stack += cur;
                sti++;
                break;
            }
            case ')':
            case '}':
            case ']':
            case '>': {
                if (stack[sti] == cur-1 || stack[sti] == cur-2) {
                    stack.pop_back();
                    sti--;
                }
                else {
                    cout << "Incorrect!" << endl;
                    return;
                }
            }
            default:
                break;
        }
    }
    cout << "Correct!" << endl;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);

    string s;
    cin >> s;
    while (s != "-1") {
        doMagic(s);
        cin >> s;
    }
    return 0;
}