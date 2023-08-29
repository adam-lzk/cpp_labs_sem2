#include <iostream>

using namespace std;


class Student
{
    public:
        Student()
        {
            age = 17;
            course = 1;

            cout << "defolt construct " << this << endl;
        };

        Student(int age, int course)
        {
            this->age = age;
            this->course = course;

            cout << "construct " << this << endl;
        };

        Student(const Student& other)  // copy constructor
        {
            this->age = other.age;
            this->course = other.course;

            cout << "copy construct " << this << endl;
        };

        ~Student()
        {
            cout << "destruct " << this << endl;
        };



    private:
        int age;
        int course;
};


int main()
{
    Student student1;  // "defolt construct adress1"

    Student student2(student1);  // "copy construct adress2"

    return 0;
}
// destruct adress2
// destruct adress1
