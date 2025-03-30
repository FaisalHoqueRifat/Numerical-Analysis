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
    double lower = -100, upper = 100, x = 1.0;///boundary and increment

    double x2 = lower, x1 = lower;
    int i = 1;
    while(x2 < upper)
    {
        x1 = lower, x2 = lower + x;
        double f1 = f(x1),f2 =f(x2);
        lower = x2 + 0.000001;
        if((f1 * f2) > 0)
        {
            continue;
        }
        cout << " Root "<< i <<" : "<< bisection(x1, x2, tol) << endl ;
        i++;
    }
    return 0;
}