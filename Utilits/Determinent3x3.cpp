#include <bits/stdc++.h>
using namespace std;

// Function to calculate determinant of 3x3 matrix
double calculateDeterminant(double matrix[3][3]) 
{
    double det = 0;
    
    // Using the formula: det = a(ei-fh) - b(di-fg) + c(dh-eg)
    // Where matrix is:
    // a b c
    // d e f  
    // g h i
    
    det = matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1])
        - matrix[0][1] * (matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0])
        + matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]);
    
    return det;
}

// Function to display the matrix
void displayMatrix(double matrix[3][3]) 
{
    cout << "\nMatrix:" << endl;
    for(int i = 0; i < 3; i++)
    {
        cout << "| ";
        for(int j = 0; j < 3; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << "|" << endl;
    }
}

// Function to input matrix elements
void inputMatrix(double matrix[3][3]) 
{
    cout << "Enter the elements of 3x3 matrix:" << endl;
    for(int i = 0; i < 3; i++) 
    {
        for(int j = 0; j < 3; j++)
        {
            cout << "Enter element [" << i+1 << "][" << j+1 << "]: ";
            cin >> matrix[i][j];
        }
    }
}

int main()
{
    double matrix[3][3];
    
    cout << "=== 3x3 Matrix Determinant Calculator ===" << endl;
    
    // Input matrix
    inputMatrix(matrix);
    
    // Display matrix
    displayMatrix(matrix);
    
    // Calculate determinant
    double determinant = calculateDeterminant(matrix);
    
    // Display result
    cout << "\nDeterminant of the matrix = " << determinant << endl;
    
    return 0;
}