#include<bits/stdc++.h>
using namespace std;

vector<double> syntheticDivision(vector<double>& coefficients, double root) 
{
    vector<double> quotient(coefficients.size() - 1);
    quotient[0] = coefficients[0];
    for (double i = 1; i < coefficients.size() - 1; i++)
    {
        quotient[i] = coefficients[i] + quotient[i - 1] * root;
    }
    return quotient;
}

int main()
{
    vector<double> coefficients = {1, -5, 10, -8}; // x^3 - 5x^2 + 10x - 8
    double root = 2;
    vector<double> quotient = syntheticDivision(coefficients, root);

    cout << "Quotient polynomial: ";
    for (double coeff : quotient)
    {
        cout << coeff << " ";
    }
    cout << endl;
    return 0;
}