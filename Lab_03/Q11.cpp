#include<bits/stdc++.h>
using namespace std;

int main() 
{
    // Example system:
    // 10x + y + z = 12
    // 2x + 10y + z = 13
    // 2x + 2y + 10z = 14

    double a[3][3] = {{10, 1, 1}, {2, 10, 1}, {2, 2, 10}};
    double b[3] = {12, 13, 14};
    double x[3] = {0, 0, 0}; // Initial guesses
    double x_new[3];
    double tol = 1e-4;
    int max_iter = 100, iter = 0;

    while (iter < max_iter)
    {
        x_new[0] = (b[0] - a[0][1]*x[1] - a[0][2]*x[2]) / a[0][0];
        x_new[1] = (b[1] - a[1][0]*x[0] - a[1][2]*x[2]) / a[1][1];
        x_new[2] = (b[2] - a[2][0]*x[0] - a[2][1]*x[1]) / a[2][2];

        if (fabs(x_new[0] - x[0]) < tol &&
            fabs(x_new[1] - x[1]) < tol &&
            fabs(x_new[2] - x[2]) < tol)
            break;

        x[0] = x_new[0];
        x[1] = x_new[1];
        x[2] = x_new[2];
        iter++;
    }

    cout << "Solution after " << iter << " iterations:\n";
    cout << "x = " << x[0] << endl;
    cout << "y = " << x[1] << endl;
    cout << "z = " << x[2] << endl;
    return 0;
}
