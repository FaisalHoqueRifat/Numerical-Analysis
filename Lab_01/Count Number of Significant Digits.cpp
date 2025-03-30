#include <bits/stdc++.h>
using namespace std;

int countSignificantDigits(string number)
{
    int count = 0;
    bool significantDigitEncountered = false;

    for (char ch : number)
    {
        if (isdigit(ch))
        {
            if (ch != '0' || significantDigitEncountered)
            {
                significantDigitEncountered = true;
                count++;
            }
        }
    }

    return count;
}

int main()
{
    string number;
    cout << "Enter a number: ";
    cin >> number;
    cout << "Number of significant digits: " << countSignificantDigits(number) << endl;
    return 0;
}