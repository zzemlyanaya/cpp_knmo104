#include <windows.h>
#include <iostream>
#include <string>

using namespace std;

void doMagic(string s) {
    string word_dels = " ,:;-";
    string sent_dels = ".!? ";
    int sent_count = 0, word_count = 0;
    float lens_sum = 0;
    int N = s.length();
    int i = 0;
    while(i < N) {
        if (word_dels.find(s[i]) != -1) {
            word_count++;
            while (word_dels.find(s[i]) != -1) i++;
        }
        else if (sent_dels.find(s[i]) != -1) {
            word_count++;
            lens_sum += word_count;
            word_count = 0;
            sent_count++;
            while (sent_dels.find(s[i]) != -1) i++;
        }
        else if (i == N-1) {
            word_count++;
            lens_sum += word_count;
            sent_count++;
            i++;
        }
        else i++;
    }
    float res = lens_sum / sent_count;
    cout << "Средняя длина предложения в тексте: " << res << endl;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    string input;
    getline(cin, input);
    while (input != "-1") {
        doMagic(input);
        getline(cin, input);
    }
    return 0;
}