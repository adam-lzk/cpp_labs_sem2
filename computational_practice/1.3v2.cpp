// Функция, возвращающая ссылку на максимальное число, встречающееся в заданном массиве ровно 2 раза
// g++ -std=c++11 1.3v2.cpp -o 1.3v2

#include <iostream>
#include <map>
#include <vector>

using namespace std;

int& MaxUniqueNumber(const map<int, int>& numbersInRepeats, vector<int>& uniqueNumbers)
{
    for (const auto& pairs : numbersInRepeats)
    {
        if (pairs.second == 1)
        {
            uniqueNumbers.push_back(pairs.first);
        }
    }

    return uniqueNumbers[uniqueNumbers.size() - 1]; // последний элемент ветора - самый большой;
}

int main()
{
    int size;
    cout << "size = ";
    cin >> size;

    vector<int> numbers(size);

    for (auto& item : numbers)
        cin >> item;

    map<int, int> numbersInRepeats;

    for (auto item : numbers)
    {
        numbersInRepeats[item]++;
    }

    vector<int> uniqueNumbers;

    int answer = MaxUniqueNumber(numbersInRepeats, uniqueNumbers);

    cout << "max unique number = " << answer << endl;

    return 0;
}
