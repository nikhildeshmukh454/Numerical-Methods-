#include <iostream>
#include <vector>
#include <cmath> // for fabs function
using namespace std;

// Function to evaluate the polynomial at a given point
double solveEqn(const vector<double>& coef, double root)
{
    double ans = 0;
    double factor = 1.0;

    for (int i = 0; i < coef.size(); i++)
    {
        ans += factor * coef[i];
        factor *= root;
    }

    return ans;
}

// Bisection method to find the root
double bisectionM(const vector<double>& coef, double guess1, double guess2, int iteration)
{
    if (solveEqn(coef, guess1) * solveEqn(coef, guess2) >= 0)
    {
        cout << "INVALID GUESS\n";
        return -1.0;
    }

    double ans = 0.0;

    while (iteration--)
    {
        double mid = (guess1 + guess2) / 2;
        double midans = solveEqn(coef, mid);

        if (fabs(midans) < 1e-9) // Mid is close enough to the root
        {
            return mid;
        }

        if (solveEqn(coef, guess1) * midans < 0)
        {
            guess2 = mid;
        }
        else
        {
            guess1 = mid;
        }

        ans = mid;
    }

    return ans;
}
