#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Function to perform Gauss-Jordan elimination
vector<double> gaussJordan(vector<vector<double>>& A, vector<double>& b) {
    int n = b.size();

    // Augmenting matrix A with b
    for (int i = 0; i < n; i++) {
        A[i].push_back(b[i]);
    }

    // Performing forward elimination to obtain row echelon form
    for (int i = 0; i < n; i++) {
        // Normalize the pivot row
        double pivot = A[i][i];
        for (int j = i; j <= n; j++) {
            A[i][j] /= pivot;
        }

        // Eliminate the lower entries
        for (int k = 0; k < n; k++) {
            if (k != i) {
                double factor = A[k][i];
                for (int j = i; j <= n; j++) {
                    A[k][j] -= factor * A[i][j];
                }
            }
        }
    }

    // Extracting the solution from the augmented matrix
    vector<double> x(n);
    for (int i = 0; i < n; i++) {
        x[i] = A[i][n];
    }

    return x;
}
