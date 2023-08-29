#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;


int** CreateMatrix(int rows, int columns)
{
    int** mattrix = new int* [rows];

    for (int i = 0; i < rows; i++)
    {
        mattrix[i] = new int [columns];
    }

    return mattrix;
}


void FillMatrix(int** matrix, int rows, int columns)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            matrix[i][j] = rand() % 100;
        }
    }
}


void MatrixOutput(int** matrix, int rows, int columns)
{
    cout << endl;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            cout << setw(3) << matrix[i][j] << " ";
        }
        cout << endl << endl;
    }
}


void PrintMaxElementInRow(int** matrix, int rows, int columns)
{
    cout << "enter the row number: ";
    int rowNumber;
    cin >> rowNumber;  // < rows

    int maxElement = 0;

    for (int j = 0; j < columns; j++)
    {
        if (matrix[rowNumber][j] > maxElement)
            maxElement = matrix[rowNumber][j];
    }

    cout << "max element in row: " << maxElement << endl << endl;
}


void PrintMinElementInColumn(int** matrix, int rows, int columns)
{
    cout << "enter the column number: ";
    int columnNumber;
    cin >> columnNumber;  // < column

    int minElement = INT_MAX;

    for (int i = 0; i < rows; i++)
    {
        if (matrix[i][columnNumber] < minElement)
            minElement = matrix[i][columnNumber];
    }

    cout << "min element in column: " << minElement << endl << endl;
}





void Replace(int** matrix, int rows, int columns)
{
    cout << "enter the row number: ";
    int rowNumber;
    cin >> rowNumber;  // < rows

    int columnOfMinElement;
    int minElement = INT_MAX;

    for (int j = 0; j < columns; j++)
    {
        if (matrix[rowNumber][j] < minElement)
        {
            minElement = matrix[rowNumber][j];
            columnOfMinElement = j;
        }
    }


    cout << endl;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if ((i == rowNumber) && (j == columnOfMinElement))
            {
                cout << setw(3) << '*' << " ";
            }
            else cout << setw(3) << matrix[i][j] << " ";
        }
        cout << endl << endl;
    }
}






void DeleteMatrix(int** mattrix, int rows, int columns)
{
    for (int i = 0; i < rows; i++)
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

    PrintMaxElementInRow(matrix, rows, columns);

    PrintMinElementInColumn(matrix, rows, columns);

    Replace(matrix, rows, columns);

    DeleteMatrix(matrix, rows, columns);

    return 0;
}
