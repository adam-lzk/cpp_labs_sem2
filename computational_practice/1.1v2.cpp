// Закручивание двумерного массива по спирали (через динамический массив)

#include <iostream>
#include <iomanip>

using namespace std;

int size = 5;

void SpiralArray(int **arr)
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


void ArrayOutput(int **arr)
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


int main()
{
    int **arr = new int* [size];  // создание двумерного динамического массива

    for (int i = 0; i < size; i++)
    {
        arr[i] = new int [size];
    }

    SpiralArray(arr);

    ArrayOutput(arr);

    for (int i = 0; i < size; i++)  // удаление
    {
        delete [] arr[i];
    }

    delete [] arr;

    return 0;
}
