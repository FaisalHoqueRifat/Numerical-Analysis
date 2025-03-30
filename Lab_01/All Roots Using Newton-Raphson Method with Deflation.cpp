#include<bits/stdc++.h>
using namespace std;

double evaluatePolynomial(const vector<double>& coeffs, double x) 
{
    double result = 0.0;
    for (int i = 0; i < coeffs.size(); i++) 
    {
        result += coeffs[i] * pow(x, coeffs.size() - 1 - i);
    }
    return result;
}

double evaluateDerivative(const vector<double>& coeffs, double x)
{
    double result = 0.0;
    for (int i = 0; i < coeffs.size() - 1; i++) 
    {
        int power = coeffs.size() - 1 - i;
        result += power * coeffs[i] * pow(x, power - 1);
    }
    return result;
}

vector<double> syntheticDivision(const vector<double>& coeffs, double root) 
{
    vector<double> newCoeffs(coeffs.size() - 1);
    newCoeffs[0] = coeffs[0];
    
    for (int i = 1; i < newCoeffs.size(); i++)
    {
        newCoeffs[i] = newCoeffs[i-1] * root + coeffs[i];
    }
    
    return newCoeffs;
}

double newtonRaphson(const vector<double>& coeffs, double x0, double E) 
{
    double xr = x0;
    double prev_xr;
    int iterations = 0;
    const int max_iterations = 100;
    
    while (fabs(xr - prev_xr) > E)
    {
        prev_xr = xr;
        double fx = evaluatePolynomial(coeffs, xr);
        double dfx = evaluateDerivative(coeffs, xr);
        
        if (fabs(dfx) < 1e-10) 
        { 
            cout << "Derivative too small. Trying a different initial guess." << endl;
            xr += 0.5;
            continue;
        }
        
        xr = xr - fx / dfx;
        iterations++;
        
        if (iterations > max_iterations) 
        {
            cout << "Maximum iterations reached." << endl;
            break;
        }
    } 
    
    return xr;
}

int main()
{
    // Original polynomial: x^3 - 6x + 4 = 0
    vector<double> coefficients = {1, 0, -6, 4};
    
    double E = 0.001; 
    double x0 = 1.0;  
    
    vector<double> roots;
    vector<double> currentCoeffs = coefficients;
    int n = currentCoeffs.size() - 1;
    
    cout << fixed << setprecision(3);
    
    while (n > 1) 
    {
        double root = newtonRaphson(currentCoeffs, x0, E);
        roots.push_back(root);
        
        currentCoeffs = syntheticDivision(currentCoeffs, root);
        n = currentCoeffs.size() - 1;
        
        x0 = root;
    }
    
    double lastRoot = -currentCoeffs[1] / currentCoeffs[0];
    roots.push_back(lastRoot);

    cout << "Roots of the polynomial x^3 - 6x + 4 = 0 are:" << endl;
    for (int i = 0; i < roots.size(); ++i)
    {
        cout << "Root " << i+1 << ": " << roots[i] << endl;
    }
    
    return 0;
}