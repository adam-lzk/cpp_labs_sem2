// Найти числа, встречающиеся в исходной последовательности (размера 10^9) ровно два раза

#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

int main()
{
    srand(time(NULL));

    const int SIZE = 10000;
    const int numberOfRepetition = 2;
    int numbersAndNumberOfRepetition[SIZE] = {};

    for (int i = 0; i < pow(10, 3); i++)
    {
        numbersAndNumberOfRepetition[rand() % SIZE]++;  // 0 ... 9999
    }

    for (int i = 0; i < SIZE; i++)
    {
        if (numbersAndNumberOfRepetition[i] == numberOfRepetition)
            cout << i << " ";
    }

    cout << endl;

    return 0;
}
