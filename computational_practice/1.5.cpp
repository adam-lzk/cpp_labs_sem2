// Вычисление определенного интеграла методом трапеции

#include <iostream>
#include <cmath>

using namespace std;


double CalculateY(const double& x)
{
    return 1/(sqrt(pow(x,3) + 1));  // given function
}


double IntegralCalculation(const double& a, const double& b, const double& deltaX)
{
    double x = a;
    double y;
    double trapezoidBase1;
    double trapezoidBase2;
    double integral = 0;

    while(x < b)
    {
        trapezoidBase1 = CalculateY(x);

        x += deltaX;
        trapezoidBase2 = CalculateY(x);

        integral += (trapezoidBase1 + trapezoidBase2) / 2 * deltaX;  // delta square
    }

    return integral;
}


int main()
{
    double a;
    cout << "a = ";
    cin >> a;

    double b;
    cout << "b = ";
    cin >> b;

    double deltaX;
    cout << "delta x = ";
    cin >> deltaX;

    double integral = IntegralCalculation(a, b, deltaX);
    cout << integral << endl;

    return 0;
}
