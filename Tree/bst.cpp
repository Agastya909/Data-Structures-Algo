#include <iostream>
using namespace std;

class tree
{
public:
    struct node
    {
        int data;
        node *left;
        node *right;
    };
    node *root;
    node *addNode(node *root, int data);
    void print();
    void inputFn();
    tree()
    {
        root = NULL;
    }
};

tree::node *tree::addNode(node *root, int data)
{

}

void tree::inputFn()
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
            addNode(root, nodeData);
            break;
        }
    }
}

int main()
{
    tree makeTree;
    makeTree.inputFn();
    return 0;
}
