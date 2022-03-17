//
// Created by Evgeniya Zemlyanaya on 16.03.2022.
//

#include "List.h"

using namespace std;

int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    if (inputFile.fail()) return -1;

    List* list = new List();
    Node* node = new Node();

    int num;

    while (inputFile >> num) {
        if (list->is_empty()) {
            list->add(new Node(num));
        }
        else {
            node = list->getHead();

            do {
                if (node->value == num) {
                    node->freq += 1;
                    break;
                }
                node = node->next;
            }
            while (node != nullptr);

            if (node == nullptr) list->add(new Node(num));
        }
    }

    outputFile << list;
}