// g++ -std=c++11 test5.cpp -o test5

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int size;
    cout << "size = ";
    cin >> size;

    int desiredNumber;
    cout << "number = ";
    cin >> desiredNumber;

    vector<int> vect(size);

    for (int& item : vect)
        cin >> item;

    sort(begin(vect), end(vect));

    int firstIndex = 0, secondIndex = size - 1;

    while(true)
    {
        if (vect[firstIndex] + vect[secondIndex] > desiredNumber)
        {
            secondIndex--;
        }
        else if (vect[firstIndex] + vect[secondIndex] < desiredNumber)
        {
            firstIndex++;
        }
        else
        {
            cout << vect[firstIndex] << " " << vect[secondIndex] << endl;
            break;
        }
    }

    return 0;
}
