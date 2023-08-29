#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int size;
    cout << "size = ";
    cin >> size;

    int *arr1 = new int[size];  // создание динамического массива

    cout << endl;

    for (int i = 0; i < size; i++) // заполнение и вывод
    {
        arr1[i] = i + 1;
        cout << arr1[i] << " ";
    }

    cout << endl << endl;

    delete [] arr1;  // удаление


    ////////


    int **arr2 = new int* [size];  // создание двумерного динамического массива

    for (int i = 0; i < size; i++)
    {
        arr2[i] = new int [size];
    }

    ////////

    int a = 1;

    for (int i = 0; i < size; i++)  // заполнение и вывод
    {
        for (int j = 0; j < size; j++)
        {
            arr2[i][j] = a;
            a++;

            cout << setw(3) << arr2[i][j];
        }
        cout << endl;
    }

    ////////

    for (int i = 0; i < size; i++)  // удаление
    {
        delete [] arr2[i];
    }

    delete [] arr2;

    return 0;
}
