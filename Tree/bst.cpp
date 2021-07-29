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
    void addData();
    tree *addNode(node *root, int data);
    
};
