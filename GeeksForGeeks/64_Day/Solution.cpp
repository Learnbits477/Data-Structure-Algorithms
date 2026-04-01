#include <iostream>
#include <vector>

using namespace std;

/**
 * Problem: Consecutive 1's not allowed
 * Source: https://www.geeksforgeeks.org/problems/consecutive-1s-not-allowed1912/1
 * 
 * Approach: Dynamic Programming
 * We maintain two states for each length i:
 * 1. a: Number of binary strings of length i ending with 0.
 * 2. b: Number of binary strings of length i ending with 1.
 * 
 * Transitions for length i:
 * a[i] = (a[i-1] + b[i-1]) % mod (We can append 0 to any valid string)
 * b[i] = a[i-1] (We can only append 1 to a string ending in 0)
 * 
 * Total valid strings of length i = (a[i] + b[i]) % mod.
 * 
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

class Solution {
public:
    // Function to count the number of binary strings without consecutive 1's
    long long countStrings(int n) {
        if (n == 0) return 0;
        
        const int mod = 1e9 + 7;
        
        // Base case: length 1
        // "0" ends in 0, "1" ends in 1
        long long a = 1; // Strings ending with 0
        long long b = 1; // Strings ending with 1
        
        for (int i = 2; i <= n; i++) {
            long long prev_a = a;
            a = a + b;
            b = prev_a;
        }
  
        return (b + a);
    }
};

int main() {
    Solution sol;
    
    // Example 1
    int n1 = 3;
    cout << "Example 1 (n=3): Output: " << sol.countStrings(n1) << " (Expected: 5)" << endl;
    
    // Example 2
    int n2 = 2;
    cout << "Example 2 (n=2): Output: " << sol.countStrings(n2) << " (Expected: 3)" << endl;
    
    // Example 3
    int n3 = 1;
    cout << "Example 3 (n=1): Output: " << sol.countStrings(n3) << " (Expected: 2)" << endl;

    return 0;
}
