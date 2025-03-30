#include<bits/stdc++.h>
using namespace std;

double roundToSignificantFigures(double num, int n)
{
    if (num == 0.0) return 0.0;

    double d = ceil(log10(num < 0 ? -num : num));
    int power = n - static_cast<int>(d);

    double magnitude = pow(10.0, power);
    long shifted = round(num * magnitude);

    return shifted / magnitude;
}

int main()
{
    double number;
    int n;
    cout << "Enter a number: ";
    cin >> number;
    cout << "Enter number of significant figures: ";
    cin >> n;
    cout << "Rounded number: " << roundToSignificantFigures(number, n) << endl;
    return 0;
}