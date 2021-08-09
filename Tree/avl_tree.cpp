#include <iostream>
using namespace std;

class node
{
public:
    int key;
    int height;
    node *left;
    node *right;
};

class AVL
{
public:
    node *root;
    void input();
    void printInorder(node *root);
    // void preOrder(node *root);
    // void postOrder(node *root);
    // void findMax(node *root);
    // void findMin(node *root);
    int heightTree(node *root);
    int getBalance(node *root);
    // int findElement(node *root, int find, int returnValue);
    node *addNode(int data);
    node *makeBST(node *root, int data);
    node *rotateRight(node *root);
    node *rotateLeft(node *root);
    AVL()
    {
        root = NULL;
    }
};

node *AVL::addNode(int data)
{
    node *newNode = new node();
    newNode->key = data;
    newNode->height = -1;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

node *AVL::makeBST(node *root, int data)
{
    if (root == NULL)
    {
        root = addNode(data);
    }
    else if (root->key > data)
    {
        root->left = makeBST(root->left, data);
    }
    else if (root->key < data)
    {
        root->right = makeBST(root->right, data);
    }
    else
    {
        return root;
    }
    /*
        also use height with if else to i.e. 
        if(root.left == NULL) {left = 0; }
        else { left = height; }

        if(root.right == NULL) {left = 0; }
        else { left = height; }
    */
    root->height = max(heightTree(root->left), heightTree(root->right));
    int balFac = getBalance(root);

    if (balFac > 1 && root->left->key > data)
    {
        return rotateRight(root);
    }

    if (balFac < -1 && root->right->key < data)
    {
        return rotateLeft(root);
    }


    return root;
}

node *AVL::rotateRight(node *root)
{
    node *newRoot = root->left;
    node *temp = newRoot->right;

    newRoot->right = root;
    root->left = temp;

    root->height = max(heightTree(root->left), heightTree(root->right));
    newRoot->height = max(heightTree(newRoot->left), heightTree(newRoot->right));

    return newRoot;
}

node *AVL::rotateLeft(node *root)
{
    node *newRoot = root->right;
    node *temp = newRoot->left;

    newRoot->left = root;
    root->right = temp;

    root->height = max(heightTree(root->left), heightTree(root->right));
    newRoot->height = max(heightTree(newRoot->left), heightTree(newRoot->right));

    return newRoot;
}

int AVL::heightTree(node *root)
{
    if (root == NULL)
    {
        return -1;
    }
    else
    {
        int left = heightTree(root->left);
        int right = heightTree(root->right);
        return max(left, right) + 1;
    }
}

int AVL::getBalance(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return heightTree(root->left) - heightTree(root->right);
}

void AVL::input()
{
    int operation, nodeData;
    while (operation != 0)
    {
        cout << "1 to enter data in BST\n";
        cout << "2 to print Inorder traversal\n";
        cout << "3 to print Preorder traversal\n";
        cout << "4 to print Postorder traversal\n";
        cout << "5 to search for an element in the tree\n";
        cout << "6 to print largest number in the tree.\n";
        cout << "7 to print smallest number in the tree.\n";
        cout << "8 to print height of the tree.\n";
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
        // case 3:
        //     cout << "The tree in Preorder traversal is : ";
        //     preOrder(root);
        //     cout << endl;
        //     break;
        // case 4:
        //     cout << "The tree in Postorder traversal is : ";
        //     postOrder(root);
        //     cout << endl;
        //     break;
        // case 5:
        //     int find, returnValue;
        //     cout << "Enter element that has to be searched : ";
        //     cin >> find;
        //     returnValue = findElement(root, find, returnValue);
        //     if (returnValue == 1)
        //     {
        //         cout << "The element is present in the tree.\n";
        //     }
        //     else
        //     {
        //         cout << "The element is not present in the tree.\n";
        //     }
        //     break;

        // case 6:
        //     findMax(root);
        //     break;
        // case 7:
        //     findMin(root);
        //     break;
        case 8:
            int hTree;
            hTree = heightTree(root);
            cout << "Height of the tree is : " << hTree << endl;
            break;
        }
    }
}

void AVL::printInorder(node *root)
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

int main()
{
    AVL makeTree;
    makeTree.input();
}
