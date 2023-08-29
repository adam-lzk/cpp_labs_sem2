#include "Header.h"

const int Vector::Get_size() {
    return size;
}
void Vector::Set_size(int _size) {
    if (_size < MAX)
        this->size = _size;

}

const double Vector::Get_element(int n) {
    if ((n) < size && (n) >= 0) {
        return vector[n];
    }
    else
        cout << "Error!" << endl;
}

void Vector::Set_element(int n, double a) {
    if ((n) < size && (n) >= 0)
        vector[n] = a;
    else
        cout << "Error!" << endl;
}

void Vector::Del_skal(double k) {
    for (int i = 0; i < size; i++)
        vector[i] /= k;
}

void Vector::Pr_skal(double k) {
    for (int i = 0; i < size; i++)
        vector[i] *= k;
}

void Vector::Sum_skal(double k) {
    for (int i = 0; i < size; i++)
        vector[i] += k;
}

void Vector::Raz_skal(double k) {
    for (int i = 0; i < size; i++)
        vector[i] -= k;
}

double Vector::Length() {
    double sum = 0;
    for (int i = 0; i < size; i++)
        sum += vector[i] * vector[i];
    return sqrt(sum);
}
void Vector::Del_vector(const Vector& a) {
    if (a.size == size) {

        for (int i = 0; i < size; i++)
            vector[i] /= a.vector[i];
    }
    else {
        cout << "Error" << endl;
    }
}

void Vector::Proi_vector(const Vector& a) {
    if (a.size == size) {

        for (int i = 0; i < size; i++)
            vector[i] *= a.vector[i];
    }
    else {
        cout << "Error" << endl;
    }
}

void Vector::Sum_vector(const Vector& a) {
    if (a.size == size) {

        for (int i = 0; i < size; i++)
            vector[i] += a.vector[i];
    }
    else {
        cout << "NE VYP odno is usluviy" << endl;
    }
}

void Vector::Raz_vector(const Vector& a) {
    if (a.size == size) {

        for (int i = 0; i < size; i++)
            vector[i] -= a.vector[i];
    }
    else {
        cout << "NE VYP odno is usluviy" << endl;
    }
}

void Vector::Print() {
    for (int i = 0; i < size; i++)
        cout << this->vector[i] << " ";
    cout << endl;
}

void Vector::Random() {
    for (int i = 0; i < size; i++)
        vector[i] = rand() % 10;
}

void Vector::Vvod() {
    for (int i = 0; i < size; i++)
        cin >> vector[i];
}

double Vector::Skal_proizv(const Vector& a) {
    if (a.size == size) {
        double sum = 0;
        for (int i = 0; i < size; i++)
            sum += a.vector[i] * vector[i];

        return sum;
    }
    else {
        cout << "Vectora raznoy razmernosti" << endl;
        return 0;
    }
}

void Vector::Task(const Vector& a, double k) {
    for (int i = 0; i < a.size; i++)
        vector[i] = a.vector[i] + k;
    size = a.size;
}

double Vector::Average() {
    double sum = 0, k = 0;
    for (int i = 0; i < size; i++) {
        sum += vector[i];
        k++;

    }
    return sum / k;
}

double Vector::Max(double average) {

    double max = 0;
    for (int i = 0; i < size; i++) {
        if (max < abs(vector[i] - average))
            max = abs(vector[i] - average);
    }
    return max;
}

int main()
{
    srand(time(NULL));

    Vector x(3), z(3);
    x.Set_size(3);
    x.Random();
    cout << "Vector x: ";
    x.Print();
    cout << x.Max(x.Average()) << endl;
    cout << "Vector z: ";
    z.Task(x, x.Max(x.Average()));
    z.Print();
    cout << "Vector x: ";
    x += x.Max(x.Average());
    x.Print();
}