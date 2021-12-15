#include <windows.h>
#include <iostream>
#include <string>
#include <cmath>

using namespace std;


int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    string txt = "";
    getline(cin, txt);

    int N = txt.length();
    int prev_counter, next_counter;
    for (int i = 0; i < N; i++) {
        prev_counter = 0;
        for (int j = 0; j < i; j++) {
            if (txt[i] == txt[j]) prev_counter++;
        }

        if (prev_counter == 0) {
            next_counter = 1;
            for (int j = i + 1; j < N; j++) {
                if (txt[i] == txt[j]) next_counter++;
            }

            cout << txt[i] << " : " << next_counter << endl;
        }
    }

    return 0;
}