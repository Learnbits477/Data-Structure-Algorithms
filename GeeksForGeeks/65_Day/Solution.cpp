#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Painting the Fence
 * Link: https://www.geeksforgeeks.org/problems/painting-the-fence3727/1
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

class Solution {
  public:
    long long countWays(int n, int k) {
        // Base cases
        if (n == 1) return k;
        if (n == 2) return (long long)k * k;

        // DP array to store the result of painting n posts
        // We can optimize the space to O(1) using two variables
        long long prev2 = k;            // n = 1
        long long prev1 = (long long)k * k; // n = 2
        long long current;

        for (int i = 3; i <= n; i++) {
            // The recurrence relation is:
            // total[i] = (total[i-1] + total[i-2]) * (k - 1)
            // Where (k-1) represents the number of ways to choose a 
            // different color for the current post.
            current = (prev1 + prev2) * (k - 1);
            
            // Result is guaranteed to fit in 32-bit int, 
            // but we use long long for intermediate safety.
            prev2 = prev1;
            prev1 = current;
        }

        return prev1;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        Solution obj;
        cout << obj.countWays(n, k) << endl;
    }
    return 0;
}
