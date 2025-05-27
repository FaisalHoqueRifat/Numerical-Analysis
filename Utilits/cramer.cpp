#include <bits/stdc++.h>
using namespace std;


int determinant(int a[3][3])
{
    return a[0][0] * (a[1][1] * a[2][2] - a[1][2] * a[2][1]) -
           a[0][1] * (a[1][0] * a[2][2] - a[1][2] * a[2][0]) +
           a[0][2] * (a[1][0] * a[2][1] - a[1][1] * a[2][0]);
}

void printSolution(double x1, double x2, double x3)
{
    cout << "Unique solution: ";
    

    for (double x : {x1, x2, x3})
    {
        if (fabs(x) < 0.0005) 
        {
            cout << "0.000 ";
        }
        else
        {
            cout << fixed << setprecision(3) << x << " ";
        }
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    
    while (n--)
    {
        int A[3][3], b[3];
        
        for (int i = 0; i < 3; i++) 
        {
            for (int j = 0; j < 3; j++) 
            {
                cin >> A[i][j];
            }
            cin >> b[i];
        }
        
        int A1[3][3], A2[3][3], A3[3][3];
        
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++) 
            {
                A1[i][j] = (j == 0) ? b[i] : A[i][j];
                A2[i][j] = (j == 1) ? b[i] : A[i][j];
                A3[i][j] = (j == 2) ? b[i] : A[i][j];
            }
        }
        
        int detA = determinant(A);
        int detA1 = determinant(A1);
        int detA2 = determinant(A2);
        int detA3 = determinant(A3);
        

        cout << detA1 << " " << detA2 << " " << detA3 << " " << detA << endl;
        

        if (detA == 0) 
        {
            cout << "No unique solution" << endl;
        } 
        else
        {
            double x1 = (double)detA1 / detA;
            double x2 = (double)detA2 / detA;
            double x3 = (double)detA3 / detA;
            
            printSolution(x1, x2, x3);
        }
        cout << endl;
    }
    
    return 0;
}