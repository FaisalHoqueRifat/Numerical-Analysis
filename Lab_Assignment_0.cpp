#include<bits/stdc++.h>
using namespace std;

int main()
{
    string input;
    getline(cin, input);
    vector<int>arr;
    stringstream ss(input);
    string word;
    while (ss >> word)
    {
        int n = stoi(word);
        arr.push_back(n);
    }
    cout<<"Number of Integer : "<<endl;
    cout<<arr.size()<<endl;
    for(int i = 0; i<arr.size(); i++)
    {
        cout<<arr[i]<<endl;
    }
    return 0;
}