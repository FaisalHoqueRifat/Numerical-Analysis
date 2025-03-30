#include<bits/stdc++.h>
using namespace std;

double f(double x)
{
    return x * x * x - 9 * x + 1;
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
    double a = 0, b = 1, tol = 0.001;
    cout << "Root: " << bisection(a, b, tol) << endl;
    return 0;
}