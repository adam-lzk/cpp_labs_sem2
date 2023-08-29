#include<iostream>
#include<fstream>

using namespace std;
int const MAX = 100;

struct BLANK_STRUDENTOV
{
	char FIO[MAX];
	int  Age;
	int  Course;
	char Gender;
	int  Mark;
};

class STUDENT
{
private:

	BLANK_STRUDENTOV student;

public:
	STUDENT()
	{
		student.FIO[0] = '\0';
		student.Age    = 0;
		student.Course   = 0;
		student.Gender    = 0;
		student.Mark   = 0;
	}

	STUDENT(char Age)
	{
		cin.ignore();
		cout << "FIO: ";          cin.getline(student.FIO, MAX);

		cout << "AGE: ";      cin >> student.Age;

		cout << "Course: ";         cin >> student.Course;

		cout << "Gender: ";          cin >> student.Gender;

		cout << "Mark: "; cin >> student.Mark;
	}

	STUDENT(BLANK_STRUDENTOV newstudent)
	{
		student = newstudent;
	}

	STUDENT(const STUDENT& newstudent)
	{
		student = newstudent.student;
	}

	~STUDENT() = default;


	void Input()
	{
		cin.ignore();
		cout << "FIO: ";          cin.getline(student.FIO, MAX);

		cout << "Age: ";      cin >> student.Age;

		cout << "Course: ";         cin >> student.Course;

		cout << "Gender: ";          cin >> student.Gender;

		cout << "Mark: "; cin >> student.Mark;
		cout << '\n';
	}

	void print_new()
	{
		cout << "FIO\t" << "Age\t" << "Course\t" << "Gender\t" << "Mark\t\t" << '\n';
		cout << "==================================================================" << '\n';
		cout << student.FIO
			<< '\t' << student.Age
			<< '\t' << student.Course
			<< '\t' << student.Gender
			<< '\t' << student.Mark << endl;
	}

	void add_student(ofstream& student_data)
	{
		student_data.write(reinterpret_cast <char*> (&student), sizeof(student));
	}
	void print(ifstream& student_data_out)
	{
		student_data_out.read(reinterpret_cast<char*>(&student), sizeof(student));
	}

	BLANK_STRUDENTOV task()
	{
		return student ;
	}
};

void zapolnenie_massiva(int n, STUDENT* array)
{
	for (int i = 0; i < n; i++)
	{
		array[i].Input();
	}
}

void FillTheArray(int n, STUDENT* array)
{
	for (int i = 0; i < n; i++)
	{
		array[i].print_new();
	}
}

void InputFile(int n, STUDENT* array, ofstream& student_data)
{
	for (int i = 0; i < n; i++)
	{
		array[i].add_student(student_data);
	}
}

void OutputFile(int n, STUDENT* array, ifstream& student_data)
{
	for (int i = 0; i < n; i++)
	{
		array[i].print(student_data);
	}
}

int Find_Student(int k, STUDENT* array, int n)
{
	int kol = 0;
	for (int i = 0; i < n; i++)
	{
		BLANK_STRUDENTOV S = array[i].task();
		if (S.Mark > 8 && S.Course == k)
		{
			kol++;
		}
	}
	return kol;
}

int main()
{
	setlocale(LC_ALL, "Rus");

	int k;
	int n;
	cout << "Number of students : " << '\n';
	cin >> n;

	STUDENT* ARRAY = new STUDENT[n];

	zapolnenie_massiva(n, ARRAY);

	cout << "FIO\t" << "Age\t" << "Course\t" << "Gender\t" << "Mark\t\t" << '\n';
	cout << "==================================================================" << '\n';

	FillTheArray(n, ARRAY);

	cout << "Enter the course: " << '\n';
	cin >> k;

	int result = Find_Student(k, ARRAY, n);

	cout << "Mark:  " << k << " " <<  result << endl;

	ofstream student_data("file.bin", ios::binary);

	InputFile(n, ARRAY, student_data);
	student_data.close();

	ifstream student_data_out("file.bin", ios::binary);

	STUDENT* ARRAY1 = new STUDENT[n];

	OutputFile(n, ARRAY1, student_data_out);

	student_data_out.close();
	FillTheArray(n, ARRAY1);

    delete[] ARRAY;
}