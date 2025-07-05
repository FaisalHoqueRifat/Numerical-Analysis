#include<bits/stdc++.h>
using namespace std;

// Function to calculate the determinant of a 3x3 matrix
double determinant(double a[3][3])
{
    return a[0][0]*(a[1][1]*a[2][2] - a[1][2]*a[2][1])
         - a[0][1]*(a[1][0]*a[2][2] - a[1][2]*a[2][0])
         + a[0][2]*(a[1][0]*a[2][1] - a[1][1]*a[2][0]);
}

// Function to find the inverse of a 3x3 matrix
void inverse(double a[3][3], double inv[3][3]) 
{
    double det = determinant(a);
    if (det == 0) 
    {
        cout << "Matrix is singular, cannot find inverse." << endl;
        return;
    }
    inv[0][0] = (a[1][1]*a[2][2] - a[1][2]*a[2][1]) / det;
    inv[0][1] = -(a[0][1]*a[2][2] - a[0][2]*a[2][1]) / det;
    inv[0][2] = (a[0][1]*a[1][2] - a[0][2]*a[1][1]) / det;
    inv[1][0] = -(a[1][0]*a[2][2] - a[1][2]*a[2][0]) / det;
    inv[1][1] = (a[0][0]*a[2][2] - a[0][2]*a[2][0]) / det;
    inv[1][2] = -(a[0][0]*a[1][2] - a[0][2]*a[1][0]) / det;
    inv[2][0] = (a[1][0]*a[2][1] - a[1][1]*a[2][0]) / det;
    inv[2][1] = -(a[0][0]*a[2][1] - a[0][1]*a[2][0]) / det;
    inv[2][2] = (a[0][0]*a[1][1] - a[0][1]*a[1][0]) / det;
}

int main() 
{
    double a[3][3], inv[3][3], b[3], x[3];
    cout << "Enter the 3x3 coefficient matrix row-wise:\n";
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            cin >> a[i][j];
    cout << "Enter the constants vector:\n";
    for (int i = 0; i < 3; i++)
        cin >> b[i];

    inverse(a, inv);

    // Multiply inverse matrix by constants vector
    for (int i = 0; i < 3; i++) 
    {
        x[i] = 0;
        for (int j = 0; j < 3; j++)
            x[i] += inv[i][j] * b[j];
    }

    cout << fixed << setprecision(4);
    cout << "Solution:\n";
    cout << "x = " << x[0] << "\ny = " << x[1] << "\nz = " << x[2] << endl;
    return 0;
}
