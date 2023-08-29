#include <ctime>
#include <cstdlib>
#include <fstream>
#include <iostream>

using namespace std;


int GeneratePositiveNumber() {
	return rand() % 100 + 1;
}


void Create(ofstream& outfile, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			outfile << GeneratePositiveNumber() << endl;  // для записи в файл <<
		}

		for (int j = 0; j < 10; j++)
		{
			outfile << (-1) * GeneratePositiveNumber() << endl;
		}
	}
}


void Read_file(ifstream& infile)
{
	int v;
	infile >> v;
	while (!infile.fail())
	{
		cout << endl << v ;  // для чтения из файла >>
		infile >> v;
	}
	cout << endl;
}


void Create_chet(ofstream& outfile_new, ifstream& infile)
{
	int v;
	int MAS[5] = { 0 };
	while (!infile.fail())
	{
		for (int j = 0; j < 5 && !infile.fail(); j++)
		{
			infile >> v;
			outfile_new << v << endl;
		}
		for (int j = 0; j < 5 && !infile.fail(); j++)
		{
			infile >> v;
			MAS[j] = v;
		}

		for (int j = 0; j < 5 && !infile.fail(); j++)
		{
			infile >> v;
			outfile_new << v << endl;
		}
		for (int j = 0; j < 5 && !infile.fail(); j++)
		{
			outfile_new << MAS[j] << endl;
		}
		for (int j = 0; j < 5 && !infile.eof(); j++)
		{
			infile >> v;
			outfile_new << v << endl;
		}
	}
}


int main()
{
	srand((unsigned)time(NULL));

	int n = 2;

	ofstream outfile("file.txt");  // объект класса ofstream - для того, чтобы сохранить данные в файл
	if (!outfile)
	{
		cout << "error1" << endl;
		return 1;
	}
	else
	{
		Create(outfile, n);
		outfile.close();  // после открытия, записи, чтения файла его нужно закрыть - .close()
	}

	ifstream infile("file.txt");
	if (!infile)  // !infile.is_open()
	{
		cout << "error2" << endl;
		return 1;
	}
	else
	{
		cout << "Default file: ";
		Read_file(infile);
		infile.close();
	}

	ofstream outfile_new("file1.txt");
	if (!outfile_new)
	{
		cout << "error3" << endl;
		return 1;
	}
	infile.clear();
	infile.open("file.txt");  // для открытия/создания файла file.txt в папке проекта
	if (!infile)
	{
		cout << "error4" << endl;
		return 1;
	}
	Create_chet(outfile_new, infile);

	outfile_new.close();
	infile.close();

	infile.clear();
	infile.open("file1.txt");
	if (!infile)
	{
		cout << "error5" << endl;
		return 1;
	}

	cout << endl << endl <<"Changed file";
	Read_file(infile);
	infile.close();
	return 0;
}
