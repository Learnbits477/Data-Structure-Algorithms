#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Method 1: Iterative Euclidean Algorithm (Primary - O(log(min(n, m))) Time, O(1) Space)
    long long minSquares(long long n, long long m) {
        // Step: 01 - Handle trivial dimensions
        if (n <= 0 || m <= 0) {
            return 0;
        }

        // Step: 02 - Initialize counter for squares
        long long totalSquares = 0;

        // Step: 03 - Perform Euclidean division until paper is fully dissected
        while (m > 0) {
            // Ensure n is the larger or equal dimension
            if (n < m) {
                swap(n, m);
            }

            // Step: 04 - Carve out all possible squares of size m x m
            totalSquares += (n / m);

            // Step: 05 - Update remaining rectangle dimension
            long long remainder = n % m;
            n = m;
            m = remainder;
        }

        // Step: 06 - Return accumulated square count
        return totalSquares;
    }

    // Method 2: Recursive Euclidean Algorithm (Alternative - O(log(min(n, m))) Time, O(log(min(n, m))) Space)
    long long minSquaresRecursive(long long n, long long m) {
        // Step: 01 - Base condition for zero dimension
        if (n <= 0 || m <= 0) {
            return 0;
        }

        // Step: 02 - Normalize orientation
        if (n < m) {
            return minSquaresRecursive(m, n);
        }

        // Step: 03 - Recursively accumulate squares
        return (n / m) + minSquaresRecursive(m, n % m);
    }

    // Overload for 32-bit integer interfaces
    int minSquares(int n, int m) {
        // Step: 01 - Delegate to 64-bit implementation
        return static_cast<int>(minSquares(static_cast<long long>(n), static_cast<long long>(m)));
    }

    // Alias wrapper for alternative naming conventions
    long long minimumSquares(long long n, long long m) {
        // Step: 01 - Delegate to minSquares
        return minSquares(n, m);
    }

    int minimumSquares(int n, int m) {
        // Step: 01 - Delegate to minSquares
        return minSquares(n, m);
    }
};
