#include <iostream>
#include <string>

using namespace std;

class vehicle
{
	int number_of_seats = 0;
	string name;

public:

	vehicle(int m, string sub)
	{
		number_of_seats = m; name = sub;
	}
	void set()
	{
		cout << "Enter number of seats:" << endl;
		cin >> number_of_seats; cin >> name;
	}
	void print() { cout << "Vehicle - " << number_of_seats << endl; cout << " Name- " << name << endl; }

	~vehicle() = default;
};

class bus : public vehicle
{

	int kol_handrail = 0;
	int punch;

public:

	bus(int m, string sub, int n, int ft) : vehicle(m, sub)
	{
		kol_handrail = n; punch = ft;
	}
	void set()
	{
		vehicle::set();
		cout << "Enter data: " << endl;
		cin >> kol_handrail; cin >> punch;
	}
	void print()
	{
		cout << "Bus:" << endl;
		vehicle::print();
		cout << "Data - " << kol_handrail << endl; cout << " " << punch << endl;
	}
	~bus() = default;
};

class train : public vehicle
{
	int dream;
	string place_type;

public:

	train(int m, string sub, int c, string te) : vehicle(m, sub)
	{
		place_type = te; dream = c;
	}
	void set()
	{
		vehicle::set();
		cout << "Data " << endl;
		cin >> dream; cin >> place_type;
	}
	void print()
	{
		cout << "Train" << endl;
		vehicle::print();
		cout << "Data - " << dream << endl << " " << place_type << endl;
	}
	~train() = default;
};

class airplane : public vehicle
{

	int flight_number;
	int kol_turbin;

public:

	airplane(int m, string sub, int te, int c) : vehicle(m, sub)
	{
		flight_number = te; kol_turbin = c;
	}
	void set()
	{
		vehicle::set();
		cout << "Enter data " << endl;
		cin >> flight_number;	cin >> kol_turbin;
	}
	void print()
	{
		cout << "Airplane" << endl;
		vehicle::print();
		cout << "Data - " << flight_number << endl << " " << kol_turbin << endl;;
	}
	~airplane() = default;
};

int main()
{
	cout << "\t";
	bus obj1(80, "Bus class B", 10, 3);
	obj1.print();

	cout << endl << "\t";
	train obj2(450, "TrainGtA", 26, "g");
	obj2.print();

	cout << endl << "\t";
	airplane obj3(300, "FlyKing", 254, 4);
    obj3.print();
	
	return 0;
}