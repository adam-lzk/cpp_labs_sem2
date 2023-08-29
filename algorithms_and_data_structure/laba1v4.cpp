// laba 1 N11 (works)
// g++ -std=c++11 laba1v4.cpp -o laba1v4

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


bool IsAllGirlsDating(const vector<int>& boysHeight, const vector<int>& girlsHeight)
{
    for (int i = 0; i < boysHeight.size(); i++)
    {
        if (boysHeight[i] > girlsHeight[i])
        {
            continue;
        }
        else return false;
    }

    return true;
}


int main()
{
    cout << "\nnumber of boys: ";
    int boysNumber;
    cin >> boysNumber;

    cout << "\nnumber of girls: ";
    int girlsNumber;
    cin >> girlsNumber;

    if (boysNumber < girlsNumber)
    {
        cout << "\nNO\n\n";  // Not every girl has a boyfrienf
        return 0;
    }


    cout << "\nboys' height:\n";

    vector<int> boysHeight(boysNumber);

    for (int& height : boysHeight)
    {
        cin >> height;
    }


    cout << "\ngirls' height:\n";

    vector<int> girlsHeight(girlsNumber);

    for (int& height : girlsHeight)
    {
        cin >> height;
    }


    sort(begin(boysHeight), end(boysHeight), greater<int>());  // сортировка по убыванию
    sort(begin(girlsHeight), end(girlsHeight), greater<int>());


    if (IsAllGirlsDating(boysHeight, girlsHeight))
    {
        cout <<  "\nYES\n\n";  // Every girl has a boyfrienf
    }
    else cout << "\nNO\n\n";  // Not every girl has a boyfrienf

    return 0;
}
