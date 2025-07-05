#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int a[3][3];
    int det;
    cout << "Enter elements of 3x3 matrix row-wise:\n";
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            cin >> a[i][j];

    det = a[0][0]*(a[1][1]*a[2][2] - a[1][2]*a[2][1])
        - a[0][1]*(a[1][0]*a[2][2] - a[1][2]*a[2][0])
        + a[0][2]*(a[1][0]*a[2][1] - a[1][1]*a[2][0]);

    cout << "Determinant: " << det << endl;
    return 0;
}
