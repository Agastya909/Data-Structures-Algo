#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node()
    {
        next = NULL;
    }
};

class linkedList
{
public:
    node *head;
    void inputDatafn();
    void addNode(int nodeData);
    void addNodeAtN(int nodeData, int position);
    void deleteNode();
    void deleteNodeAtN(int position);
    void reverseList();
    void reverseRecursion(node *head);
    void print();
    void printReverse(node *head);
    linkedList()
    {
        head = NULL;
    }
};

void linkedList::inputDatafn()
{
    int operation, nodeData, insertPostion, deletePosition;
    while (operation != 0)
    {
        cout << "1 to add node. \n2 to print node \n3 to delete last node \n";
        cout << "4 to add node at a specific postion \n5 to delete node from a specific postion \n";
        cout << "6 to reverse the linked list and print \n7 to reverse the linked list with recursion and print\n";
        cout << "8 to print elements in reverse order\n0 to exit and print Linked List\n";
        cin >> operation;
        switch (operation)
        {
        case 0:
            cout << "Quiting.\n";
            break;
        case 1:
            cout << "Enter number for node : ";
            cin >> nodeData;
            addNode(nodeData);
            break;
        case 2:
            print();
            break;
        case 3:
            deleteNode();
            break;
        case 4:
            cout << "Enter number for node : ";
            cin >> nodeData;
            cout << "Enter position to insert node : ";
            cin >> insertPostion;
            addNodeAtN(nodeData, insertPostion);
            break;
        case 5:
            cout << "Enter position to delete : ";
            cin >> deletePosition;
            deleteNodeAtN(deletePosition);
            break;
        case 6:
            reverseList();
            print();
            break;
        case 7:
            reverseRecursion(head);
            print();
            break;
        case 8:
            cout << "The list in reverse is : ";
            printReverse(head);
            cout << endl;
            break;
        }
    }
}

void linkedList::addNode(int nodeData)
{
    node *tempNode = new node();
    tempNode->data = nodeData;
    if (head == NULL)
    {
        head = tempNode;
    }
    else
    {
        node *tempNode2 = head;
        while (tempNode2->next != NULL)
        {
            tempNode2 = tempNode2->next;
        }
        tempNode2->next = tempNode;
    }
}

void linkedList::addNodeAtN(int nodeData, int position)
{
    node *tempNode = new node();
    tempNode->data = nodeData;
    if (head == NULL)
    {
        cout << "Linked list empty, will append at first postion.";
        head = tempNode;
    }
    else if (position == 1)
    {
        tempNode->next = head;
        head = tempNode;
    }
    else
    {
        node *tempNode2 = head;
        for (int i = 1; i < position - 1; i++)
        {
            tempNode2 = tempNode2->next;
        }
        tempNode->next = tempNode2->next;
        tempNode2->next = tempNode;
    }
}

void linkedList::print()
{
    node *tempNode = head;
    if (head == NULL)
    {
        cout << "Linked list is empty !\n";
    }
    else
    {
        cout << "\nThe linked list is : ";
        while (tempNode != NULL)
        {
            cout << tempNode->data << "  ";
            tempNode = tempNode->next;
        }
        cout << endl;
    }
}

void linkedList::printReverse(node *tempNode)
{
    if (tempNode == NULL)
    {
        return;
    }
    printReverse(tempNode->next);
    cout << tempNode->data << " ";
    
}

void linkedList::deleteNode()
{
    node *temp = head;
    if (head == NULL)
    {
        cout << "List already empty.";
    }
    else if (head->next == NULL)
    {
        cout << "Element Deleted: " << head->data << endl;
        free(head);
        head = NULL;
    }
    else
    {
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }

    print();
}

void linkedList::deleteNodeAtN(int position)
{
    node *tempNode =  head;
    if (head == NULL)
    {
        cout << "List already empty.";
    }
    else if (position == 1)
    {
        head = tempNode->next;
        free(tempNode);
    }
    else
    {
        node *tempNode2 = head;
        for (int i = 1; i < position; i++)
        {
            tempNode2 = tempNode;
            tempNode = tempNode->next;
        }
        tempNode2->next = tempNode->next;
        free(tempNode);
    }

    print();
}

void linkedList::reverseList() 
{
    node *currentNode, *nextNode, *prevNode;
    currentNode = head;
    nextNode = prevNode = NULL;
    while (currentNode != NULL)
    {
        nextNode = currentNode->next;
        currentNode->next = prevNode;
        prevNode = currentNode;
        currentNode = nextNode;
    }
    head = prevNode;
}

void linkedList::reverseRecursion(node *tempNode)
{
    if(tempNode->next == NULL)
    {
        head = tempNode;
        return;
    }
    reverseRecursion(tempNode->next);
    node *recNode;
    recNode = tempNode->next;
    recNode->next = tempNode;
    tempNode->next = NULL; 
}

int main()
{
    linkedList makeList;
    makeList.inputDatafn();
    return 0;
}