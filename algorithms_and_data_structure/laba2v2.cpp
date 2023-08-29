// laba 2 N5

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


void AddUser(vector<string>& phoneDirectory)
{
    cout << "new user's name: ";
    string userName;
    cin >> userName;

    if ( find(phoneDirectory.begin(), phoneDirectory.end(), userName) == phoneDirectory.end() )  // if the name is not in the vector => add
    {
        phoneDirectory.push_back(userName);
    }
    else cout << "this name is alredy in the phone directory\n";
}


void RemoveUser(vector<string>& phoneDirectory)
{
    cout << "enter the number: ";
    int removeNumber;
    cin >> removeNumber;

    phoneDirectory.erase(phoneDirectory.begin() + removeNumber);
}


void FindUserName(vector<string> phoneDirectory, int userIndex)
{
    int leftBorder = 0;  // limiter on the left
    int rightBorder = phoneDirectory.size() - 1;  // limiter on the right

    int index = phoneDirectory.size() / 2;  // индекс серединного элемента вектора

    for (int i = 0; i < phoneDirectory.size(); i++)  // бинарный поиск
    {
        if (userIndex > index)
        {
            leftBorder = index;
            index = (leftBorder + rightBorder) / 2;
            continue;
        }

        if (userIndex < index)
        {
            rightBorder = index;
            index = (leftBorder + rightBorder) / 2;
            continue;
        }

        if (userIndex == index)
        {
            cout << phoneDirectory[index] << endl;
            break;
        }
    }
}


int main()
{
    vector<string> phoneDirectory;  // нумерация в справочнике начинается с нуля

    cout << "\ncommands:\n    ADD\n    REMOVE\n    FIND\n    EXIT\n";

    while (true)
    {
        cout << "\nenter a command: ";
        string command;
        cin >> command;

        if (command == "ADD")
        {
            AddUser(phoneDirectory);
        }

        else if (command == "REMOVE")
            RemoveUser(phoneDirectory);

        else if (command == "FIND")
        {
            cout << "enter the user's key: ";
            int userIndex;
            cin >> userIndex;

            FindUserName(phoneDirectory, userIndex);
        }

        else if (command == "EXIT")
            break;
    }

    return 0;
}
