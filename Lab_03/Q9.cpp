#include<bits/stdc++.h>
using namespace std;

int main() 
{
    float a[3][4];
    int n = 3;

    cout << "Enter the augmented matrix (3x4) row-wise:\n";
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n + 1; j++)
            cin >> a[i][j];

    // Forward elimination
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = i + 1; j < n; j++) 
        {
            float ratio = a[j][i] / a[i][i];
            for(int k = 0; k <= n; k++)
                a[j][k] -= ratio * a[i][k];
        }
    }

    // Back substitution
    float x[3];
    for(int i = n - 1; i >= 0; i--) 
    {
        x[i] = a[i][n];
        for(int j = i + 1; j < n; j++)
            x[i] -= a[i][j] * x[j];
        x[i] /= a[i][i];
    }

    cout << fixed << setprecision(4);
    cout << "Solution:\n";
    cout << "x = " << x[0] << "\ny = " << x[1] << "\nz = " << x[2] << endl;
    return 0;
}
