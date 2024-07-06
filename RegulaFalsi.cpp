#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

// Define the function for which you want to find the root
double f(const vector<double>& coeffs, double x) {
    double result = 0.0;
    int degree = coeffs.size() - 1;
    double factor=1;
    
    for (int i = 0; i <= degree; ++i) {
        result += coeffs[i] * factor;
        factor*=x;
    }
    
    return result;
}

// Implement the Regula Falsi method for a general equation
double regulaFalsi(const vector<double>& coeffs, double a, double b, double tol, int maxIter) {
    if (f(coeffs, a) * f(coeffs, b) >= 0) {
        cerr << "Error: The function must have different signs at a and b." << endl;
        return NAN;
    }

    double c = a; // Initialize c

    for (int i = 0; i < maxIter; ++i) {
        // Calculate the point c
        c = (a * f(coeffs, b) - b * f(coeffs, a)) / (f(coeffs, b) - f(coeffs, a));

        // Check if the value at c is close enough to zero (within the tolerance)
        if (abs(f(coeffs, c)) < tol) {
            break;
        }

        // Update the interval [a, b]
        if (f(coeffs, c) * f(coeffs, a) < 0) {
            b = c;
        } else {
            a = c;
        }
    }

    return c;
}
