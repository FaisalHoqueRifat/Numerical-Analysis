#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x;
    cin >> x;
    vector<vector<int>> table;
    vector<int> y(x);
    for (int i = 0; i < x; i++)
    {
        cout << "Enter the value of f(" << i + 1 << ")" << endl;
        cin >> y[i];
    }
    table.push_back(y);
    x--;
    while (x > 0)
    {
        vector<int> y1;
        vector<int> y0;
        y0 = table[table.size() - 1];
        for (int i = 0; i < y0.size() - 1; i++)
        {
            y1.push_back(y0[i + 1] - y0[i]);
        }
        table.push_back(y1);
        x--;
    }
    cout << "Difference Table:" << endl;
    for (int i = 0; i < table.size(); i++)
    {
        for (int j = 0; j < table[i].size(); j++)
        {
            cout << setw(5) << table[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}