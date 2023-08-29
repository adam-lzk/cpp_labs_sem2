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
	cout << "Fio: " << STUD.fio << endl;

	cout << "Age: " << STUD.age << endl;

	cout << "Course: " << STUD.course << endl;

	cout << "Mark: " << STUD.mark << endl << endl << endl;
}

void create(ofstream& outfile, int kol)
{
	Students STUD;
	for (int i = 0; i < kol; i++)
	{
		random(STUD);
		outfile.write(reinterpret_cast<char*>(&STUD), sizeof(Students));
	}
}

void read_file(ifstream& infile)
{
	int k = 0;
	Students STUD;
	infile.read(reinterpret_cast<char*>(&STUD), sizeof(Students));
	while (!infile.eof())
	{
		print(STUD);
		infile.read(reinterpret_cast<char*>(&STUD), sizeof(Students));
	}
}

int work(ifstream& infile, int n)
{
	int k = 0;
	Students STUD;
	infile.read(reinterpret_cast<char*>(&STUD), sizeof(Students));

	while (!infile.eof())
	{
		if (STUD.course == n && STUD.mark >= 9)
		{
			k++;
		}
		infile.read(reinterpret_cast<char*>(&STUD), sizeof(Students));
	}
	return k;
}

int  main()
{
	srand(time(NULL));
	int kol;
	cout << "Number of students: ";
	cin >> kol;

	ofstream outfile("file.bin", ios::binary);
	if (!outfile)
	{
		cout << "error1" << endl;
		return 1;
	}
	create(outfile, kol);
	outfile.close();

	ifstream infile("file.bin", ios::binary);

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
	infile.open("file.bin", ios::binary);

	cout << "Check " << n << " course" << endl << "Smartasses ->      " << work(infile, n);
	cout << endl;

	infile.close();
}