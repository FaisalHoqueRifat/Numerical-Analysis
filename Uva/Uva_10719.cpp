#include<bits/stdc++.h>
using namespace std;

int main()
{
    int k;
    string line;
    
    while (cin >> k)
    {
        getline(cin, line);
        getline(cin, line);
        
        stringstream ss(line);
        vector<int> coefficients;
        int coeff;

        while (ss >> coeff) 
        {
            coefficients.push_back(coeff);
        }
        
        int n = coefficients.size();
        vector<int> q(n); 
        

        q[0] = coefficients[0];
        for (int i = 1; i < n; i++)
        {
            q[i] = coefficients[i] + k * q[i-1];
        }
        

        cout << "q(x):";
        for (int i = 0; i < n - 1; i++)
        {
            cout << " " << q[i];
        }
        cout << "\n";
        
        cout << "r = " << q[n-1] << "\n\n";
    }
    return 0;
}