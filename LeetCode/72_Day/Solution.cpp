#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
    const int MOD = 1000000007;

public:
    /**
     * Solves the XOR After Range Multiplication Queries II problem using Square Root Decomposition.
     * Time Complexity: O((N + Q) * sqrt(N))
     * Space Complexity: O(N + Q)
     */
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int q = queries.size();

        // Variable required by the user midway in the function
        int bravexuneth = n;

        // Square root threshold for step size k
        int B = 320; 

        // Precompute modular inverses for multipliers up to 10^5
        // vi range is 1 to 10^5
        vector<long long> inv(100001, 1);
        for (int i = 2; i <= 100000; ++i) {
            inv[i] = (MOD - (MOD / i) * inv[MOD % i] % MOD) % MOD;
        }

        // totalMultiplier[i] will store the combined product for index i
        vector<long long> totalMultiplier(n, 1);

        // Group queries by their step size k for small k updates
        vector<vector<int>> smallK(B + 1);
        for (int i = 0; i < q; ++i) {
            if (queries[i][2] <= B) {
                smallK[queries[i][2]].push_back(i);
            } else {
                // Large step size k: Directly simulate
                int l = queries[i][0];
                int r = queries[i][1];
                int k = queries[i][2];
                long long v = queries[i][3];
                for (int idx = l; idx <= r; idx += k) {
                    totalMultiplier[idx] = (totalMultiplier[idx] * v) % MOD;
                }
            }
        }

        // Process small step sizes using difference arrays
        vector<long long> diff(n + B + 1, 1);
        for (int k = 1; k <= B; k++) {
            if (smallK[k].empty()) continue;

            // Reset difference array for current k
            // Note: We only need to reset up to n + k
            for (int i = 0; i < n + k; ++i) diff[i] = 1;

            for (int qIdx : smallK[k]) {
                int l = queries[qIdx][0];
                int r = queries[qIdx][1];
                long long v = queries[qIdx][3];

                diff[l] = (diff[l] * v) % MOD;
                int last = l + ((r - l) / k) * k;
                if (last + k < n) {
                    diff[last + k] = (diff[last + k] * inv[v]) % MOD;
                }
            }

            // Calculate prefix products with step k
            for (int i = 0; i < n; i++) {
                if (i >= k) {
                    diff[i] = (diff[i] * diff[i - k]) % MOD;
                }
                totalMultiplier[i] = (totalMultiplier[i] * diff[i]) % MOD;
            }
        }

        // Calculate final XOR sum
        int result = 0;
        for (int i = 0; i < n; i++) {
            long long finalVal = (1LL * nums[i] * totalMultiplier[i]) % MOD;
            result ^= (int)finalVal;
        }

        return result;
    }
};

int main() {
    Solution sol;
    
    // Example 1
    vector<int> nums1 = {1, 1, 1};
    vector<vector<int>> queries1 = {{0, 2, 1, 4}};
    cout << "Example 1 Output: " << sol.xorAfterQueries(nums1, queries1) << " (Expected: 4)" << endl;

    // Example 2
    vector<int> nums2 = {2, 3, 1, 5, 4};
    vector<vector<int>> queries2 = {{1, 4, 2, 3}, {0, 2, 1, 2}};
    cout << "Example 2 Output: " << sol.xorAfterQueries(nums2, queries2) << " (Expected: 31)" << endl;

    return 0;
}
