#include<bits/stdc++.h>
using namespace std;

double f(double x)
{
    return x * x * x - 5 * x * x - 29;
}

double secant(double x0, double x1, double tol) 
{
    double x2;
    while (true) 
    {
        x2 = x1 - f(x1) * (x1 - x0) / (f(x1) - f(x0));
        if (fabs(x2 - x1) < tol) break;
        x0 = x1;
        x1 = x2;
    }
    return x2;
}

int main() 
{
    double x0 = 3, x1 = 4, tol = 0.001;
    cout << "Root: " << secant(x0, x1, tol) << endl;
    return 0;
}