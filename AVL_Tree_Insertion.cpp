// AVL_Tree_Insertion.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
using namespace std;

struct Node
{
    int key;
    int height;
    int balance;
    Node* next;
    Node* left;
    Node* right;

    Node(int nodeKey)
    {
        key = nodeKey;
        height = 0;
        balance = 0;
        next = nullptr;
        left = nullptr;
        right = nullptr;
    };
};

class Queue
{
private:
    struct QueueNode
    {
        Node* data;
        QueueNode* next;
        QueueNode(Node* node) { data = node; next = nullptr; }
    };
    QueueNode* front;
    QueueNode* rear;
    int queueSize;
public:
    Queue() { front = nullptr; rear = nullptr; queueSize = 0; }
    void enqueue(Node* node)
    {
        QueueNode* newNode = new QueueNode(node);
        if (rear == nullptr)
        {
            front = newNode;
            rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
        queueSize++;
    }
    Node* dequeue()
    {
        if (front == nullptr) { return nullptr; }
        QueueNode* temp = front;
        Node* node = front->data;
        front = front->next;
        if (front == nullptr) { rear = nullptr; }
        delete temp;
        queueSize--;
        return node;
    }
    bool isEmpty() { return front == nullptr; }
    int size() { return queueSize; }
};

int getHeight(Node* node) { return node ? node->height : 0; };
int getBalance(Node* node) { return node ? getHeight(node->left) - getHeight(node->right) : 0; };

Node* leftRotate(Node* x)
{
    Node* y = x->right;
    x->right = y->left;
    y->left = x;

    //Updating the heights
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;

}

Node* rightRotate(Node* x)
{
    Node* y = x->left;
    x->left = y->right;
    y->right = x;

    //Updating the heights
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

Node* rebalance(Node* node)
{
    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
    int balance = getBalance(node);  //node->left - node->right

    if (balance == 2 && getBalance(node->left) == 1) { return rightRotate(node); }          //left outward imbalance
    else if (balance == 2 && getBalance(node->left) == -1)                                  //left inward imbalance
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    else if (balance == -2 && getBalance(node->right) == -1) { return leftRotate(node); }   // right outward imbalance
    else if (balance == -2 && getBalance(node->right) == 1)                                 //right inward imbalance
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    else { return node; }
}

Node* insert(Node* node, int key)
{
    //this is the non-tail recursive process due to rebalance
    if (node == nullptr)
    {
        Node* newNode = new Node(key);
        return newNode;
    }
    if (key < node->key) { node->left = insert(node->left, key); }
    else if (key > node->key) { node->right = insert(node->right, key); }
    else { return node; }
    node = rebalance(node); //update heights and rebalance
}

int main()
{
    // The goal is to implement a binary tree through a input txt file
    // and balancing it everytime it becomes unbalanced through AVL method
    //
    // Finally, we insert the final balanced tree to a output txt file in the
    // directory of this depository through displaying each level on a seperate
    // line using the two queue display method
    ifstream in;
    ofstream out;
    int temp;
    Node* root = nullptr;
    Queue queue;

    in.open("input.txt");
    if (!(in.is_open()))
    {
        cout << "ERROR: input file could not be opened!" << endl;
        return 0;
    }
    while (in >> temp)
    {
        root = insert(root, temp);
    }

    // Printing out levels of Tree in output file
    out.open("output.txt");
    if (root == nullptr)
    {
        return 0;
    }
    queue.enqueue(root);
    while (!(queue.isEmpty()))
    {
        int levelSize = queue.size();
        for (int i = 0; i < levelSize; i++)
        {
            Node* node = queue.dequeue();
            if (node != nullptr)
            {
                out << node->key << " ";
                queue.enqueue(node->left);
                queue.enqueue(node->right);
            }
        }
        out << endl;
    }

    in.close();
    out.close();

    return 0;
}
