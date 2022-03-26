//
// Created by Evgeniya Zemlyanaya on 16.03.2022.
//

#include <string>

struct Node {
    std::string value;
    int freq;
    Node* next;

    Node();
    Node(std::string value);
};
