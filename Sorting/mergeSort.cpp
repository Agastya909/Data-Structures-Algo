#include <iostream>
using namespace std;

void splitArray(int array[], int size);
void mergeArrays(int arrayL[], int arrayR[], int array[]);
void inputArray(int array[], int size)
{
    cout << "Enter elements for the arrar : \n";
    for (int i = 0; i < size; i++)
    {
        cin >> array[i];
    }
    
}

void show(int array[], int size)
{
    cout << "Elements in the array are : ";
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << "  ";
    }
    cout << endl;
}

int main()
{
    cout << "Enter size of the array : ";
    int size;
    cin >> size;
    int array[size];
    inputArray(array, size);
    show(array, size);
}