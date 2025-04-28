#include<bits/stdc++.h>
using namespace std;

vector<int> syntheticDivision(vector<int>& a, int root, int n) 
{
    vector<int> q(n+1);
    q[0] = a[0];
    for(int i = 1; i<=n; i++)
    {
        q[i] = a[i] + q[i-1]*root;
    }
    return q;
}

int main()
{
    int n = 3;
    vector<int> a = {1, -5, 10, -8}; // x^3 - 5x^2 + 10x - 8
    int root = 2;
    vector<int> q = syntheticDivision(a, root, n);

    cout << "Quotient polynomial: ";
    for (int coeff : q)
    {
        cout << coeff << " ";
    }
    cout << endl;
    return 0;
}