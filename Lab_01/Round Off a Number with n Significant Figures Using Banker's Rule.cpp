#include<bits/stdc++.h>
using namespace std;

vector<int> getSignificantIndexes(string number, int n) 
{
    vector<int> indexes;
    bool significantEncountered = false;
    for (int i = 0; i < number.size(); i++) 
    {
        if (isdigit(number[i])) 
        {
            if (number[i] != '0' || significantEncountered) 
            {
                significantEncountered = true;
                indexes.push_back(i);
                if (indexes.size() == n)
                    break;
            }
        }
    }
    return indexes;
}

string roundToNSignificant(string number, int n)
{

    vector<int> sigIdx = getSignificantIndexes(number, n+1);

    if (sigIdx.size() < n)
        return number;

    string result = number;

    if (sigIdx.size() == n)
        return number.substr(0, sigIdx[n-1]+1);

    int nthIdx = sigIdx[n-1];
    int n1thIdx = sigIdx[n];

    char nthVal = number[nthIdx];
    char n1thVal = number[n1thIdx];

    bool roundUp = false;

    if (n1thVal < '5')
        roundUp = false;
    else if (n1thVal > '5')
        roundUp = true;
    else 
    {
        if ((nthVal - '0') % 2 == 0)
            roundUp = false;
        else
            roundUp = true;
    }

    string rounded = number.substr(0, nthIdx+1);

    if (roundUp) 
    {
        int i = nthIdx;
        while (i >= 0) 
        {
            if (!isdigit(rounded[i])) 
            {
                i--;
                continue;
            }
            if (rounded[i] < '9') 
            {
                rounded[i] += 1;
                break;
            } 
            else
            {
                rounded[i] = '0';
                i--;
            }
        }
        if (i < 0)
            rounded = "1" + rounded;
    }
    return rounded;
}

int main() 
{
    string number;
    int n;
    cout << "Enter a number: ";
    cin >> number;
    cout << "Enter n (significant digits to keep): ";
    cin >> n;

    string res = roundToNSignificant(number, n);
    cout << "Rounded to " << n << " significant digits: " << res << endl;

    return 0;
}