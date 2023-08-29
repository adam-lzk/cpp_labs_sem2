#include <iostream>

using namespace std;

int main()
{
    const int SIZE = 5;
    int arr[SIZE] = {1, 3, 5, 7, 9};

    for (int i = 0; i < SIZE; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl << endl;


    int *pArr = arr;

    cout << "arr\t" << *arr << "\t" << arr << endl;
    cout << "pArr\t" << *pArr << "\t" << pArr << endl << endl;

    for (int i = 0; i < SIZE; i++)
    {
        cout << pArr[i] << " ";
    }
    cout << endl;


    for (int i = 0; i < SIZE; i++)
    {
        cout << *(pArr + i) << " ";
    }
    cout << endl;

    cout << *pArr << " " << *(pArr + 1) << " " << *(pArr + 2) << endl;

    cout << "elements of array in memory:\n";
    for (int i = 0; i < SIZE; i++)
    {
        cout << (pArr + i) << endl;
    }

    return 0;
}
