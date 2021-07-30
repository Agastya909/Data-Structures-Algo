#include <iostream>
using namespace std;

class node
{
public:
    int key;
    node *left;
    node *right;
};

class BST
{
public:
    node *root;
    void inputData();
    void print(node *root);
    node *addNode(int data);
    node *makeBST(node *root, int data);
    BST()
    {
        root = NULL;
    }
};

node *BST::addNode(int data)
{
    node *newNode = new node();
    newNode->key = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

node *BST::makeBST(node *root, int data)
{
    if (root == NULL)
    {
        root = addNode(data);
    }
    else if (root->key > data)
    {
        root->left = makeBST(root->left, data);
    }
    else
    {
        root->right = makeBST(root->right, data);
    }
    return root;
}

void BST::inputData()
{
    int operation, nodeData;
    while (operation != 0)
    {
        cout << "1 to enter data in BST\n";
        cout << "2 to print the tree\n";
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
            root = makeBST(root, nodeData);
            break;
        case 2:
            cout << "The tree in postorder traversal is : ";
            print(root);
            cout << endl;
            break;
        }
    }
}

void BST::print(node *root)
{
    if (root == 0)
    {
        return;
    }
    else
    {
        print(root->right);
        cout << root->key << "  ";
        print(root->left);
    }
}

int main()
{
    BST makeTree;
    makeTree.inputData();
    return 0;
}