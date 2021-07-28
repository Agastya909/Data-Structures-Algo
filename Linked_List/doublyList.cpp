#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node *prev;
    node()
    {
        next = NULL;
    }
};

class linkedList
{
public:
    node *head;
    node *tail;
    void inputData();
    void addElement(int data);
    void addElementAtN(int data, int position);
    void deleteLast();
    void deleteAtN(int positon);
    void print();
    void printReverse();
    linkedList()
    {
        head = NULL;
    }
};

void linkedList::inputData()
{
    int operation, nodeData, insertPostion, deletePosition;
    while (operation != 0)
    {
        cout << "1 to add node. \n2 to print node \n3 to delete last node and print list\n";
        cout << "4 to add node at a specific postion \n5 to delete node from a specific postion \n";
        cout << "6 to print elements in reverse order\n0 to exit and print Linked List\n";
        cin >> operation;
        switch (operation)
        {
        case 0:
            cout << "Quiting.\n"; 
            break;
        case 1:
            cout << "Enter number for node : ";
            cin >> nodeData;
            addElement(nodeData);
            break;
        case 2:
            print();
            break;
        case 3:
            deleteLast();
            print();
            break;
        case 4:
            cout << "Enter number for node : ";
            cin >> nodeData;
            cout << "Enter position to insert node : ";
            cin >> insertPostion;
            addElementAtN(nodeData, insertPostion);
            break;
        case 5:
            cout << "Enter position to delete : ";
            cin >> deletePosition;
            deleteAtN(deletePosition);
            break;
        case 6:
            cout << "The list in reverse is : ";
            printReverse();
            cout << endl;
            break;
        }
    }
}

void linkedList::addElement(int data)
{
    node *tempNode = new node();
    tempNode->data = data;
    if (head == NULL)
    {
        head = tempNode;
        tail = tempNode;
        tempNode->prev = NULL;
    }
    else
    {
        node *tempNode2 = tail;
        tempNode->prev = tail;
        tempNode2->next = tempNode;
        tail = tempNode;
    }
}

void linkedList::addElementAtN(int data, int position)
{
    node *tempNode = new node();
    tempNode->data = data;
    if(head == NULL)
    {
        head = tempNode;
        tail = tempNode;
        tempNode->prev = NULL;
    } 
    else if(position == 1)
    {
        node *tempNode2 = head;
        tempNode2->prev = tempNode;
        tempNode->prev = NULL;
        tempNode->next = tempNode2;
        head = tempNode;
    } 
    else
    {
        node *tempNode2 = head;
        for (int i = 1; i < position-1; i++)
        {
            tempNode2 = tempNode2->next;
        }
        tempNode->prev = tempNode2;
        tempNode->next = tempNode2->next;
        tempNode2->next = tempNode;
        tempNode->next->prev = tempNode;
        
    }
    
}

void linkedList::print()
{
    node *tempNode = head;
    if (head == NULL)
    {
        cout << "List is empty!" << endl;
    }
    else
    {
        cout << "The list is : ";
        while (tempNode != NULL)
        {
            cout << tempNode->data << " ";
            tempNode = tempNode->next;
        }
        cout << endl;
    }
}

void linkedList::printReverse()
{
    node *tempNode = tail;
    while (tempNode != NULL)
    {
        cout << tempNode->data << " ";
        tempNode = tempNode->prev;
    }
    cout << endl;
}

void linkedList::deleteLast()
{
    if (head == NULL)
    {
        return;
    }
    else if (head == tail)
    {
        node *tempNode = head;
        head = tail = NULL;
        free(tempNode);
    }
    else
    {
        node *tempnode2 = tail;
        tail = tempnode2->prev;
        tempnode2->prev->next = NULL;
        free(tempnode2);
    }
}

void linkedList::deleteAtN(int position)
{
    node *tempNode = head;
    if(head == NULL)
    {
        cout << "List is already empty.";
    }
    else if(position == 1)
    {
        head = tempNode->next;
        tempNode->next->prev = NULL;
        free(tempNode);
    }
    else
    {
        for (int i = 1; i < position; i++)
        {
            tempNode = tempNode->next;
        }
        tempNode->prev->next = tempNode->next;
        tempNode->next->prev = tempNode->prev;
        free(tempNode);
    }
    
}

int main()
{
    linkedList makeList;
    makeList.inputData();
    return 0;
}