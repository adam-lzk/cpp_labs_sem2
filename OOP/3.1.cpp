// 4.1
// g++ -std=c++11 3.1.cpp -o 3.1

#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

int main()
{
    vector<char> text(20);

    for (char& letter : text)
    {
        cin >> letter;
    }


    map<char, int> lettersAndCounter;

    for (char letter : text)
    {
        lettersAndCounter[letter]++;
    }


    set<char> uniqueLetters;

    for (char letter : text)
    {
        uniqueLetters.insert(letter);
    }


    for (const auto& item : lettersAndCounter)
    {
        cout << item.first << ": " << item.second << endl;
    }

    cout << endl;

    for (const char& letter : uniqueLetters)
    {
        cout << letter;
    }

    cout << endl;

    return 0;
}
