#pragma once
#include <iostream>
#include "math.h"
#include"ctime"
const int MAX = 6;
using namespace std;
class Vector {
private:
    double* vector;
    int size;

public:
    Vector() : size(0), vector{ 0 } {};

    Vector(int size) {
        if (size > 0 && size <= MAX) {
            vector = new double[size];
            this->size = size;
        }
        else { size = 0; vector = {}; }
    };

    Vector(const Vector& a) :size(a.size) {
        for (int i = 0; i < size; i++)
            vector[i] = a.vector[i];

    };

    ~Vector() {
        delete[] vector;
    };

public:
    const int Get_size();
    void Set_size(int _size);
    const double Get_element(int n);
    void Set_element(int n, double a);
    void Del_skal(double k);
    void Pr_skal(double k);
    void Sum_skal(double k);
    void Raz_skal(double k);


    double Length();
    void Del_vector(const Vector& a);
    void Proi_vector(const Vector& a);
    void Sum_vector(const Vector& a);
    void Raz_vector(const Vector& a);

    void Print();
    void Random();
    void Vvod();
    double Skal_proizv(const Vector& a);
    void Task(const Vector& a, double k);
    double Average();
    double Max(double average);

    Vector& operator+=(const Vector& other) {
        if (other.size == this->size) {
            for (int i = 0; i < other.size; i++)
                this->vector[i] += other.vector[i];

        }
        return *this;

    }

    Vector& operator-=(const Vector& other) {
        if (other.size == this->size)
            for (int i = 0; i < other.size; i++)
                this->vector[i] -= other.vector[i];
        return *this;
    }

    Vector& operator*=(const Vector& other) {
        if (other.size == this->size)
            for (int i = 0; i < other.size; i++)
                this->vector[i] *= other.vector[i];
        return *this;
    }

    Vector& operator/=(const Vector& other) {
        if (other.size == this->size)
            for (int i = 0; i < other.size; i++)
                this->vector[i] /= other.vector[i];
        return *this;
    }

    Vector& operator+=(double skal) {
        for (int i = 0; i < size; i++)
            this->vector[i] += skal;
        return *this;
    }

    Vector& operator-=(double skal) {
        for (int i = 0; i < size; i++)
            this->vector[i] -= skal;
        return *this;
    }

    Vector& operator*=(double skal) {
        for (int i = 0; i < size; i++)
            this->vector[i] *= skal;
        return *this;
    }

    Vector& operator/=(double skal) {
        for (int i = 0; i < size; i++)
            this->vector[i] /= skal;
        return *this;
    }
};