#include <bits/stdc++.h>
using namespace std;

bool containsDot(string& str) 
{
    if (str.find('.') != string::npos) 
    {
        return true;
    } 
    else 
    {
        return false;
    }
}
int countTrailingZeros(int n)
{
    if (n == 0) return 0;
    int count = 0;
    while (n % 10 == 0) 
    {
        count++;
        n /= 10;
    }
    return count;
}

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
    if(containsDot(number))
    {
        cout << "Number of significant digits: " << countSignificantDigits(number) << endl;
    }
    else{
        cout<<int(number.size())-countTrailingZeros(stoi(number))<<endl;
    }
    return 0;
}