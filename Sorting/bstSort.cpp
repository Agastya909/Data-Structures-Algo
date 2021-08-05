// BST sort is nothing but inorder traversal of the BST
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
    void printSort(node *root);
    node *addNode(int data);
    node *makeBST(node *root, int data);
    BST()
    {
        root = NULL;
    }
};

node *BST::addNode(int data)
{
    // this fn() creates a new node 
    node *newNode = new node();
    newNode->key = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

node *BST::makeBST(node *root, int data)
{
    // this fn() appends the node returned 
    //from the above (addNode())  to the tree
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

void BST::printSort(node *root)
{
    if (root == 0)
    {
        return;
    }
    else
    {
        printSort(root->left);
        cout << root->key << "  ";
        printSort(root->right);
    }
}

void BST::inputData()
{
    int operation, nodeData;
    while (operation != 0)
    {
        cout << "1 to enter data\n";
        cout << "2 to print numbers in sorted order\n";
        cout << "0 to quit\n";
        cin >> operation;
        switch (operation)
        {
        case 0:
            cout << "Quitting\n";
            break;
        case 1:
            cout << "Enter number for list that needs to be sorted : ";
            cin >> nodeData;
            root = makeBST(root, nodeData);
            break;
        case 2:
            cout << "The tree in Inorder traversal is : ";
            printSort(root);
            cout << endl;
            break;
        }
    }
}

int main()
{
    BST makeTree;
    makeTree.inputData();
    return 0;
}