#include<bits/stdc++.h>
using namespace std;

const double EPS = 1e-7;

int p, q, r, s, t, u;

double f(double x) 
{
    return p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x * x + u;
}

double bisection() 
{
    double lo = 0, hi = 1, mid;
    while (hi - lo > EPS) 
    {
        mid = (lo + hi) / 2.0;
        if (f(lo) * f(mid) <= 0)
            hi = mid;
        else
            lo = mid;
    }
    return (lo + hi) / 2.0;
}

int main() 
{
    while (cin >> p >> q >> r >> s >> t >> u)
    {
        if (f(0) * f(1) > 0)
        {
            cout << "No solution\n";
        } 
        else
        {
            printf("%.4f\n", bisection());
        }
    }
    return 0;
}
