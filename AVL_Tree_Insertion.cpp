// AVL_Tree_Insertion.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Node
{
public:
    int key;
    int height;
    int balance;
    Node* left;
    Node* right;

    Node(int nodeKey)
    {
        key = nodeKey;
        left = nullptr;
        right = nullptr;
    }
    Node* rebalance(Node* node);
    Node* insert(Node* node, int key);
    Node* leftRotate(Node* node);
    Node* rightRotate(Node* node);

    int getHeight(Node* node) { return height; };
    int getKey(Node* node) { return key; };
    int getBalance(Node* node) { return balance; };
};

Node* Node::rebalance(Node* node)
{
    return nullptr;
}

Node* Node::insert(Node* node, int key)
{
    return nullptr;
}

Node* Node::leftRotate(Node* node)
{
    return nullptr;
}

Node* Node::rightRotate(Node* node)
{
    return nullptr;
}

int main()
{
    // The goal is to implement a binary tree through a input txt file
    // and balancing it everytime it becomes unbalanced through AVL method
    //
    // Finally, we insert the final balanced tree to a output txt file in the
    // directory of this depository
    
    return 0;
}
