#include<bits/stdc++.h>
using namespace std;

double bankersRounding(double num, int significantDigits)
{
    if (num == 0.0) return 0.0;
    
    int order = floor(log10(fabs(num))) + 1;
    double scale = pow(10, significantDigits - order);
    double rounded = round(num * scale);
  
    if (fabs(num * scale - rounded) == 0.5) 
    {
        if (static_cast<long long>(rounded) % 2 != 0)
        {
            rounded = (num > 0) ? rounded + 1 : rounded - 1;
        }
    }
    
    return rounded / scale;
}
int main()
{
    int test;
    cout<<"Enter The Number of Test Case: ";
    cin>>test;
    while (test--)
    {
        double number;
        int significantDigits;
        
        cout << "Enter a number: ";
        cin >> number;
        cout << "Enter the number of significant digits: ";
        cin >> significantDigits;
        
        double roundedValue = bankersRounding(number, significantDigits);
        
        cout << "Rounded number: " << setprecision(significantDigits) << roundedValue << endl;
    }
    
    return 0;
}

