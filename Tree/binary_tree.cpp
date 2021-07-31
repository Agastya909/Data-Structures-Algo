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
    void printInorder(node *root);
    void preOrder(node *root);
    void postOrder(node *root);
    int findElement(node *root, int find, int returnValue);
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
        cout << "2 to print Inorder traversal\n";
        cout << "3 to print Preorder traversal\n";
        cout << "4 to print Postorder traversal\n";
        cout << "5 to search for an element in the tree\n";
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
            cout << "The tree in Inorder traversal is : ";
            printInorder(root);
            cout << endl;
            break;
        case 3:
            cout << "The tree in Preorder traversal is : ";
            preOrder(root);
            cout << endl;
            break;
        case 4:
            cout << "The tree in Postorder traversal is : ";
            postOrder(root);
            cout << endl;
            break;
        case 5:
            int find, returnValue = -1;
            cout << "Enter element that has to be searched : ";
            cin >> find;
            returnValue = findElement(root, find, returnValue);
            if (returnValue == 1)
            {
                cout << "The element is present in the tree.\n";
            }
            else
            {
                cout << "The element is not present in the tree.\n";
            }
            break;
        }
    }
}

void BST::printInorder(node *root)
{
    if (root == 0)
    {
        return;
    }
    else
    {
        printInorder(root->left);
        cout << root->key << "  ";
        printInorder(root->right);
    }
}

void BST::preOrder(node *root)
{
    if (root == 0)
    {
        return;
    }
    else
    {
        cout << root->key << "  ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void BST::postOrder(node *root)
{
    if (root == 0)
    {
        return;
    }
    else
    {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->key << "  ";
    }
}

int BST::findElement(node *root, int find, int returnValue)
{
    if (root->key == find)
    {
        returnValue = 1;
    }
    else if (root->key > find)
    {
        if (root->left != NULL)
        {
            returnValue = findElement(root->left, find, returnValue);
        }
        else
        {
            returnValue = 0;
        }
    }
    else if (root->key < find)
    {
        if (root->right != NULL)
        {
            returnValue = findElement(root->right, find, returnValue);
        }
        else
        {
            returnValue = 0;
        }
    }
    return returnValue;
}

int main()
{
    BST makeTree;
    makeTree.inputData();
    return 0;
}