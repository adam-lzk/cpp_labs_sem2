#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;


int** CreateMatrix(int rows, int columns)
{
    int** mattrix = new int* [columns];

    for (int i = 0; i < columns; i++)
    {
        mattrix[i] = new int [rows];
    }

    return mattrix;
}


void FillMatrix(int** matrix, int rows, int columns)
{
    for (int i = 0; i < columns; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            matrix[i][j] = rand() % 100;
        }
    }
}


void MatrixOutput(int** matrix, int rows, int columns)
{
    cout << endl;

    for (int i = 0; i < columns; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            cout << setw(3) << matrix[i][j] << " ";
        }
        cout << endl << endl;
    }
}


void MaxElementInRow(int** matrix, int rows, int columns)
{
    cout << "enter the row number: ";
    int rowNumber;
    cin >> rowNumber;  // < rows

    int maxElement = 0;

    for (int i = 0; i < columns; i++)
    {
        if (matrix[rowNumber][i] > maxElement)
            maxElement = matrix[rowNumber][i];
    }

    cout << "max element in row: " << maxElement << endl << endl;
}


void MinElementInColumn(int** matrix, int rows, int columns)
{
    cout << "enter the column number: ";
    int columnNumber;
    cin >> columnNumber;  // < column

    int minElement = INT_MAX;

    for (int j = 0; j < rows; j++)
    {
        if (matrix[j][columnNumber] < minElement)
            minElement = matrix[j][columnNumber];
    }

    cout << "min element in column: " << minElement << endl << endl;
}


void DeleteMatrix(int** mattrix, int rows, int columns)
{
    for (int i = 0; i < columns; i++)
        delete [] mattrix[i];

    delete [] mattrix;
}


int main()
{
    srand(time(NULL));

    cout << "\nnumber of rows: ";
    int rows;
    cin >> rows;

    cout << "number of columns: ";
    int columns;
    cin >> columns;

    int** matrix = CreateMatrix(rows, columns);

    FillMatrix(matrix, rows, columns);

    MatrixOutput(matrix, rows, columns);

    MaxElementInRow(matrix, rows, columns);

    MinElementInColumn(matrix, rows, columns);

    DeleteMatrix(matrix, rows, columns);

    return 0;
}
