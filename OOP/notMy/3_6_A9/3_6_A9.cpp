#include <iostream>
#include <vector>
#include<fstream>
#include <sstream>

using namespace std;

void funk(string str, string razd, ofstream& outfile1)
{
	for (int i = 0; i < str.length(); i++)
	{
		if (razd.find(str[i]) < razd.length())
			str[i] = ' ';
	}

	stringstream s(str);
	string buf;
	while (s >> buf)
	{
		outfile1 << buf << " ";
	}
}

void Push_in_Vector(ifstream& infile, vector<string>& stack) {

	string buf;
	infile >> buf;
	while (!infile.fail()) {
		stack.push_back(buf);
		infile >> buf;
	}
}
void Write(vector<string>& stack, ofstream& outfile) {
	while (!stack.empty()) {
		cout << stack.back() << " ";
		outfile << stack.back() << " ";
		stack.pop_back();
	}
}
int main()
{
	setlocale(LC_ALL, "rus");
	vector<string> stack;
	string razd = " ,?!;-.";
	string str;

	cout << "Enter the sentence: " << endl;
	getline(cin, str);

	ofstream outfile1("file.txt");
	if (!outfile1)
	{
		cout << "error1" << endl;
		return 1;
	}
	funk(str, razd, outfile1);

	outfile1.close();
	/////
	ifstream infile("file.txt");

	if (!infile){
		cout << "error1" << endl;
		return 1;
	}

	Push_in_Vector(infile, stack);
	infile.close();

	ofstream outfile("file1.txt");
	if (!outfile)
	{
		cout << "error1" << endl;
		return 1;
	}
	Write(stack, outfile);
	outfile.close();
}