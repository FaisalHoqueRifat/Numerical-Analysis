#include<bits/stdc++.h>
using namespace std;

// Function f(x,y) = x^3 + y
double f(double x, double y) {
    return x*x*x + y;
}

int main() {
    // Initial conditions
    double x0 = 0.0;
    double y0 = 1.0;
    double h = 0.01;
    double target_x = 0.02;
    
    double x = x0;
    double y = y0;
    
    cout << fixed << setprecision(6);
    cout << "Euler's Method Solution:" << endl;
    cout << "x = " << x << ", y = " << y << endl;
    
    // Apply Euler's method: y(n+1) = y(n) + h * f(x(n), y(n))
    while (x < target_x) {
        y = y + h * f(x, y);
        x = x + h;
        cout << "x = " << x << ", y = " << y << endl;
    }
    
    cout << "\nFinal result: y(0.02) = " << y << endl;
    
    return 0;
}
