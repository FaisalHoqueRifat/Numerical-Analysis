#include<bits/stdc++.h>
using namespace std;

int countSignificantDigits(string num)
{
    int count = 0;
    bool foundNonZero = false;
    
    for (char ch : num)
    {
        if (isdigit(ch))
        {
            if (ch != '0') 
            {
                foundNonZero = true;
            }
            if (foundNonZero)
            {
                count++;
            }
        }
    }
    return count;
}
int main()
{
    int test;
    cout<<"Enter The Number of Test Case: ";
    cin>>test;
    while (test--)
    {
        string num;
        cout << "Enter a number: ";
        cin >> num;
        
        int sigDigits = countSignificantDigits(num);
        cout << "Number of significant digits: " << sigDigits << endl;
    }
    
    return 0;
}
