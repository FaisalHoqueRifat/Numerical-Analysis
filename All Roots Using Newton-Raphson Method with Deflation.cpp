#include<bits/stdc++.h>
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
        if (fabs(x1 - x0) < tol) break;
        x0 = x1;
    }
    return x1;
}

vector<double> deflatePolynomial(vector<double> coeffs, double root)
{
    vector<double> newCoeffs(coeffs.size() - 1);
    newCoeffs[0] = coeffs[0];
    for (double i = 1; i < newCoeffs.size(); i++) 
    {
        newCoeffs[i] = coeffs[i] + newCoeffs[i - 1] * root;
    }
    return newCoeffs;
}

int main() 
{
    double tol = 0.001;
    vector<double> coeffs = {1, 0, -6, 4}; // x^3 - 6x + 4

    double root1 = newtonRaphson(1.5, tol);
    cout << "Root 1: " << root1 << endl;

    coeffs = deflatePolynomial(coeffs, root1);
    double root2 = newtonRaphson(1.5, tol);
    cout << "Root 2: " << root2 << endl;

    coeffs = deflatePolynomial(coeffs, root2);
    double root3 = newtonRaphson(1.5, tol);
    cout << "Root 3: " << root3 << endl;

    return 0;
}