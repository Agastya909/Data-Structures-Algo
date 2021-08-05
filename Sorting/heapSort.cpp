#include <iostream>
#include <utility>
using namespace std;

void heapify(int *array, int size, int index);
void heapSort(int *array, int size);
void print(int *array, int size);
void inputArray(int *array, int size);

int main()
{
    cout << "Enter size of the array : ";
    int size;
    cin >> size;
    int array[size];
    inputArray(array, size);
    cout << "Sorted array is : \n";
    heapSort(array, size);
    print(array, size);
    return 0;
}

void inputArray(int *array, int size)
{
    cout << "Enter elements for the array : \n";
    for(int i = 0; i<size; i++)
    {
        cin >> array[i];
    }
}

void print(int *array, int size)
{
    for(int i = 0; i<size; i++)
    {
        cout << array[i] << " ";
    }
}

void heapSort(int *array, int size)
{
    // first a max heap is created with the heapify function
    
    for (int i = size/2 - 1; i>=0; i--)
    {
        heapify(array, size, i);
    }
    
    // after max head is created with all the elements,
    // swap root and last elements and make a max heap
    // again and after every heapify, initial index is
    // moved back by one so that the largest element is 
    // not included in the heap again.

    for (int i = size-1; i >= 0; i--)
    {
        swap(array[0], array[i]);
        heapify(array, i, 0);
    }
}

void heapify(int *array, int size, int index)
{
    int parent = index;
    int leftChild = 2*index + 1;
    int rightChild = 2*index + 2;

    if(leftChild < size && array[leftChild] > array[parent])
    {
        parent = leftChild;
    }
    if(rightChild < size && array[rightChild] > array[parent])
    {
        parent = rightChild;
    }

    // exit condition for recursion
    // keep heapifying untill the heap is not max heap 
    // for the subtree for the particular index
    // ps. no actual tree is there, just visualising it.

    if(parent!=index)
    {
        swap(array[index], array[parent]);
        heapify(array, size, parent);
    }
}