#include<bits/stdc++.h>
using namespace std;

double f(double x)
{
    return x * x * x - x + 2;
}

double falsePosition(double a, double b, double tol)
{
    double c;
    while ((b - a) > tol)
    {
        c = (a * f(b) - b * f(a)) / (f(b) - f(a));
        if (f(c) == 0.0) break;
        else if (f(c) * f(a) < 0) b = c;
        else a = c;
    }
    return c;
}

int main() 
{
    double a = -3, b = -2, tol = 0.001;
    cout << "Root: " << falsePosition(a, b, tol) << endl;
    return 0;
}