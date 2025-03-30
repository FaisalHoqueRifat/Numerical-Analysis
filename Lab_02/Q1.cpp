#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 5;
    int x[] = {1, 2, 3, 4, 5};

    int y[n][n];
    y[0][0] = 1;
    y[1][0] = 8;
    y[2][0] = 27;
    y[3][0] = 64;
    y[4][0] = 125;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
            y[j][i] = y[j + 1][i - 1] - y[j][i - 1];
    }

    for (int i = 0; i < n; i++)
    {
        cout << setw(4) << x[i] << "\t";
        for (int j = 0; j < n - i; j++)
        {
            cout << setw(4) << y[i][j] << "\t";
        }
        cout << endl;
    }
    return 0;
}
