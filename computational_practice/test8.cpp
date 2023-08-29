#include <iostream>

using namespace std;

int main()
{
    int a = 5;
    int *pa = &a;
    int *pa2 = &a;

    cout << "pa = \t" << pa << endl;  // 0x16b0c32a8
    cout << "*pa = \t" << *pa << endl;  // 5
    cout << "&a = \t" << &a << endl << endl;  // 0x16b0c32a8


    a = 3;

    cout << "pa = \t" << pa << endl;  // 0x16b0c32a8
    cout << "*pa = \t" << *pa << endl << endl;  // 3


    *pa = 7;

    cout << "pa = \t" << pa << endl;  // 0x16b0c32a8
    cout << "*pa = \t" << *pa << endl;  // 7
    cout << "pa2 = \t" << pa2 << endl;  // 0x16b0c32a8
    cout << "*pa2 = \t" << *pa2 << endl;  // 7

    return 0;
}
