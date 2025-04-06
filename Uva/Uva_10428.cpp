#include<bits/stdc++.h>

using namespace std;

double evaluatePolynomial(vector<double>& coefficients, double x) 
{
    double result = 0.0;
    for (int i = 0; i < coefficients.size(); i++) 
    {
        result = result * x + coefficients[i];
    }
    return result;
}

double evaluateDerivative(vector<double>& coefficients, double x)
{
    double result = 0.0;
    for (int i = 0; i < coefficients.size() - 1; i++) 
    {
        result = result * x + coefficients[i] * (coefficients.size() - 1 - i);
    }
    return result;
}

double findRoot(vector<double>& coefficients, double initialGuess) 
{
    double x = initialGuess;
    for (int i = 0; i < 100; i++)
    {
        double fx = evaluatePolynomial(coefficients, x);
        double fpx = evaluateDerivative(coefficients, x);
        if (fabs(fpx) < 1e-10) break;
        double xNew = x - fx / fpx;
        if (fabs(xNew - x) < 1e-10) break;
        x = xNew;
    }
    return x;
}

vector<double> deflatePolynomial(vector<double>& coefficients, double root)
{
    vector<double> newCoefficients(coefficients.size() - 1);
    newCoefficients[0] = coefficients[0];
    for (int i = 1; i < newCoefficients.size(); ++i)
    {
        newCoefficients[i] = coefficients[i] + root * newCoefficients[i - 1];
    }
    return newCoefficients;
}

int main()
{
    int equationNumber = 1;
    while (true) 
    {
        int N;
        cin >> N;
        if (N == 0) break;

        vector<double> coefficients(N + 1);
        for (int i = 0; i <= N; i++) 
        {
            cin >> coefficients[i];
        }

        vector<double> roots;
        vector<double> currentCoefficients = coefficients;

        for (int i = 0; i < N; i++) 
        {
            double initialGuess = 0.0;
            double root = findRoot(currentCoefficients, initialGuess);
            roots.push_back(root);
            currentCoefficients = deflatePolynomial(currentCoefficients, root);
        }

        sort(roots.begin(), roots.end());

        cout << "Equation " << equationNumber++ << ":";
        for (auto root : roots) 
        {
            cout << fixed << setprecision(4) << " " << root;
        }
        cout << endl;
    }

    return 0;
}