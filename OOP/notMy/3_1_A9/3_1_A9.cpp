#include <iostream>
#include<string>

using namespace std;

void Find(string& str1, char c)
{
	int k;
	k = (str1.find(c));
	while (k > 0) {
		str1.erase(k, 1);
		k = (str1.find(c));
	}
}

void Result(string str1, string str2, string& str3)
{
	str3 = "";
	for (int i = 0; i < str2.size(); i++)
	{
		int k = str1.find(str2.at(i));
		if (k < 0)
		{
			str3 += str2.at(i);
		}
	}
}

int main()
{
	string str1;
	string str2 = ("aieouy");
	string str3;
	char c = '*';

	cout << "String: " << endl;
	cin >> str1;

	Find(str1, c);
	Result(str1, str2, str3);

	cout << "size= " << str1.size() << '\t' << str1 << endl;
	cout << "Result\t" << str3;
}