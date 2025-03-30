#include <bits/stdc++.h>
using namespace std;

float proterm(int i, float xi, int x[])
{
    float pro = 1;
    for (int j = 0; j < i; j++)
    {
        pro = pro * (xi - x[j]);
    }
    return pro;
}

void dividedDiffTable(int x[], float y[][10], int n)
{
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            y[j][i] = (y[j][i - 1] - y[j + 1][i - 1]) / (x[j] - x[i + j]);
        }
    }
}

float applyFormula(float xi, int x[], float y[][10], int n)
{
    float sum = y[0][0];

    for (int i = 1; i < n; i++)
    {
        sum = sum + (proterm(i, xi, x) * y[0][i]);
    }
    return sum;
}

void printDiffTable(float y[][10], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            cout << setprecision(4) << y[i][j] << "\t ";
        }
        cout << endl;
    }
}

int main()
{
    int n = 5;
    float xi, sum, y[10][10];
    int x[] = {1, 3, 4, 6, 10};

    y[0][0] = 0;
    y[1][0] = 18;
    y[2][0] = 58;
    y[3][0] = 190;
    y[4][0] = 920;

    dividedDiffTable(x, y, n);
    printDiffTable(y, n);

    xi = 2.7;
    sum = applyFormula(xi, x, y, n);
    cout << "\nValue at " << xi << " is " << sum << endl;
    return 0;
}
