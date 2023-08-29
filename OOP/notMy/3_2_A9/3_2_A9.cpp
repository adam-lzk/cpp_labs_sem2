#include <iostream>

using namespace std;

int main()
{
	int n;
	cout << "Enter n" << endl;
	cin >> n;
	char go[32] = { 0 };

	_itoa_s(n, go, 16);

	string str = string(go);
	cout << "Present   " << str<<endl;

	_itoa_s(n, go, 10);
	string str2 = string(go);
	cout << "Present   " << str2;

}