#include <iostream>
#include <string>

using namespace std;

void find(string str1, string razd, string& str2, int n)
{
	int WordBegin = 0, WordEnd = 0;

	WordBegin = str1.find_first_not_of(razd, WordEnd);
	WordEnd = str1.find_first_of(razd, WordBegin);

	if (WordEnd >= str1.length())
		WordEnd = str1.length();

	while (WordBegin < str1.length())
	{
		string word = str1.substr(WordBegin, WordEnd - WordBegin);

		if (word.length() == n)
		{
			str2 += word;
			str2 += " ";
		}
		WordBegin = str1.find_first_not_of(razd, WordEnd);
		WordEnd = str1.find_first_of(razd, WordBegin);

		if (WordEnd >= str1.length())
			WordEnd = str1.length();
	}
}

int main()
{
	int n;
	cout << "Vvod n" << endl;
	cin >> n;
	string str1, str2;
	cout << "Str1" << endl;
	cin >> str1;
	string razd = (" .,;!?-:");

	find(str1, razd, str2, n);
	cout << str2;

    return 0;
}