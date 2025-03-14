#include<bits/stdc++.h>
using namespace std;

double evaluatePolynomial(double x) 
{
    return ((x * x - 2) * x + 5) * x + 10;
}

int main() 
{
    double x = 5.0;
    cout << "f(5) = " << evaluatePolynomial(x) << endl;
    return 0;
}