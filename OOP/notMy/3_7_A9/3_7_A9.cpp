#include <list>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

void funk(string str, string sep, string itog, list<string>& text)
{
	for (int i = 0; i < str.length(); i++)
	{
		char c = str[i];
		if (sep.find(str[i]) < sep.length())
			str[i] = ' ';
	}

	stringstream stream(str);
	string word;
	while (stream >> word) // ������ �� ������ ��������� �������
	{
		int len = word.length();
		if (word[len - 1] == 'd' && word[len - 2] == 'r') {
			
			text.push_back(word);
		}
	}
}

void Write(list<string> text) {
	while (!text.empty()) {
		cout << text.back() << " ";
		text.pop_back();
	}
}

int main()
{
	list<string> text;

	string str;
	string itog;
	cout << "Enter the sentence:\n";
	getline(cin, str);
	string sep = "! .,;:?()-";
	funk(str, sep, itog, text);
	Write(text);
}