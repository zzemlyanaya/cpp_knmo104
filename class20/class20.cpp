//
// Created by Evgeniya Zemlyanaya on 11.05.2022.
//

#include "TreeNode.h"

using namespace std;

#define BLOCK 0

bool is_blocked(TreeNode* node) {
    return node->value == BLOCK ||
            node->left != nullptr && node->left->value == BLOCK ||
            node->right != nullptr && node->right->value == BLOCK;
}

bool can_add(TreeNode* node) {
    return node->left == nullptr || node->right == nullptr;
}

TreeNode* find_empty(TreeNode* root) {
    if (root == nullptr || is_blocked(root)) return nullptr;
    if (root->left == nullptr && root->right == nullptr) return root;

    TreeNode* res = root;
    if (root->left != nullptr) res = find_empty(root->left);

    if (res != nullptr) return res;
    if (root->right == nullptr) return root;

    res = find_empty(root->right);

    if (res != nullptr) return res;

    return nullptr;
}

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");
    int a, is_left;
    in >> a;

    TreeNode *root = new TreeNode(a);
    TreeNode *cur = root;


    while (!in.eof()) {
        in >> a;

        if(!can_add(cur)) cur = find_empty(root);

        is_left = (cur->left == nullptr) ? 1 : 0;

        cur->add_node(new TreeNode(a));
        if (a != 0) cur = is_left ? cur->left : cur->right;

    }
    in.close();

    root->print(out);
    cout << root->is_balanced(root);
}
