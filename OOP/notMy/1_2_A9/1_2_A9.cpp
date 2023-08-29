#include <ctime>
#include <cstdlib>
#include <fstream>
#include <iostream>
using namespace std;

void create(ofstream& outfile, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			int v = rand() % 100;
			outfile.write(reinterpret_cast <char*> (&v), sizeof(int));
		}
		for (int j = 0; j < 10; j++)
		{
			int v = (rand() % 100) * (-1);
			outfile.write(reinterpret_cast <char*> (&v), sizeof(int));
		}
	}
}

void read_file(ifstream& infile)
{
	int v;
	infile.read(reinterpret_cast<char*>(&v), sizeof(int));
	while (!infile.fail())
	{
		cout << endl << v;
		infile.read(reinterpret_cast<char*>(&v), sizeof(int));
	}
	cout << endl;
}

void create_chet(ofstream& outfile_new, ifstream& infile)
{
	int v;
	int MAS[5] = { 0 };
	while (!infile.eof())
	{
		for (int j = 0; j < 5 && !infile.eof(); j++)
		{
			infile.read(reinterpret_cast<char*>(&v),sizeof(int));

			outfile_new.write(reinterpret_cast<char*>(&v),sizeof(int));
		}

		for (int j = 0; j < 5 && !infile.eof(); j++)
		{
			infile.read(reinterpret_cast<char*>(&v),sizeof(int));
			MAS[j] = v;
		}
		//
		for (int j = 0; j < 5 && !infile.eof(); j++)
		{
			infile.read(reinterpret_cast<char*>(&v),sizeof(int));

			outfile_new.write(reinterpret_cast<char*>(&v),sizeof(int));
		}
		for (int j = 0; j < 5 && !infile.eof(); j++)
		{
			/*v = MAS[j];*/
			outfile_new.write(reinterpret_cast<char*>(&MAS[j]), sizeof(int));
		}
		for (int j = 0; j < 5 && !infile.eof(); j++)
		{
			infile.read(reinterpret_cast<char*>(&v),sizeof(int));

			outfile_new.write(reinterpret_cast<char*>(&v),sizeof(int));
		}
	}
}

int main()
{
	srand((unsigned)time(NULL));
	int n = 2;

	ofstream outfile("file.txt",ios::binary);
	if (!outfile)
	{
		cout << "error1" << endl;
		return 1;
	}

	create(outfile, n);
	outfile.close();

	ifstream infile("file.txt", ios::binary);
	if (!infile)
	{
		cout << "error2" << endl;
		return 2;
	}

    cout << "Default file: ";
	read_file(infile);
	infile.close();

	ofstream outfile_new("file1.txt", ios::binary);
	if (!outfile_new)
	{
		cout << "error3" << endl;
		return 3;
	}
	infile.clear();
	infile.open("file.txt", ios::binary);
	if (!infile)
	{
		cout << "error4" << endl;
		return 4;
	}
	create_chet(outfile_new, infile);

	outfile_new.close();
	infile.close();

	infile.clear();
	infile.open("file1.txt", ios::binary);
	if (!infile)
	{
		cout << "error5" << endl;
		return 5;
	}

    cout << endl << endl << "Changed file: ";
	read_file(infile);
	infile.close();
	return 0;
}