#include<bits/stdc++.h>
using namespace std;

double f(double x) 
{
    return x * x * x - 6 * x + 4;
}

double bisection(double a, double b, double tol)
{
    double c;
    while ((b - a) / 2.0 > tol)
    {
        c = (a + b) / 2.0;
        if (f(c) == 0.0) break;
        else if (f(c) * f(a) < 0) b = c;
        else a = c;
    }
    return c;
}

int main()
{
    double tol = 0.001;
    cout << "Root 1: " << bisection(0, 1, tol) << endl;
    cout << "Root 2: " << bisection(1, 2, tol) << endl;
    cout << "Root 3: " << bisection(2, 3, tol) << endl;
    return 0;
}