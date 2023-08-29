// laba 1 N11 (not works)

#include <iostream>
#include <map>
#include <vector>

using namespace std;


void AddInformationAboutStudents(map<int, vector<string> >& boysHeightAndName, map<int, vector<string> >& girlsHeightAndName, const int& boysNumber, const int& girlsNumber)
{
    for (int i = 0; i < boysNumber; i++)  // filling out information about boys
    {
        cout << "boy name: ";
        string boyName;
        cin >> boyName;

        cout << boyName << "'s height: ";
        int boyHeight;
        cin >> boyHeight;

        while (boyHeight < 150 || boyHeight > 200)
        {
            cout << "repeat: ";
            cin >> boyHeight;
        }
        cout << endl;

        boysHeightAndName[boyHeight].push_back(boyName);
    }


    for (int i = 0; i < girlsNumber; i++)  // filling out information about girls
    {
        cout << "girl name: ";
        string girlName;
        cin >> girlName;

        cout << "girl height: ";
        int girlHeight;
        cin >> girlHeight;

        while (girlHeight < 150 || girlHeight > 200)
        {
            cout << "repeat: ";
            cin >> girlHeight;
        }

        boysHeightAndName[girlHeight].push_back(girlName);
    }

    cout << endl;
}


void WhoGirlDating(map<int, vector<string> > boysHeightAndName, map<int, vector<string> > girlsHeightAndName)
{
    bool isEveryGirlWithBoy = true;

    

    for (const auto& girl : girlsHeightAndName)
    {
        for (const auto& boy : boysHeightAndName)
        {
            if (girl.first < boy.first)
            {
                cout << girl.second << " with " << boy.second;
                break;
            }
        }
    }
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
        cout << endl << "Not every girl has a boyfrienf (NO)\n";
        return 0;
    }

    map<int, vector<string> > boysHeightAndName;
    map<int, vector<string> > girlsHeightAndName;

    AddInformationAboutStudents(boysHeightAndName, girlsHeightAndName, boysNumber, girlsNumber);

    WhoGirlDating(boysHeightAndName, girlsHeightAndName);

    return 0;
}
