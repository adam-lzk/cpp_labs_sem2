#include <iostream>

using namespace std;


class Student
{
    public:
        Student()  // defolt constructor
        {
            age = 17;
            course = 1;

            cout << "defolt construct " << this << endl;
        };

        Student(int age, int course)  // constructor
        {
            this->age = age;  // this - указатель на текущий объект класса
            this->course = course;

            cout << "construct " << this << endl;
        };

        ~Student()  // destructor
        {
            cout << "destruct " << this << endl;
        };



    private:
        int age;
        int course;
};


void function1(Student student)
{
    cout << "\nfunction1 started\n\n";
}
// destruct adress3


Student function2()
{
    cout << "\nfunction2 started\n\n";

    Student student;  // "defolt construct adress4"

    return student;
}


int main()
{
    Student student1;  // "defolt construct adress1"

    Student student2(19, 3);  // "construct adress2"

    function1(student2);

    function2();

    return 0;
}
// destruct adress4
// destruct adress2
// destruct adress1
