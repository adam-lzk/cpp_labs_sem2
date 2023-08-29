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
		student.Age = 0;
		student.Course = 0;
		student.Gender = 0;
		student.Mark = 0;
	}

	STUDENT(char Age)
	{
		cin.ignore();
		cout << "FIO: ";          cin.getline(student.FIO, MAX);

		cout << "Age: ";      cin >> student.Age;

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
		return student;
	}
};

class BAZA
{
	STUDENT* array;
	int n;

public:

				BAZA()
				{
					array = NULL;
					n = 0;
				}

				BAZA(int M)
				{
					n = M;
					array = new STUDENT[M];
				}

				BAZA(const BAZA& S)
				{
					n = S.n;
					array = new STUDENT[n];
					for (int i = 0; i < n; i++)
					{
						array[i] = S.array[i];
					}
				}

				void FillTheArray()
				{
					for (int i = 0; i < n; i++)
					{
						array[i].Input();
					}
				}
				void PrintTheArray()
				{
					for (int i = 0; i < n; i++)
					{
						array[i].print_new();
					}
				}

				void InputFile(ofstream& student_data)
				{
					for (int i = 0; i < n; i++)
					{
						array[i].add_student(student_data);
					}
				}
				void OutputFile(ifstream& student_data)
				{
					for (int i = 0; i < n; i++)
					{
						array[i].print(student_data);
					}
				}

				int Find_Student(int k)
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
				~BAZA()
				{
					delete[]  array;
				}

			};
int main()
{
	setlocale(LC_ALL, "Rus");

	int k;
	int n;
	cout << "Enter the number of students : " << '\n';
	cin >> n;

	BAZA ARRAY(n);

	ARRAY.FillTheArray();

	cout << "FIO\t" << "Age\t" << "Course\t" << "Gender\t" << "Mark\t\t" << '\n';
	cout << "==================================================================" << '\n';

	ARRAY.PrintTheArray();

	cout << "Enter the course: " << '\n';
	cin >> k;

	int result = ARRAY.Find_Student(k);

	cout << "Course:  " << k << " Number:" << result << endl;

	ofstream student_data("file.bin", ios::binary);

	ARRAY.InputFile(student_data);
	student_data.close();

	ifstream student_data_out("file.bin", ios::binary);

	BAZA ARRAY1(n);

	ARRAY1.OutputFile(student_data_out);

	student_data_out.close();
	ARRAY1.PrintTheArray();

	BAZA ARRAY2 = ARRAY1;
	ARRAY2.PrintTheArray();
}