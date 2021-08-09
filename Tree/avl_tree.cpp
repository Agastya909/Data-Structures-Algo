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
    node *addNode(int data);
    node *makeAVL(node *root, int data);
    node *rotateRight(node *root);
    node *rotateLeft(node *root);
    void input();
    void printInorder(node *root);
    void preOrder(node *root);
    void postOrder(node *root);
    void findMax(node *root);
    void findMin(node *root);
    int heightTree(node *root);
    int getBalance(node *root);
    int findElement(node *root, int find, int returnValue);
    AVL()
    {
        root = NULL;
    }
};

// Creates a new node and returns it's address
node *AVL::addNode(int data)
{
    node *newNode = new node();
    newNode->key = data;
    newNode->height = -1;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Attaches the node to the AVL tree
node *AVL::makeAVL(node *root, int data)
{
    if (root == NULL)
    {
        root = addNode(data);
    }
    else if (root->key > data)
    {
        root->left = makeAVL(root->left, data);
    }
    else if (root->key < data)
    {
        root->right = makeAVL(root->right, data);
    }
    else
    {
        return root;
    }

    root->height = 1 + max(heightTree(root->left), heightTree(root->right));
    int balFac = getBalance(root);

    if (balFac > 1 && root->left->key > data)
    {
        return rotateRight(root);
    }

    if (balFac < -1 && root->right->key < data)
    {
        return rotateLeft(root);
    }

    if (balFac > 1 && data > root->left->key)
    {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    if (balFac < -1 && data < root->right->key)
    {
        root->right = rotateRight(root->right);
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

int AVL::findElement(node *root, int find, int returnValue)
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
            root = makeAVL(root, nodeData);
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
            int find, returnValue;
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

        case 6:
            findMax(root);
            break;
        case 7:
            findMin(root);
            break;
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

void AVL::preOrder(node *root)
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

void AVL::postOrder(node *root)
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

void AVL::findMax(node *root)
{
    if (root == NULL)
    {
        cout << "Tree empty.\n";
    }
    else
    {
        while (root->right != NULL)
        {
            root = root->right;
        }
        cout << "Largest number in the tree is : " << root->key << endl;
    }
}

void AVL::findMin(node *root)
{
    if (root == NULL)
    {
        cout << "Tree empty.\n";
    }
    else
    {
        while (root->left != NULL)
        {
            root = root->left;
        }
        cout << "Smallest number in the tree is : " << root->key << endl;
    }
}

int main()
{
    AVL makeTree;
    makeTree.input();
}
