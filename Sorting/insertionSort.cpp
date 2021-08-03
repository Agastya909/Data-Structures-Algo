#include <iostream>
using namespace std;

void insertionSort(int array[], int size)
{
    int key=1, i, j;
    for (int key = 0; key < size; key++)
    {
        j=key;
        i=key-1;
        while (i>=0 && array[j] < array[i])
        {
            swap(array[j], array[i]);
            i--;
            j--;
        }
    }
}

void inputArray(int array[], int size)
{
    int i = 0;
    cout << "Enter elements for the array : ";
    for(int i=0; i<size; i++)
    {
        cin >> array[i];
    }
}

void show(int array[], int size)
{
    int i = 0;
    cout << "The array elements are : " << endl;
    for(int i=0; i<size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main()
{
    int size;
    cout << "Enter the length for the array : ";
    cin >> size;
    int array[size];
    inputArray(array, size);    
    insertionSort(array, size);
    show(array, size);
    return 0;
}