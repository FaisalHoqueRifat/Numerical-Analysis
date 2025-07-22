#include<bits/stdc++.h>
using namespace std;

// Function to calculate determinant of 3x3 matrix
double determinant3x3(double matrix[3][3]) {
    return matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1])
         - matrix[0][1] * (matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0])
         + matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]);
}

int main() {
    // Given data points
    double x[] = {2, 4, 6, 8};
    double y[] = {1.4, 2.0, 2.4, 2.8};
    int n = 4;
    
    // Calculate sums needed for normal equations
    double sum_1 = n;  // sum of 1's
    double sum_x = 0, sum_x2 = 0, sum_x3 = 0, sum_x4 = 0;
    double sum_y = 0, sum_xy = 0, sum_x2y = 0;
    
    for (int i = 0; i < n; i++) {
        sum_x += x[i];
        sum_x2 += x[i] * x[i];
        sum_x3 += x[i] * x[i] * x[i];
        sum_x4 += x[i] * x[i] * x[i] * x[i];
        sum_y += y[i];
        sum_xy += x[i] * y[i];
        sum_x2y += x[i] * x[i] * y[i];
    }
    
    // Set up coefficient matrix A and constant vector B for normal equations
    // Normal equations: A * [a, b, c]^T = B
    double A[3][3] = {
        {sum_1, sum_x, sum_x2},
        {sum_x, sum_x2, sum_x3},
        {sum_x2, sum_x3, sum_x4}
    };
    
    double B[3] = {sum_y, sum_xy, sum_x2y};
    
    // Calculate determinant of coefficient matrix
    double det_A = determinant3x3(A);
    
    if (det_A == 0) {
        cout << "System has no unique solution (determinant = 0)" << endl;
        return 1;
    }
    
    // Apply Cramer's rule to find a, b, c
    
    // For coefficient 'a': replace first column with B
    double A_a[3][3] = {
        {B[0], sum_x, sum_x2},
        {B[1], sum_x2, sum_x3},
        {B[2], sum_x3, sum_x4}
    };
    double a = determinant3x3(A_a) / det_A;
    
    // For coefficient 'b': replace second column with B
    double A_b[3][3] = {
        {sum_1, B[0], sum_x2},
        {sum_x, B[1], sum_x3},
        {sum_x2, B[2], sum_x4}
    };
    double b = determinant3x3(A_b) / det_A;
    
    // For coefficient 'c': replace third column with B
    double A_c[3][3] = {
        {sum_1, sum_x, B[0]},
        {sum_x, sum_x2, B[1]},
        {sum_x2, sum_x3, B[2]}
    };
    double c = determinant3x3(A_c) / det_A;
    
    // Display results
    cout << fixed << setprecision(6);
    cout << "Least Square Parabola: y = " << a << " + " << b << "x + " << c << "x²" << endl;
    cout << "\nCoefficients:" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;
    
    return 0;
}
