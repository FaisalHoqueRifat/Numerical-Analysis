#include <bits/stdc++.h>
using namespace std;

double f(double x)
{
    return x / (1 + x * x);
}

int main()
{
    double a = 0.0, b = 1.0;
    int n = 6;
    double h = (b - a) / n;
    double sum = f(a) + f(b);

    for (int i = 1; i < n; i++) 
    {
        double xi = a + i * h;
        if (i % 3 == 0)
            sum += 2 * f(xi);
        else
            sum += 3 * f(xi);
    }

    double result = (3 * h / 8.0) * sum;

    cout << fixed << setprecision(3);
    cout << "Approximate value of the integral: " << result << endl;

    return 0;
}
