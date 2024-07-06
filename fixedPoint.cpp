#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

// Function to evaluate the polynomial f(x) given the coefficients
double polynomial(const vector<double>& coeffs, double x) {
    double result = 0.0;
    for (int i = 0; i < coeffs.size(); ++i) {
        result += coeffs[i] * pow(x, i);
    }
    return result;
}

// Function g(x) for fixed point iteration, assuming g(x) = x - f(x)/f'(x)
double g(const vector<double>& coeffs, double x) {
    double fx = polynomial(coeffs, x);
    double dfx = 0.0;
    for (int i = 1; i < coeffs.size(); ++i) {
        dfx += i * coeffs[i] * pow(x, i - 1);
    }
    return x - fx / dfx;
}

// Function to perform the Fixed Point Iteration
double fixedPointIteration(const vector<double>& coeffs, double x0, double tol, int maxIter) {
    double x = x0;
    for (int i = 0; i < maxIter; ++i) {
        double x_new = g(coeffs, x);
        if (fabs(x_new - x) < tol) {
            return x_new;
        }
        x = x_new;
    }
    cout << "Fixed Point Iteration did not converge within the maximum number of iterations." << endl;
    return x;
}
