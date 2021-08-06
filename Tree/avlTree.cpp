#include <iostream>
using namespace std;

class node
{
public:
    int key;
    int height;
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

class avlTree
{
public:
    node *root;
    node *addNode(int data);
    node *makeAVL(int data, node *root);
    void input();
    void printSort(node *root);
    int findElement(node *root, int find, int returnValue);
    avlTree()
    {
        root = NULL;
    }
};

node *avlTree::makeAVL(int data, node *root)
{
    
}

void avlTree::input()
{
    int operation, nodeData;
    while (operation != 0)
    {
        cout << "0 to quit\n";
        cout << "1 to add data to node\n";
        cout << "2 to search data from the tree\n";
        cout << "3 to print elements in sorted order : \n";
        cin >> operation;
        switch (operation)
        {
        case 0:
            cout << "Quitting\n";
            break;
        case 1:
            cout << "Enter number for node : ";
            cin >> nodeData;
            root = makeAVL(nodeData, root);
            break;
        case 2:
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
        case 4:
            printSort(root);
            break;
        }
    }
}

int main()
{
    avlTree makeTree;
    makeTree.input();
    return 0;
}