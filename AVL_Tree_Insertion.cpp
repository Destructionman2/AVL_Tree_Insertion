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
        height = 0;
        balance = 0;
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
    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
    int balance = getBalance(node);  //node->left - node->right

    if (balance == 2 && getBalance(node->left) == 1) return rightRotate(node);              //left outward imbalance
    else if (balance == 2 && getBalance(node->left) == -1)                                  //left inward imbalance
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    else if (balance == -2 && getBalance(node->right) == -1) return leftRotate(node);       // right outward imbalance
    else if (balance == -2 && getBalance(node->right) == 1)                                 //right inward imbalance
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    else return node;
}

Node* Node::insert(Node* node, int key)
{
    //this is the non-tail recursive process due to rebalance
    if (node == nullptr)
    {
        Node* newNode = new Node(key);
        return newNode;
    }
    if (key < node->key) { node->left = insert(node->left, key); }
    else node->right = insert(node->right, key);
    node = rebalance(node); //update heights and rebalance
    return node;
}

Node* Node::leftRotate(Node* x)
{
    Node *y = x->right;
    
}

Node* Node::rightRotate(Node* x)
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
