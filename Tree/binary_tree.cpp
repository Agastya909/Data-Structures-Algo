#include <iostream>
using namespace std;

class treeNode
{
public:
    int key;
    treeNode *left;
    treeNode *right;
    treeNode();
    treeNode(int data)
    {   
        key = data;
        left = NULL;
        right = NULL;
    }
};

class binaryTree
{
public:
    treeNode *root;
    void inputData();
    void makeBST(int data);
    void print();
    binaryTree addNode(treeNode *root, int data);
    binaryTree()
    {
        root = NULL;
    }
};

binaryTree binaryTree::addNode(treeNode *root, int data)
{

}

void binaryTree::makeBST(int data)
{
    treeNode *node = new treeNode();

}

void binaryTree::inputData()
{

    int operation, nodeData;
    while (operation != 0)
    {
        cout << "1 to enter data in BST\n";
        cout << "0 to quit\n";
        cin >> operation;
        switch (operation)
        {
        case 0:
            cout << "Quitting\n";
            break;
        case 1:
            cout << "Enter number for node : ";
            cin >> nodeData;
            makeBST(nodeData);
            break;
        }
    }
}


int main()
{
    binaryTree makeTree;
    makeTree.inputData();
    return 0;
}