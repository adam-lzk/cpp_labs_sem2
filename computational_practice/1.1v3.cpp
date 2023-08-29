// Закручивание двумерного массива по спирали (работает для массива любого размера)

#include <iostream>
#include <iomanip>

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


void SpiralArray(int** arr, int size)
{
    int row = 0, column = size - 1;  // start position
    int rowMax = size - 1, columnMax = size - 1, rowMin = 0, columnMin = 0;
    int a = 1;

    for (int i = 0; ; i++)
    {
        for (; column != columnMin; column--)
        {
            arr[row][column] = a;
            a++;
            if (a > size*size) break;
        }
        rowMin++;
        if (a > size*size) break;


        for (; row != rowMax; row++)
        {
            arr[row][column] = a;
            a++;
            if (a > size*size) break;
        }
        columnMin++;
        if (a > size*size) break;


        for (; column != columnMax; column++)
        {
            arr[row][column] = a;
            a++;
            if (a > size*size) break;
        }
        rowMax--;
        if (a > size*size) break;


        for (; row != rowMin; row--)
        {
            arr[row][column] = a;
            a++;
            if (a > size*size) break;
        }
        columnMax--;
        if (a > size*size) break;
    }
}


void ArrayOutput(int** arr, int size)
{
    cout << endl;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << setw(3) << arr[i][j] << " ";
        }
        cout << endl << endl;
    }
}


void DeleteArray(int** arr, int size)
{
    for (int i = 0; i < size; i++)
        delete [] arr[i];

    delete [] arr;
}


int main()
{
    int size;
    cout << "size = ";
    cin >> size;

    int** arr = CreateArray(size);

    SpiralArray(arr, size);

    ArrayOutput(arr, size);

    DeleteArray(arr, size);

    return 0;
}
