#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 5;
    int x[] = {1, 2, 3, 4, 5};

    int y[n];
    y[0] = 1;
    y[1] = 8;
    y[2] = 27;
    y[3] = 64;
    y[4] = 125;

    int yi = 85;
    float xi;
    for (int i = 0; i < n; i++)
    {
        float up = 1, down = 1;
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                continue;
            }
            up *= (yi - y[j]);
            down *= (y[i] - y[j]);
        }
        xi += (up / down) * x[i];
    }
    cout << xi << endl;
    return 0;
}
