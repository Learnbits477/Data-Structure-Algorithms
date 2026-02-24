/*
 * GeeksForGeeks: Union of Arrays with Duplicates
 * Difficulty: Easy
 * Approach: Hash Set (unordered_set)
 *
 * Time  Complexity: O(n + m) average
 * Space Complexity: O(n + m)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findUnion(vector<int>& a, vector<int>& b) {
        unordered_set<int> st;

        for (int x : a) st.insert(x);
        for (int x : b) st.insert(x);

        return vector<int>(st.begin(), st.end());
    }
};

// ──────────────────────────────────────────────
// Test Driver
// ──────────────────────────────────────────────
int main() {
    Solution sol;

    auto printUnion = [](vector<int> res) {
        sort(res.begin(), res.end());
        for (int x : res) cout << x << " ";
        cout << "\n";
    };

    // Test 1 → 1 2 3
    vector<int> a1 = {1, 2, 3, 2, 1}, b1 = {3, 2, 2, 3, 3, 2};
    printUnion(sol.findUnion(a1, b1));

    // Test 2 → 1 2 3 4 5 6
    vector<int> a2 = {1, 2, 3}, b2 = {4, 5, 6};
    printUnion(sol.findUnion(a2, b2));

    // Test 3 → 1 2
    vector<int> a3 = {1, 2, 1, 1, 2}, b3 = {2, 2, 1, 2, 1};
    printUnion(sol.findUnion(a3, b3));

    return 0;
}
