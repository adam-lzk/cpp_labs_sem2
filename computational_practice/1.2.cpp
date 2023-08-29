// Сортировка вектора строк
// компиляция - g++ -std=c++11 1.2.cpp -o 1.2

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    vector<string> words;
    string str;

    for (int i = 0; i < 5; i++)
    {
        cin >> str;
        words.push_back(str);
    }

    sort(begin(words), end(words));

    for (string a : words)
    {
        cout << a << " ";
    }

    cout << endl;

    return 0;
}
