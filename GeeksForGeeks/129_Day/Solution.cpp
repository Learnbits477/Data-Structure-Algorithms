#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string lexicographicallySmallest(string s, int k) {
        int n = s.length();
        
        // Step 1: Length Check & k Adjustment
        bool isPowerOfTwo = (n > 0) && ((n & (n - 1)) == 0);
        if (isPowerOfTwo) {
            k /= 2;
        } else {
            k *= 2;
        }
        
        // Step 2: Feasibility Check
        if (k >= n) {
            return "-1";
        }
        
        // Step 3: Monotonic Stack Construction
        string result = "";
        for (char c : s) {
            while (k > 0 && !result.empty() && result.back() > c) {
                result.pop_back();
                k--;
            }
            result.push_back(c);
        }
        
        // Step 4: Remove Remaining Characters
        while (k > 0 && !result.empty()) {
            result.pop_back();
            k--;
        }
        
        // Step 5: Final Checks
        if (result.empty()) {
            return "-1";
        }
        
        return result;
    }
};
