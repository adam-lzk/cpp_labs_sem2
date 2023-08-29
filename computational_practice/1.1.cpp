// Закручивание двумерного массива по спирали

#include <iostream>
#include <iomanip>

using namespace std;

const int SIZE = 5;

void SpiralArray(int arr[SIZE][SIZE])
{
    int row = 0, column = 4;  // start position
    int rowMax = 4, columnMax = 4, rowMin = 0, columnMin = 0;
    int a = 1;

    for (int i = 0; i < 3; i++)  // i < ??
    {
        for (; column != columnMin; column--)
        {
            arr[row][column] = a;
            a++;
        }
        rowMin++;


        for (; row != rowMax; row++)
        {
            arr[row][column] = a;
            a++;
        }
        columnMin++;


        for (; column != columnMax; column++)
        {
            arr[row][column] = a;
            a++;
        }
        rowMax--;


        for (; row != rowMin; row--)
        {
            arr[row][column] = a;
            a++;

            if (a >= 25)
            break;
        }
        columnMax--;
    }
}


void ArrayOutput(int arr[SIZE][SIZE])
{
    cout << endl;

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            cout << setw(3) << arr[i][j] << " ";
        }
        cout << endl << endl;
    }
}


int main()
{
    int arr[SIZE][SIZE];

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            arr[i][j] = 0;
        }
    }

    SpiralArray(arr);

    ArrayOutput(arr);

    return 0;
}
