// Возведение матрицы в степень

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

const int SIZE = 9;
const int matrixOrder = sqrt(SIZE);

void ExponentionOfMatrix(int matrix[SIZE], int poweredMatrix[SIZE], int poweredMatrix_copy[SIZE], int power)
{
    for (int i = 0; i < SIZE; i++)  // обнуление первоначальной матрицы
    {
        poweredMatrix[i] = 0;
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
            poweredMatrix[i] = matrix[i];
        }
    }

    else if (power == 0)  // создание единичной матрицы
    {
        poweredMatrix[0] = 1;

        for (int i = 1; i < SIZE; i++)
        {
            if (i % (matrixOrder + 1) == 0)
            {
                poweredMatrix[i] = 1;
            }
            else poweredMatrix[i] = 0;
        }
    }
}


int main()
{
    int matrix[SIZE];
    int poweredMatrix[SIZE];
    int poweredMatrix_copy[SIZE];

    cout << endl << "fill the 3*3 matrix: ";

    for (int i = 0; i < SIZE; i++)  // заполнение матрицы
    {
        cin >> matrix[i];
        poweredMatrix_copy[i] = matrix[i];
    }

    cout << "power: ";
    int power;
    cin >> power;
    cout << endl;

    ExponentionOfMatrix(matrix, poweredMatrix, poweredMatrix_copy, power);

    for (int i = 0; i < SIZE; i++)
    {
        cout << setw(5) << poweredMatrix_copy[i];
    }

    return 0;
}
