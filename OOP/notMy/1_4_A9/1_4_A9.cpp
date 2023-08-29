#include <iostream>
#include <ctime>
#include <fstream>
using namespace std;

struct Students {
	int age;
	int course;
	double mark;
	char fio[80];
};

void random(Students& STUD)
{
	cout << "Enter name and lastname : ";
	cin.getline(STUD.fio, 80);

	STUD.age = rand() % 17 + 15;

	STUD.course = rand() % 4 + 1;

	cout << "Enter mark: ";
	cin >> STUD.mark;
	cin.get();
	cout << endl;
}

void print(Students STUD)
{
	cout << "Name and lastname: " << STUD.fio << endl;

	cout << "Age: " << STUD.age << endl;

	cout << "Course: " << STUD.course << endl;

	cout << "Mark: " << STUD.mark <<  endl << endl;
}

void create(ofstream& outfile, int kol)
{
	Students STUD;
	for (int i = 0; i < kol; i++)
	{
		random(STUD);
		outfile << STUD.fio << "  ";
		outfile << STUD.age << "  ";
		outfile << STUD.course << "  ";
		outfile << STUD.mark << endl;
	}
}

void read_file(ifstream& infile)
{
	int k = 0;
	Students STUD;
	infile >> STUD.fio;
	infile >> STUD.age;
	infile >> STUD.course;
	infile >> STUD.mark;
	while (!infile.eof())
	{
		print(STUD);
		infile >> STUD.fio;
		infile >> STUD.age;
		infile >> STUD.course;
		infile >> STUD.mark;

	}
}

int work(ifstream& infile, int n)
{
	int k = 0;
	Students STUD;
	infile >> STUD.fio;
	infile >> STUD.age;
	infile >> STUD.course;
	infile >> STUD.mark;

	while (!infile.eof())
	{
		if (STUD.course == n && STUD.mark >= 9)
		{
			k++;
		}
		infile >> STUD.fio;
		infile >> STUD.age;
		infile >> STUD.course;
		infile >> STUD.mark;
	}
	return k;
}

int  main()
{
	srand(time(NULL));
	int kol;
	cout << "Number of students: ";
	cin >> kol;

	ofstream outfile("file.txt");
	if (!outfile)
	{
		cout << "error1" << endl;
		return 1;
	}
	create(outfile, kol);
	outfile.close();

	ifstream infile("file.txt");

	if (!infile)
	{
		cout << "error1" << endl;
		return 1;
	}
	read_file(infile);
	infile.close();

	int n;
	cout << "Enter a course: ";
	cin >> n;

	infile.clear();
	infile.open("file.txt");

	cout << "Check " << n << " course" << endl << "Smartasses ->      " << work(infile, n);
	cout << endl;

	infile.close();
}
