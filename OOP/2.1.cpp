#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

class Vector {
    public:
        Vector() {}
        Vector() {}

        void ChangeVectorSize(const int& newSize) {
            vect.resize(newSize, 0);
        }

        void GetVectorSize() {
            cout << vect.size() << endl;
        }

        void RandomFillVector() {
            for (const auto& item : vect)
            {
                int randNumb = rand() % 100;
                vect.push_back(randNumb);
            }
        }

        ~Vector() {}


    private:
        vector<int> vect;
};

int main()
{
    srand(time(NULL));

    return 0;
}
