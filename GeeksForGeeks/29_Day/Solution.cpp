#include <bits/stdc++.h>
using namespace std;

/*
 * Approach: Prefix Sum + Earliest-Index Vector  O(n) time, O(n) space
 *
 * Transform: arr[i] > k  -> +1,  arr[i] <= k -> -1  (stored in var)
 * Problem becomes: longest subarray with sum >= 1.
 *
 * store[j] = earliest index at which prefix sum equals -j.
 *   store[0] = -1  (prefix sum 0 before the array starts)
 *
 * For each i:
 *   var > 0  -> entire [0..i] is valid, ans = i+1
 *   var <= 0 -> need earliest l where prefix[l] = var-1
 *               i.e. store[1-var], and length = i - store[1-var]
 *
 * We only append to store when store.size() == -var (brand-new minimum),
 * which is valid because each step changes var by exactly ±1.
 */

class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        int var = 0, ans = 0;
        vector<int> store{-1}; // store[0] = -1 (prefix 0 at index -1)

        for (int i = 0; i < (int)arr.size(); i++) {
            var += (arr[i] > k ? 1 : -1);

            if (var > 0) {
                // Entire prefix [0..i] has sum > 0
                ans = i + 1;
            } else if (1 - var < (int)store.size()) {
                // Earliest index where prefix sum == var-1 is store[1-var]
                ans = max(ans, i - store[1 - var]);
            }

            // Only record a new minimum prefix sum (first time -var is seen)
            if ((int)store.size() == -var) {
                store.push_back(i);
            }
        }

        return ans;
    }
};

// ─── Driver ──────────────────────────────────────────────────────────────────
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution sol;

    // Test 1: Expected 3
    {
        vector<int> arr = {1, 2, 3, 4, 1};
        cout << "Test 1: " << sol.longestSubarray(arr, 2) << " (expected 3)\n";
    }

    // Test 2: Expected 4
    {
        vector<int> arr = {6, 5, 3, 4};
        cout << "Test 2: " << sol.longestSubarray(arr, 2) << " (expected 4)\n";
    }

    // Test 3: All elements <= k  → Expected 0
    {
        vector<int> arr = {1, 1, 1};
        cout << "Test 3: " << sol.longestSubarray(arr, 5) << " (expected 0)\n";
    }

    // Test 4: Single element > k  → Expected 1
    {
        vector<int> arr = {5};
        cout << "Test 4: " << sol.longestSubarray(arr, 3) << " (expected 1)\n";
    }

    // Test 5: Alternating +1/-1 with majority > k  → Expected 5
    {
        vector<int> arr = {3, 1, 3, 1, 3};
        cout << "Test 5: " << sol.longestSubarray(arr, 2) << " (expected 5)\n";
    }

    // Test 6: All same and > k  → Expected 5
    {
        vector<int> arr = {3, 1, 3, 1, 3};
        cout << "Test 6: " << sol.longestSubarray(arr, 0) << " (expected 5)\n";
    }

    return 0;
}
