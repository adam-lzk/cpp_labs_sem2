// laba 2 N5 (works)
// g++ -std=c++11 laba2v3.cpp -o laba2v3

#include <iostream>
#include <map>

using namespace std;


void AddUser(map<string, string>& phoneDirectory)
{
    string userKey;
    bool isKeyCorrect = true;

    do
    {
        cout << "new user's key: ";
        cin >> userKey;

        for (const auto& item : phoneDirectory)  // replacement for .count()
        {
            if (userKey == item.first)
            {
                cout << "the key is alredy there, try another one\n";
                isKeyCorrect = false;
                break;
            }
            isKeyCorrect = true;
        }

    } while (!isKeyCorrect);

    cout << "new user's name: ";
    string userName;
    cin >> userName;

    phoneDirectory[userKey] = userName;
}


void RemoveUser(map<string, string>& phoneDirectory)
{
    cout << "enter the key of the user being deleted: ";
    string userKey;
    cin >> userKey;

    phoneDirectory.erase(userKey);  // ???
}


void FindUserNameByKey(map<string, string> phoneDirectory)  // const & ???
{
    cout << "enter the key of the user you are looking for: ";
    string userKey;
    cin >> userKey;

    if (phoneDirectory[userKey] == "")
    {
        cout << "user not found\n";
    }
    else
    {
        cout << "name: ";
        cout << phoneDirectory[userKey] << endl;
    }
}


int main()
{
    map<string, string> phoneDirectory;

    cout << "\ncommands: \nADD \nREMOVE \nFIND \nEXIT\n\n";

    while (true)
    {
        cout << "enter a command: ";
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
            FindUserNameByKey(phoneDirectory);
        }

        else if (command == "EXIT")
            break;

        else cout << "command not found\n";
    }

    return 0;
}
