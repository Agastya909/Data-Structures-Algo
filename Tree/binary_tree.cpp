#include <iostream>
using namespace std;

class node
{
public:
    int key;
    node *left;
    node *right;
    node();
    node(int data)
    {
        key = data;
        left = NULL;
        right = NULL;
    }
};

class BST
{
public:
    node *root;
    void inputData();
    void makeBST(int data);
    void print(node *root);
    node addNode(node *root, int data);
    BST()
    {
        root = NULL;
    }
    
};

node BST::addNode(node *root, int data)
{
    if (root == NULL)
    {
        return node(data);
    }
    else if (root->key > data)
    {
        *root->right = addNode(root->left, data);
    }
    else
    {
        *root->right = addNode(root->right, data);
    }
    return *root;
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
            addNode(root, nodeData);
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
        cout << root->key << "  ";
        print(root->right);
        print(root->left);
    }
}

int main()
{
    BST makeTree;
    makeTree.inputData();
    return 0;
}