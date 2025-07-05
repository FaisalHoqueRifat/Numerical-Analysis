#include <bits/stdc++.h>
using namespace std;

int main()
{
    float a[3][4];
    int n = 3;

    cout << "Enter the augmented matrix (3x4) row-wise:\n";
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n + 1; j++)
            cin >> a[i][j];

    // Gauss-Jordan elimination
    for(int i = 0; i < n; i++) 
    {
        // Make the diagonal element 1
        float div = a[i][i];
        for(int j = 0; j <= n; j++)
            a[i][j] /= div;

        // Make other elements in column i zero
        for(int k = 0; k < n; k++) 
        {
            if(k != i) 
            {
                float ratio = a[k][i];
                for(int j = 0; j <= n; j++)
                    a[k][j] -= ratio * a[i][j];
            }
        }
    }

    cout << "Solution:\n";
    cout << "x = " << a[0][3] << endl;
    cout << "y = " << a[1][3] << endl;
    cout << "z = " << a[2][3] << endl;
    return 0;
}
