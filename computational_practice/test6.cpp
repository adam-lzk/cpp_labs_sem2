// g++ -std=c++11 test4.cpp -o test4

#include <iostream>
#include <algorithm>

using namespace std;


int** CreateArray(int size)
{
    int** arr = new int* [size];

    for (int i = 0; i < size; i++)
    {
        arr[i] = new int [size];
    }

    return arr;
}


void DeleteArray(int** arr, int size)
{
    for (int i = 0; i < size; i++)
        delete [] arr[i];

    delete [] arr;
}


void Comparison(int** arr, int size)
{
    bool entered = 0;

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] + arr[j] == num)
            {
                cout << arr[i] << " " << arr[j] << endl;
                entered = 1;
                break;
            }
        }

        if (entered == 1)
            break;
    }
}


int main()
{
    int size;
    cout << "size = ";
    cin >> size;

    int num;
    cout << "number = ";
    cin >> num;

    int** arr = CreateArray(size);

    Comparison(arr, size);

    DeleteArray(arr, size);

    return 0;
}