#include<bits/stdc++.h>

using namespace std;

long long evaluatePolynomial(vector<long long>& coefficients, long long x) 
{
    long long result = 0;
    for (int i = 0; i < coefficients.size(); i++) 
    {
        result = result * x + coefficients[i];
    }
    return result;
}

int main()
{
    string line;
    
    while (getline(cin, line)) 
    {
        vector<long long> coefficients;
        stringstream ss(line);
        long long num;
        
        while (ss >> num) coefficients.push_back(num);
        
        getline(cin, line);
        ss.clear();
        ss.str(line);
        
        bool first = true;
        while (ss >> num) 
        {
            if (!first) cout << " ";
            cout << evaluatePolynomial(coefficients, num);
            first = false;
        }
        cout << endl;
    }
    
    return 0;
}
