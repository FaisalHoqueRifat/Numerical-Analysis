#include<bits/stdc++.h>
using namespace std;

int main() 
{
    // Given data points
    vector<int> x = {-2, -1, 0, 1, 2};
    vector<int> y = {1, 2, 3, 4, 5};
    
    int n = x.size();
    
    double sum_x = 0, sum_y = 0, sum_x2 = 0, sum_xy = 0;
    
    for (int i = 0; i < n; i++)
    {
        sum_x += x[i];
        sum_y += y[i];
        sum_x2 += x[i] * x[i];
        sum_xy += x[i] * y[i];
    }
    
    // Using formulas to find a and b for y = a + bx
    // b = (nΣxy - ΣxΣy) / (nΣx² - (Σx)²)
    double b = (n * sum_xy - sum_x * sum_y) / (n * sum_x2 - sum_x * sum_x);
    
    // a = (Σy - bΣx) / n
    double a = (sum_y - b * sum_x) / n;
    
    cout << "The least square line is: y = " << a << " + " << b << "x" << endl;
    
    return 0;
}
