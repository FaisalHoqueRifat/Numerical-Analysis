#include<bits/stdc++.h>

using namespace std;

int evaluateDerivative(vector<int>& coefficients, int x) 
{
    int result = 0;
    int n = coefficients.size() - 1;

    for (int i = 0; i < n; i++)
    {
        result = result * x + coefficients[i] * (n - i);
    }

    return result;
}

int main()
{
    int x;
    while (cin >> x) 
    {
        vector<int> coefficients;
        int coeff;
        
        while (cin >> coeff)
        {
            coefficients.push_back(coeff);
            if (cin.peek() == '\n') break;
        }

        int derivativeValue = evaluateDerivative(coefficients, x);

        cout << derivativeValue << endl;
    }

    return 0;
}