#include <iostream>
#include <vector>

using namespace std;

// Function to perform LU decomposition
void luDecomposition(vector<vector<double>>& A, vector<vector<double>>& L, vector<vector<double>>& U) {
    int n = A.size();

    // Initialize L and U matrices
    L = vector<vector<double>>(n, vector<double>(n, 0.0));
    U = vector<vector<double>>(n, vector<double>(n, 0.0));

    // Perform LU decomposition
    for (int i = 0; i < n; i++) {
        // Upper triangular matrix U
        for (int k = i; k < n; k++) {
            double sum = 0.0;
            for (int j = 0; j < i; j++) {
                sum += L[i][j] * U[j][k];
            }
            U[i][k] = A[i][k] - sum;
        }

        // Lower triangular matrix L
        for (int k = i; k < n; k++) {
            if (i == k) {
                L[i][i] = 1.0; // Diagonal elements of L are 1
            } else {
                double sum = 0.0;
                for (int j = 0; j < i; j++) {
                    sum += L[k][j] * U[j][i];
                }
                L[k][i] = (A[k][i] - sum) / U[i][i];
            }
        }
    }
}

// Function to solve using LU decomposition
vector<double> solveUsingLU(vector<vector<double>>& A, vector<double>& b) {
    int n = A.size();
    vector<vector<double>> L, U;
    luDecomposition(A, L, U);

    // Solve LY = b using forward substitution
    vector<double> y(n);
    for (int i = 0; i < n; i++) {
        double sum = 0.0;
        for (int j = 0; j < i; j++) {
            sum += L[i][j] * y[j];
        }
        y[i] = (b[i] - sum) / L[i][i];
    }

    // Solve UX = Y using backward substitution
    vector<double> x(n);
    for (int i = n - 1; i >= 0; i--) {
        double sum = 0.0;
        for (int j = i + 1; j < n; j++) {
            sum += U[i][j] * x[j];
        }
        x[i] = (y[i] - sum) / U[i][i];
    }

    return x;
}
