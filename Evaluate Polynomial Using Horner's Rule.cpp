#include<bits/stdc++.h>
using namespace std;

int evaluatePolynomial(int x) 
{
    return (x*(x*(x-2)+5)+10);
}

int main() 
{
    int x = 5;
    cout << "f(5) = " << evaluatePolynomial(x) << endl;
    int a3 = 1;
    int a2 = -2;
    int a1 = 5;
    int a0 = 10;
    int p3 = a3;
    int p2 = p3*x + a2;
    int p1 = p2*x + a1;
    int p0 = p1*x + a0;
    cout << "f(5) = " << p0 << endl;
    return 0;
}