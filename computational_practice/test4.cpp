// g++ -std=c++11 test4.cpp -o test4

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int size;
    cout << "size = ";
    cin >> size;

    int num;
    cout << "number = ";
    cin >> num;

    vector<int> vect(size);

    for (int& item : vect)
        cin >> item;

    sort(begin(vect), end(vect));
    bool numberFound = false;

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (vect[i] + vect[j] == num)
            {
                cout << vect[i] << " " << vect[j] << endl;
                numberFound = true;
                break;
            }
        }

        if (numberFound)
            break;
    }

    return 0;
}
