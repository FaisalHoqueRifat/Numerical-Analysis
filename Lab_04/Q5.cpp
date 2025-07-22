#include<bits/stdc++.h>
using namespace std;

// Function f(x,y) = x + y
double f(double x, double y) {
    return x + y;
}

// Fourth-order Runge-Kutta method
double rungeKutta(double x0, double y0, double h, double target_x) {
    double x = x0;
    double y = y0;
    
    cout << fixed << setprecision(6);
    cout << "x = " << x << ", y = " << y << endl;
    
    while (x < target_x) {
        // Calculate k1, k2, k3, k4
        double k1 = h * f(x, y);
        double k2 = h * f(x + h/2, y + k1/2);
        double k3 = h * f(x + h/2, y + k2/2);
        double k4 = h * f(x + h, y + k3);
        
        // Update y using weighted average
        y = y + (k1 + 2*k2 + 2*k3 + k4) / 6;
        x = x + h;
        
        cout << "x = " << x << ", y = " << y << endl;
    }
    
    return y;
}

int main() {
    // Initial conditions
    double x0 = 0.0;
    double y0 = 1.0;
    double h = 0.1;
    
    cout << "Runge-Kutta Method Solution:" << endl;
    
    // Find y(0.1)
    cout << "\nCalculating y(0.1):" << endl;
    double y_01 = rungeKutta(x0, y0, h, 0.1);
    cout << "y(0.1) = " << y_01 << endl;
    
    // Find y(0.2)
    cout << "\nCalculating y(0.2):" << endl;
    double y_02 = rungeKutta(x0, y0, h, 0.2);
    cout << "y(0.2) = " << y_02 << endl;
    
    return 0;
}
