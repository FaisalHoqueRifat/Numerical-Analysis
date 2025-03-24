#include <bits/stdc++.h>
using namespace std;

double f(double x)
{
    return x * x * x - x + 2;
}

double falsePosition(double x1, double x2, double tol)
{
    double x0;
    while ((x2 - x1) > tol)
    {
        x0 = x1 - (f(x1) * (x2 - x1)) / (f(x2) - f(x1));
        if (f(x0) == 0.0)
            break;
        else if (f(x0) * f(x1) < 0)
            x2 = x0;
        else
            x1 = x0;
    }
    return x0;
}

int main()
{
    double x1 = -2, x2 = 2, tol = 0.001;
    cout << "Root: " << falsePosition(x1, x2, tol) << endl;
    return 0;
}