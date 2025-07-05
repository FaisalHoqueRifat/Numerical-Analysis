#include <bits/stdc++.h>
using namespace std;

// Function to calculate determinant of a 3x3 matrix
double det3(double a[3][3]) 
{
    return a[0][0]*(a[1][1]*a[2][2] - a[1][2]*a[2][1])
         - a[0][1]*(a[1][0]*a[2][2] - a[1][2]*a[2][0])
         + a[0][2]*(a[1][0]*a[2][1] - a[1][1]*a[2][0]);
}

int main() 
{
    double a[3][3], b[3];
    cout << "Enter the 3x3 coefficient matrix row-wise:\n";
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            cin >> a[i][j];
    cout << "Enter the constants vector:\n";
    for (int i = 0; i < 3; i++)
        cin >> b[i];

    double D = det3(a);

    // Create matrices for Dx, Dy, Dz
    double ax[3][3], ay[3][3], az[3][3];
    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 3; j++)
        {
            ax[i][j] = (j == 0) ? b[i] : a[i][j];
            ay[i][j] = (j == 1) ? b[i] : a[i][j];
            az[i][j] = (j == 2) ? b[i] : a[i][j];
        }
    }

    double Dx = det3(ax);
    double Dy = det3(ay);
    double Dz = det3(az);

    if (D == 0) 
    {
        cout << "No unique solution exists." << endl;
    } 
    else
    {
        cout << "x = " << Dx / D << endl;
        cout << "y = " << Dy / D << endl;
        cout << "z = " << Dz / D << endl;
    }
    return 0;
}
