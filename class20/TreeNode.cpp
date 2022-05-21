//
// Created by Evgeniya Zemlyanaya on 11.05.2022.
//

#include "TreeNode.h"

TreeNode::TreeNode(int value) {
    this->value = value;
    left = nullptr;
    right = nullptr;
}

void TreeNode::add_node(TreeNode *node) {
    if (this->left == nullptr) this->left = node;
    else this->right = node;
}

int TreeNode::get_height(TreeNode *root) {
    if (root == nullptr) return 0;
    return 1 + std::max(get_height(root->left), get_height(root->right));
}

void TreeNode::print(std::ofstream& out, const std::string& prefix, const TreeNode* node, bool isLeft) {
    if (node != nullptr) {
        out << prefix;

        out << (isLeft ? "├──" : "└──" );

        out << node->value << std::endl;

        print(out, prefix + (isLeft ? "│   " : "    "), node->left, true);
        print(out, prefix + (isLeft ? "│   " : "    "), node->right, false);
    }
}

void TreeNode::print(std::ofstream& out) {
    print(out, "", this, false);
}

void TreeNode::infix(TreeNode *root) {
    if (root->left != nullptr) {
        infix(root->left);
    }
    std::cout << root->value << " " << std::endl;
    if (root->right != nullptr) {
        infix(root->right);
    }
}

bool TreeNode::is_balanced(TreeNode* root) {
    int lh, rh;

    if (root == nullptr) return true;

    lh = get_height(root->left);
    rh = get_height(root->right);

    if (abs(lh - rh) <= 1 && is_balanced(root->left) && is_balanced(root->right)) return true;

    return false;
}