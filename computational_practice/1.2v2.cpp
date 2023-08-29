// Сортировка вектора строк (сортировка лишь по первой букве каждого элемента)
// компиляция - g++ -std=c++11 1.2v2.cpp -o 1.2v2

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void SortWords(vector<string>& words)
{
    for (int i = 0; i < words.size(); i++)  // перебирает все элементы вектора
    {
        char firstLetter = 'z';  //  z - макмсмальный первая буква
        string buffWord;
        int buffNumber;

        for (int k = i; k < words.size(); k++)  // бежит по неотсортированным элементам вектора (от words[i] до последнего)
        {
            if (words[k][0] < firstLetter)  // поиск минимальной первой буквы
            {
                firstLetter = words[i][0];
                buffNumber = k;  // номер элемента вектора с минимальной первой буквой
            }
        }

            buffWord = words[i];  
            words[i] = words[buffNumber];
            words[buffNumber] = buffWord;
    }
}


int main()
{
    vector<string> words;
    string str;

    for (int i = 0; i < 5; i++)
    {
        cin >> str;
        words.push_back(str);
    }

    SortWords(words);

    for (string a : words)
    {
        cout << a << " ";
    }

    cout << endl;

    return 0;
}
