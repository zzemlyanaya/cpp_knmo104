//
// Created by Evgeniya Zemlyanaya on 11.05.2022.
//

#ifndef HW_TREENODE_H
#define HW_TREENODE_H

#include <iostream>
#include<fstream>
#include <cmath>


struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value);

    void add_node(TreeNode* node);
    int get_height(TreeNode* root);
    void print(std::ofstream& out);
    void print(std::ofstream& out, const std::string& prefix, const TreeNode* node, bool isLeft);
    void infix(TreeNode* root);
    bool is_balanced(TreeNode* root);
};


#endif //HW_TREENODE_H
