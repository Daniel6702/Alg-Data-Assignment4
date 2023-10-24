#include <iostream>
#include <cmath>

struct Node {
    int data;
    Node* left;
    Node* right;
    int height;
};

// get height of tree
int getHeight(Node* node) {
    if (node == nullptr) return -1;
    return node->height;
}

// get balance factor of tree
int getBalanceFactor(Node* node) {
    if (node == nullptr) return 0;
    return getHeight(node->left) - getHeight(node->right);
}

// check if tree is balanced recursively
bool isBalanced(Node* node) {
    if (node == nullptr) return true;

    int balance = getBalanceFactor(node);

    // check if balance factor is within the acceptable range
    if (balance < -1 || balance > 1) return false;

    // Recur for left and right subtrees.
    return isBalanced(node->left) && isBalanced(node->right);
}

// create node
Node* createNode(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    newNode->height = 0;
    return newNode;
}

// main for testing
int main() {
    // Balanced Tree
    Node* Root1 = createNode(10);
    Root1->left = createNode(5);
    Root1->right = createNode(15);

    // Unbalanced Tree
    Node* Root2 = createNode(10);
    Root2->left = createNode(5);
    Root2->right = createNode(15);
    Root2->right->right = createNode(20);

    // Update heights (assuming height of leaf nodes is 0)
    Root1->left->height = 1;
    Root1->right->height = 1;

    Root2->left->height = 1;
    Root2->right->height = 1;
    Root2->right->right->height = 0;

    bool isRoot1 = isBalanced(Root1);
    bool isRoot2 = isBalanced(Root2);

    if (isRoot1) {
        std::cout << "The balanced tree is balanced." << std::endl;
    } else {
        std::cout << "The balanced tree is not balanced." << std::endl;
    }

    if (isRoot2) {
        std::cout << "The unbalanced tree is balanced." << std::endl;
    } else {
        std::cout << "The unbalanced tree is not balanced." << std::endl;
    }

    return 0;
}