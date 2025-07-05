#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 5;
    double x[] = {1, 2, 3, 4, 5};
    double f[] = {1, 8, 27, 64, 125};
    double a[5][5] = {0};

    // Construct the forward difference table
    for (int i = 0; i < n; i++)
    {
        a[i][0] = f[i];
    }
    for (int j = 1; j < n; j++)
    {
        for (int i = 0; i < n - j; i++)
        {
            a[i][j] = a[i + 1][j - 1] - a[i][j - 1];
        }
    }

    double h = 1.0; // Step size

    // Extract forward differences
    double d1 = a[0][1]; // Δy0
    double d2 = a[0][2]; // Δ^2y0
    double d3 = a[0][3]; // Δ^3y0
    double d4 = a[0][4]; // Δ^4y0

    // First derivative at x = 1
    double f1 = (d1 - (1.0 / 2.0) * d2 + (1.0 / 3.0) * d3 - (1.0 / 4.0) * d4) / h;

    // Second derivative at x = 1
    double f2 = (d2 - d3 + (11.0 / 12.0) * d4) / (h * h);

    cout << "First derivative at x = 1: " << f1 << endl;
    cout << "Second derivative at x = 1: " << f2 << endl;

    return 0;
}
