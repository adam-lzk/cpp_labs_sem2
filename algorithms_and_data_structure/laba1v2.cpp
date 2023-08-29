// laba 1 N11 (not works)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void AddStudentsHeight(int* boysHeight, int* girlsHeight)
{
    cout << "boys height: ";

    for (int i = 0; i < sizeof(boysHeight) / sizeof(int); i++)  // add boys height
    {
        int height;
        cin >> height;

        while (height < 150 || height > 200)
        {
            cout << "repeat: ";
            cin >> height;
        }

        boysHeight[i] = height;
    }

    cout << "girls height: ";

    for (int i = 0; i < sizeof(girlsHeight) / sizeof(int); i++)  // add girls height
    {
        int height;
        cin >> height;

        while (height < 150 || height > 200)
        {
            cout << "repeat: ";
            cin >> height;
        }

        girlsHeight[i] = height;
    }
}


void IsAllGirlsDating()
{

}


int main()
{
    cout << endl << "number of boys: ";
    int boysNumber;
    cin >> boysNumber;

    cout << "number of girls: ";
    int girlsNumber;
    cin >> girlsNumber;
    cout << endl;

    if (boysNumber < girlsNumber)
    {
        cout << endl << "NO\n";
        return 0;
    }

    const int SIZE1 = boysNumber;
    const int SIZE2 = girlsNumber;

    int boysHeight[SIZE1];
    int girlsHeight[SIZE2];

    AddStudentsHeight(boysHeight, girlsHeight);

    sort(boysHeight.begin(), boysHeight.end());

    IsAllGirlsDating();

    return 0;
}