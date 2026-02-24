// GFG - Count Subarrays with given XOR
// Difficulty: Medium
// Link: https://www.geeksforgeeks.org/problems/count-subarray-with-given-xor/1
//
// Approach: Prefix XOR + Hash Map (O(n) time, O(n) space)
//   - Maintain a running prefix XOR (curXOR).
//   - For each position r, we want subarrays [l..r] where XOR == k.
//   - XOR of arr[l..r] = prefXOR[r] ^ prefXOR[l-1]
//   - So we need prefXOR[l-1] = curXOR ^ k — count occurrences in freq map.
//   - Seed freq with {0: 1} to handle subarrays starting at index 0.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long subarrayXor(vector<int>& arr, int k) {
        unordered_map<int, int> freq;
        freq[0] = 1;   // empty prefix

        int curXOR = 0;
        long long ans = 0;

        for (int x : arr) {
            curXOR ^= x;
            int target = curXOR ^ k;
            ans += freq[target];
            freq[curXOR]++;
        }

        return ans;
    }
};

// ─── Driver / Testing ───────────────────────────────────────────────────────
int main() {
    Solution sol;

    // Test case 1 → Expected: 4
    vector<int> a1 = {4, 2, 2, 6, 4};
    cout << "Test 1: " << sol.subarrayXor(a1, 6) << " (expected 4)" << endl;

    // Test case 2 → Expected: 2
    vector<int> a2 = {5, 6, 7, 8, 9};
    cout << "Test 2: " << sol.subarrayXor(a2, 5) << " (expected 2)" << endl;

    // Test case 3 → Expected: 4
    vector<int> a3 = {1, 1, 1, 1};
    cout << "Test 3: " << sol.subarrayXor(a3, 0) << " (expected 4)" << endl;

    // Edge: single element equals k → 1
    vector<int> a4 = {7};
    cout << "Test 4: " << sol.subarrayXor(a4, 7) << " (expected 1)" << endl;

    // Edge: no subarray matches → 0
    vector<int> a5 = {1, 2, 3};
    cout << "Test 5: " << sol.subarrayXor(a5, 10) << " (expected 0)" << endl;

    // Edge: k = 0, all elements same → [1,1],[1,1],[1,1],[1,1,1,1] = 4 wait arr size 4
    vector<int> a6 = {5, 5, 5, 5};
    cout << "Test 6: " << sol.subarrayXor(a6, 0) << " (expected 4)" << endl;

    return 0;
}
