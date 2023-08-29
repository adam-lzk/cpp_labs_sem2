// Сумма матриц, возведенных в степень от 0 до n

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

const int SIZE = 3;

void ExponentionOfMatrix(int matrix[SIZE][SIZE], int poweredMatrix[SIZE][SIZE], int poweredMatrix_copy[SIZE][SIZE], int power)
{
    for (int i = 0; i < SIZE; i++)  // обнуление первоначальной матрицы
    {
        for (int j = 0; j < SIZE; j++)
        {
            poweredMatrix[i][j] = 0;
        }
    }

    if (power > 1)
    {
        for (int pow = 2; pow <= power; pow++)  // матрица перемножится сама на себя power-1 раз
        {
            for (int i = 0; i < SIZE; i++)  // перемножение матриц
            {
                for (int j = 0; j < SIZE; j++)
                {
                    for (int k = 0; k < SIZE; k++)
                    {
                        poweredMatrix[i][j] += poweredMatrix_copy[i][k] * matrix[k][j];  // A^3 = A^2 * A
                    }
                }
            }

            for (int i = 0; i < SIZE; i++)  // копирование полученной матрицы
            {
                for (int j = 0; j < SIZE; j++)
                {
                    poweredMatrix_copy[i][j] = poweredMatrix[i][j];
                }
            }

            if (pow < power)  // обнуление первоначальной матрицы (на последней итерации матрица не обнулится)
            {
                for (int i = 0; i < SIZE; i++)
                {
                    for (int j = 0; j < SIZE; j++)
                    {
                        poweredMatrix[i][j] = 0;
                    }
                }
            }
        }
    }

    else if (power == 1)  // матрица в первой степени
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                poweredMatrix[i][j] = matrix[i][j];
            }
        }
    }

    else if (power == 0)  // создание единичной матрицы
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                if (i != j)
                {
                    poweredMatrix[i][j] = 0;
                }
                else poweredMatrix[i][j] = 1;
            }
        }
    }
}


void SumOfExponentiatedMatrices(int poweredMatrix[SIZE][SIZE], int resultMatrix[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            resultMatrix[i][j] += poweredMatrix[i][j];
        }
    }
}


int main()
{
    int matrix[SIZE][SIZE];
    int poweredMatrix[SIZE][SIZE];
    int poweredMatrix_copy[SIZE][SIZE];
    int resultMatrix[SIZE][SIZE] = {};

    cout << endl << "fill the 3*3 matrix: ";

    for (int i = 0; i < SIZE; i++)  // заполнение матрицы
    {
        for (int j = 0; j < SIZE; j++)
        {
            cin >> matrix[i][j];
            poweredMatrix_copy[i][j] = matrix[i][j];
        }
    }

    cout << "power: ";
    int power;
    cin >> power;
    cout << endl;

    for (int pow = 0; pow <= power; pow++)
    {
        ExponentionOfMatrix(matrix, poweredMatrix, poweredMatrix_copy, pow);

        SumOfExponentiatedMatrices(poweredMatrix, resultMatrix);
    }

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            cout << setw(5) << resultMatrix[i][j];
        }
        cout << endl << endl;
    }

    return 0;
}
