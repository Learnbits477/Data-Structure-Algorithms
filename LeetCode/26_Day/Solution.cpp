/*
 * LeetCode 1461. Check If a String Contains All Binary Codes of Size K
 * Difficulty: Medium
 * Approach: Sliding Window + Hash Set
 *
 * Time  Complexity: O(n * k)
 * Space Complexity: O(2^k * k)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.size();
        // Need at least 2^k distinct substrings; impossible if string is too short
        if (n < k) return false;

        unordered_set<string> seen;
        int need = 1 << k; // 2^k

        for (int i = 0; i <= n - k; i++) {
            seen.insert(s.substr(i, k));
            // Early exit: found all codes
            if ((int)seen.size() == need) return true;
        }

        return (int)seen.size() == need;
    }
};

// ──────────────────────────────────────────────
// Test Driver
// ──────────────────────────────────────────────
int main() {
    Solution sol;

    // Test 1 → true
    cout << boolalpha << sol.hasAllCodes("00110110", 2) << "\n"; // true

    // Test 2 → true
    cout << sol.hasAllCodes("0110", 1) << "\n"; // true

    // Test 3 → false
    cout << sol.hasAllCodes("0110", 2) << "\n"; // false

    // Edge: k = 1, s = "0"  → false (missing "1")
    cout << sol.hasAllCodes("0", 1) << "\n"; // false

    // Edge: k = 1, s = "01" → true
    cout << sol.hasAllCodes("01", 1) << "\n"; // true

    return 0;
}
