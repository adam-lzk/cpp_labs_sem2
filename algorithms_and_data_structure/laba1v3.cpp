// laba 1 N11 (not works)
// g++ -std=c++11 laba1v3.cpp -o laba1v3

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void AddStudentsHeight(vector<int>& boysHeight, vector<int>& girlsHeight)
{
    cout << "boys height: ";

    for (int& height : boysHeight)  // add boys height
    {
        cin >> height;

        while (height < 150 || height > 200)
        {
            cout << "repeat: ";
            cin >> height;
        }
    }

    cout << "\ngirls height: ";

    for (int& height : girlsHeight)  // add girls height
    {
        cin >> height;

        while (height < 150 || height > 200)
        {
            cout << "repeat: ";
            cin >> height;
        }
    }
}


bool IsAllGirlsDating(const vector<int>& boysHeight, const vector<int>& girlsHeight)
{
    for (int girlsIter = 0; girlsIter < girlsHeight.size(); girlsIter++)
    {
        for (int boysIter = girlsIter; boysIter < boysHeight.size(); boysIter++)
        {
            if (boysHeight[boysIter] > girlsHeight[girlsIter])
            {
                break;
            }
            else return false;
        }
    }

    return true;
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
        cout << "NO\n";
        return 0;
    }

    vector<int> boysHeight(boysNumber);
    vector<int> girlsHeight(girlsNumber);

    AddStudentsHeight(boysHeight, girlsHeight);

    sort(boysHeight.end(), boysHeight.begin());
    sort(girlsHeight.end(), girlsHeight.begin());

    bool isEveryGirlWithBoy = IsAllGirlsDating(boysHeight, girlsHeight);

    if (isEveryGirlWithBoy)
    {
        cout << "YES";
    }
    else cout << "NO";

    return 0;
}
