// laba 2 N5

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <iterator>

using namespace std;


void AddUser(map<int, string>& phoneDirectory, set<string>& allUsers, int& usersNumber)
{
    cout << "new user's name: ";
    string userName;
    cin >> userName;

    set<string> allUsers_copy = allUsers;

    allUsers_copy.insert(userName);

    if (allUsers.size() == allUsers_copy.size())  // if name is unique => add
    {
        phoneDirectory[usersNumber] = userName;
        usersNumber++;
    }
}


void RemoveUser(map<int, string>& phoneDirectory)
{
    cout << "enter the number: ";
    int removeNumber;
    cin >> removeNumber;

    phoneDirectory.erase(removeNumber);
}


void FindUserName(map<int, string> phoneDirectory, int userKey)
{
    int leftBorder = 0;  // limiter on the left
    int rightBorder = phoneDirectory.size() - 1;  // limiter on the right

    map<int, string> :: iterator iter = phoneDirectory.begin();  // ???
    advance(iter, int(phoneDirectory.size() / 2));  // передвинутся на середину списка
                                                    // advance(iter, n) - передвинуться на n шагов вперед (-n - назад)

    for (int i = 0; i < phoneDirectory.size(); i++)  // бинарный поиск
    {
        if (userKey > iter->first)
        {
            leftBorder = iter->first;
            advance(iter, (leftBorder + rightBorder) / 2);
            continue;
        }

        if (userKey < iter->first)
        {
            rightBorder = iter->first;
            advance(iter, -(leftBorder + rightBorder) / 2);
            continue;
        }

        if (userKey == iter->first)
        {
            cout << phoneDirectory[iter->first];
            break;
        }
    }
}


int main()
{
    int usersNumber = 0;

    map<int, string> phoneDirectory;

    cout << "\ncommands: \nADD \nREMOVE \nFIND \nEXIT\n\n";

    while (true)
    {
        cout << "enter a command: ";
        string command;
        cin >> command;

        if (command == "ADD")
        {
            set<string> allUsers;
            AddUser(phoneDirectory, allUsers, usersNumber);
        }

        else if (command == "REMOVE")
            RemoveUser(phoneDirectory);

        else if (command == "FIND")
        {
            cout << "enter the user's key";
            int userKey;
            cin >> userKey;

            FindUserName(phoneDirectory, userKey);
        }

        else if (command == "EXIT")
            break;
    }

    return 0;
}
