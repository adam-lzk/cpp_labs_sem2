// Функция, возвращающая ссылку на максимальное число, встречающееся в заданном массиве ровно 2 раза
// g++ -std=c++11 1.3.cpp -o 1.3

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int& CheckMax(int& item1, int& item2, int& zero)
{
    if (item1 != item2)  // проверка 2-х максимальных элементов
    {
        return item1;
    }
    return zero;
}

int& CheckMid(int& item1, int& item2, int& item3, int& zero)
{
    if (item1 != item2 && item2 != item3)  // проверка элементов вектора (от предпоследнего до 2-го)
    {
        return item2;
    }
    return zero;
}

int& CheckMin(int& item1, int& item2, int& zero)
{
    if (item1 != item2)  // проверка 2-х минимальных элементов
    {
        return item2;
    }
    return zero;
}


int main()
{
    int size;
    cin >> size;

    vector<int> numbers(size);

    for (auto& item : numbers)
        cin >> item;

    sort(numbers.begin(), numbers.end());


    int maxIndex = numbers.size() - 1;
    int zero = 0;
    int answer = 0;

    for (int i = 1; i == 1; i++)
    {
        answer = CheckMax(numbers[maxIndex], numbers[maxIndex - 1], zero);  // проверка 2-х максимальных элементов

        for (int i = maxIndex - 1; i > 0; i--)  // проверка элементов вектора (от предпоследнего до 2-го)
            answer = CheckMid(numbers[i - 1], numbers[i], numbers[i + 1], zero);

        answer = CheckMin(numbers[0], numbers[1], zero);  // проверка 2-х минимальных элементов
    }


    cout << "unique maximum: " << answer << endl;

    return 0;
}
