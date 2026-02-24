// Longest Span in two Binary Arrays
// Difficulty: Medium | GFG
// Approach: Prefix Difference + Hash Map → O(n) time, O(n) space

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int equalSumSpan(vector<int>& a1, vector<int>& a2) {
        int n = a1.size();
        
        // mp stores first occurrence index of each prefix difference value
        unordered_map<int, int> mp;
        
        int prefixDiff = 0;
        int maxLen = 0;
        
        for (int i = 0; i < n; i++) {
            prefixDiff += (a1[i] - a2[i]);
            
            // Entire subarray [0..i] has equal sums
            if (prefixDiff == 0) {
                maxLen = i + 1;
            }
            // prefixDiff seen before at index j → subarray [j+1..i] has equal sums
            else if (mp.find(prefixDiff) != mp.end()) {
                maxLen = max(maxLen, i - mp[prefixDiff]);
            }
            // First occurrence of this prefixDiff
            else {
                mp[prefixDiff] = i;
            }
        }
        
        return maxLen;
    }
};

// ─── Test Driver ────────────────────────────────────────────────────────────

int main() {
    Solution sol;
    int passed = 0, total = 0;
    
    auto test = [&](vector<int> a1, vector<int> a2, int expected) {
        total++;
        int result = sol.equalSumSpan(a1, a2);
        bool ok = (result == expected);
        if (ok) passed++;
        cout << "Test " << total << ": " << result
             << " (expected: " << expected << ") → "
             << (ok ? "PASS" : "FAIL") << "\n";
    };

    // Test 1: Expected 4
    test({0, 1, 0, 0, 0, 0}, {1, 0, 1, 0, 0, 1}, 4);
    
    // Test 2: Expected 6
    test({0, 1, 0, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 0, 1}, 6);
    
    // Test 3: Expected 0
    test({0, 0, 0}, {1, 1, 1}, 0);
    
    // Test 4: Identical arrays → whole array
    test({1, 0, 1, 1}, {1, 0, 1, 1}, 4);
    
    // Test 5: Single element equal
    test({1}, {1}, 1);
    
    // Test 6: Single element not equal
    test({0}, {1}, 0);

    cout << "\n" << passed << "/" << total << " tests passed.\n";
    return 0;
}
