//
// Created by Evgeniya Zemlyanaya on 16.03.2022.
//

#include "Dict.h"

using namespace std;

bool is_delim(int c) {
    return c == ' ' || c == '.' || c == ',' || c == ';' || c == '!' || c == '?' || c == ':' || c == '-';
}

bool is_letter(int c) {
    return isalpha(c);
}

int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    if (inputFile.fail()) return -1;

    Dict* list = new Dict();
    Node* node = new Node();

    string line, word;
    int c_ind, line_len;
    int fst, lst;

    while (getline(inputFile, line)){
        c_ind = 0;
        line_len = line.length();

        while (c_ind < line_len) {
            while (is_delim(tolower(line[c_ind++])));
            fst = --c_ind;
            while (is_letter(tolower(line[c_ind++])));
            lst = --c_ind;

            word = line.substr(fst, lst - fst);
            if(!word.empty()) list->addOrIncrement(word);
        }
    }

    list->sort();

    outputFile << list;
}