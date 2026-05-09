#include <vector>
#include <iostream>
#include <cmath>

using namespace std;


class Solution {
public:
    double determinant(vector<vector<double>>& matrix) {
        int n = matrix.size();
        double det = 1.0;

        for (int i = 0; i < n; ++i) {
            // Find pivot
            int pivot = i;
            for (int j = i + 1; j < n; ++j) {
                if (abs(matrix[j][i]) > abs(matrix[pivot][i])) {
                    pivot = j;
                }
            }

            // Swap rows
            if (pivot != i) {
                swap(matrix[i], matrix[pivot]);
                det *= -1;
            }

            if (abs(matrix[i][i]) < 1e-9) {
                return 0;
            }

            det *= matrix[i][i];

            for (int j = i + 1; j < n; ++j) {
                double factor = matrix[j][i] / matrix[i][i];
                for (int k = i + 1; k < n; ++k) {
                    matrix[j][k] -= factor * matrix[i][k];
                }
            }
        }

        return det;
    }

    int countSpanTree(int n, vector<vector<int>>& edges) {
        // Base case for 1 vertex
        if (n <= 1) return 1;

        // 1. Build the Laplacian Matrix L = D - A
        // D: Degree matrix, A: Adjacency matrix
        vector<vector<double>> laplacian(n, vector<double>(n, 0.0));

        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            
            // Adjacency part (A)
            laplacian[u][v]--;
            laplacian[v][u]--;
            
            // Degree part (D)
            laplacian[u][u]++;
            laplacian[v][v]++;
        }

        // 2. Create a submatrix by removing the last row and column (Cofactor)
        vector<vector<double>> cofactor(n - 1, vector<double>(n - 1));
        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < n - 1; ++j) {
                cofactor[i][j] = laplacian[i][j];
            }
        }

        // 3. The determinant of this cofactor matrix is the number of spanning trees
        double result = determinant(cofactor);

        // Round to the nearest integer as the count must be an integer
        return (int)round(abs(result));
    }
};
