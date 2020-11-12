#include <iostream>
using namespace std;
void inputArray(int *ptrArray, int size)
{
    for (int i = 0; i < size; i++)
    {
        ptrArray[i] = i;
    }
    
}
void outputArray(int *ptrArray, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << ptrArray[i] << " ";
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    int size = 10;
    int *ptrArray = new int[size];
    inputArray(ptrArray, size);
    size++;
    // int *ptrNewArray = new int[size];
    // ptrNewArray = ptrArray;
    // ptrNewArray[size - 1] = 200;
    // delete [] ptrArray;
    // ptrArray = new int[size];
    // ptrArray = ptrNewArray;
    // outputArray(ptrArray, size);
    // delete [] ptrNewArray;
    ptrArray[size - 1] = 200;
    outputArray(ptrArray, size);
    for (int i = 0; i < size; i++)
    {
        cout << (int)(ptrArray + i) << endl;
    }

    cout << "end" << endl;
    
    delete [] ptrArray;
    return 0;
}
