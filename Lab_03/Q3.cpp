#include<bits/stdc++.h>
using namespace std;

double f(double x) 
{
    return log10(x);
}

int main() 
{
    double a = 1.0, b = 5.0;
    int n = 6;
    double h = (b - a) / n;
    double sum = 0.0;

    // Compute f(x0) and f(xn)
    sum += f(a) + f(b);

    // Compute 2*f(xi) for i = 1 to n-1
    for (int i = 1; i < n; i++)
    {
        double xi = a + i * h;
        sum += 2 * f(xi);
    }

    double result = (h / 2.0) * sum;

    cout << fixed << setprecision(3);
    cout << "Approximate value of the integral: " << result << endl;

    return 0;
}
