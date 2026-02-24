// GFG - Find H-Index
// Difficulty: Medium
// Link: https://www.geeksforgeeks.org/problems/find-h-index--165609/1
//
// Approach: Counting / Bucket Sort (O(n) time, O(n) space)
//   - H-index is at most n (total papers).
//   - Build a count array where cnt[i] = number of papers with exactly i citations
//     (citations > n are clamped to index n).
//   - Traverse from h = n down to 0, accumulating papers seen.
//   - The first h where cumulative papers >= h is the answer.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();

        // cnt[i] = number of papers with citation count i (clamped at n)
        vector<int> cnt(n + 1, 0);
        for (int c : citations) {
            cnt[min(c, n)]++;
        }

        int papers = 0;
        // Traverse from highest possible H down to 0
        for (int h = n; h >= 0; h--) {
            papers += cnt[h];
            if (papers >= h) {
                return h;
            }
        }
        return 0;
    }
};

// ─── Driver / Testing ───────────────────────────────────────────────────────
int main() {
    Solution sol;

    // Test case 1 → Expected: 3
    vector<int> c1 = {3, 0, 5, 3, 0};
    cout << "Test 1: " << sol.hIndex(c1) << " (expected 3)" << endl;

    // Test case 2 → Expected: 2
    vector<int> c2 = {5, 1, 2, 4, 1};
    cout << "Test 2: " << sol.hIndex(c2) << " (expected 2)" << endl;

    // Test case 3 → Expected: 0
    vector<int> c3 = {0, 0};
    cout << "Test 3: " << sol.hIndex(c3) << " (expected 0)" << endl;

    // Edge: single paper with many citations → H = 1
    vector<int> c4 = {100};
    cout << "Test 4: " << sol.hIndex(c4) << " (expected 1)" << endl;

    // Edge: all zeros → H = 0
    vector<int> c5 = {0, 0, 0};
    cout << "Test 5: " << sol.hIndex(c5) << " (expected 0)" << endl;

    // Edge: all same citation = n → H = n
    vector<int> c6 = {4, 4, 4, 4};
    cout << "Test 6: " << sol.hIndex(c6) << " (expected 4)" << endl;

    return 0;
}
