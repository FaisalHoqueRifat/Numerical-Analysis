#include <bits/stdc++.h>
using namespace std;

double f(double x)
{
    return x * x * x - 6 * x + 4;
}

double f_prime(double x)
{
    return 3 * x * x - 6;
}

double newtonRaphson(double x0, double tol)
{
    double x1;
    while (true)
    {
        x1 = x0 - f(x0) / f_prime(x0);
        if (fabs(x1 - x0) < tol)
            break;
        x0 = x1;
    }
    return x1;
}

int main()
{
    double x0 = 0, tol = 0.001;
    cout << "Root: " << newtonRaphson(x0, tol) << endl;
    return 0;
}