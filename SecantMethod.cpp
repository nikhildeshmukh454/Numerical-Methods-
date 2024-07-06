#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

// Function to evaluate the polynomial at a given root
double evaluatePolynomial(const vector<double>& coef, double root) {
    double result = 0.0;
    double factor = 1.0;

    for (int i = 0; i < coef.size(); i++) {
        result += factor * coef[i];
        factor *= root;
    }

    return result;
}

// Function to find the next approximation (Secant method) for the root
double secantMethod(const vector<double>& coef, double guess1, double guess2, int iterations) {
    // Check if initial guesses are valid (should have opposite signs)
    if (evaluatePolynomial(coef, guess1) * evaluatePolynomial(coef, guess2) >= 0) {
        cout << "Invalid initial guesses.\n";
        return -1.0;
    }

    double root = 0.0;

    // Perform iterations to approximate the root
    while (iterations--) {
        double mid = guess2 - (evaluatePolynomial(coef, guess2) * (guess2 - guess1)) /
                            (evaluatePolynomial(coef, guess2) - evaluatePolynomial(coef, guess1));

        double midValue = evaluatePolynomial(coef, mid);

        // If the approximation is close enough to zero, return the root
        if (fabs(midValue) < 1e-9) {
            return mid;
        }

        // Update the guesses for the next iteration
        guess1 = guess2;
        guess2 = mid;
        root = mid;
    }

    return root;
}
