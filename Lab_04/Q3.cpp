#include<bits/stdc++.h>
using namespace std;

int main() {
    int n = 4;
    double x[n] = {  2, 10, 26, 61 };
    double y[n] = {600, 500, 400, 350 };

    // 1. Linearize by taking ln(y)
    double lnY[n];
    for (int i = 0; i < n; i++)
    {
        lnY[i] = log(y[i]);
    }

    // 2. Accumulate sums
    double sum_x = 0, sum_x2 = 0, sum_lnY = 0, sum_xlnY = 0;
    for (int i = 0; i < n; i++)
    {
        sum_x    += x[i];
        sum_x2   += x[i] * x[i];
        sum_lnY  += lnY[i];
        sum_xlnY += x[i] * lnY[i];
    }

    // 3. Compute b and ln(a) via direct formulas
    double denom = n * sum_x2 - sum_x * sum_x;
    double b     = (n * sum_xlnY - sum_x * sum_lnY) / denom;
    double ln_a  = (sum_lnY - b * sum_x) / n;

    double a = exp(ln_a);

    // Output the fitted model
    cout << fixed << setprecision(6)
              << "Best-fit exponential:\n"
              << "y = " << a << " * e^(" << b << " x)\n";
    return 0;
}
