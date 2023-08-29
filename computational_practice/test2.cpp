#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    
    int n = 7;

    cout << n << endl;
    cout << &n << endl;
    cout << *&n << endl;

    int *ptr = &n;
    cout << *ptr << endl;
    cout << ptr << endl;

    return 0;
}
