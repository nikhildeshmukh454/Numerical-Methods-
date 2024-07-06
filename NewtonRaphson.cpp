#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

double evaluatePolynomial(const vector<double>& coef, double x) {
    double result = 0.0;
    int degree = coef.size() - 1;
    
    for (int i = degree; i >= 0; --i) {
        result += coef[i] * pow(x, i);
    }
    
    return result;
}

double evaluateDerivative(const vector<double>& coef, double x) {
    double result = 0.0;
    int degree = coef.size() - 1;
    
    for (int i = degree; i >= 1; --i) {
        result += i * coef[i] * pow(x, i - 1);
    }
    
    return result;
}

double newtonRaphson(const vector<double>& coef, double guess1, int iterations) {
    double x0 = guess1;
    const double tolerance = 1e-9;
    
    for (int i = 0; i < iterations; ++i) {
        double f_x0 = evaluatePolynomial(coef, x0);
        double f_prime_x0 = evaluateDerivative(coef, x0);
        
        if (fabs(f_prime_x0) < tolerance) {
            return x0;
        }
        
        x0 = x0 - f_x0 / f_prime_x0;
    }
    
    return x0;
}
