#include <bits/stdc++.h>
using namespace std;

double f(double x)
{
    return x * x * x - 5 * x * x - 29;
}

double secant(double x1, double x2, double tol)
{
    double x3;
    while (true)
    {
        x3 = x2 - (f(x2) * (x2 - x1)) / (f(x2) - f(x1));
        if (fabs(x2 - x1) < tol)
            break;
        x1 = x2;
        x2 = x3;
    }
    return x2;
}

int main()
{
    double x1 = 4, x2 = 2, tol = 0.001;
    cout << "Root: " << secant(x1, x2, tol) << endl;
    return 0;
}