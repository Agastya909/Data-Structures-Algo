#include <iostream>
using namespace std;

void splitArray(int *array, int size);
void mergeArrays(int *arrayL, int *arrayR, int *array, int leftLen, int rightLen);
void show(int *array, int size);
void inputArray(int *array, int size);

int main()
{
    cout << "Enter size of the array : ";
    int size;
    cin >> size;
    int array[size];
    inputArray(array, size);
    show(array, size);
    splitArray(array, size);
    show(array, size);
    return 0;
}

//This function splits the array into half 
void splitArray(int *array, int size)
{
    if (size < 2)
    {
        return; //exit condition for recursive call
    }
    int mid = size / 2; 
    int arrayLeft[mid], arrayRight[size - mid]; //split
    //copying the elements to left and right arrays *new*
    for (int i = 0; i < mid; i++)
    {
        arrayLeft[i] = array[i];
    }
    for (int j = 0; j < size - mid; j++)
    {
        arrayRight[j] = array[mid + j];
    }
    splitArray(arrayLeft, mid);
    splitArray(arrayRight, size - mid);
    mergeArrays(arrayLeft, arrayRight, array, mid, size-mid);
    // freeing the memory used making duplicate arrays
    free(arrayLeft);
    free(arrayRight);
}

void show(int *array, int size)
{
    cout << "Elements in the array are : ";
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << "  ";
    }
    cout << endl;
}

//this function merges the left and right half of a parent array into the
// parent array after sorting i.e. comparing the elements of two arrays
void mergeArrays(int *arrayL, int *arrayR, int *array, int leftLen, int rightLen)
{
    // index for the left, right and parent array
    int leftIndex, rightIndex, parentIndex;
    leftIndex = rightIndex = parentIndex = 0;
    // this while loops runs as long as both left and right arrays have at least 1 element each
    while (leftIndex < leftLen && rightIndex < rightLen)
    {
        if (arrayL[leftIndex] < arrayR[rightIndex])
        {
            array[parentIndex] = arrayL[leftIndex];
            leftIndex++;
        }
        else
        {
            array[parentIndex] = arrayR[rightIndex];
            rightIndex++;
        }
        parentIndex++;
    }
    // incase right array is used and left array has unfilled elements
    while (leftIndex < leftLen)
    {
        array[parentIndex] = arrayL[leftIndex];
        leftIndex++;
        parentIndex++;
    }
    // incase left array is used and right array has unfilled elements
    while (rightIndex < rightLen)
    {
        array[parentIndex] = arrayR[rightIndex];
        rightIndex++;
        parentIndex++;
    }
}

void inputArray(int *array, int size)
{
    cout << "Enter elements for the arrar : \n";
    for (int i = 0; i < size; i++)
    {
        cin >> array[i];
    }
}