#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isProduct(vector<int>& arr, long long target) {
        // Step 1: Special Case for Target = 0
        if (target == 0) {
            for (int num : arr) {
                if (num == 0) {
                    return true;
                }
            }
            return false;
        }

        // Step 2: Hashing Setup for Target ≠ 0
        unordered_set<long long> seen;

        // Step 3: Iterate and Match
        for (int num : arr) {
            if (num == 0) {
                continue; // 0 can never yield a non-zero product
            }

            if (target % num == 0) {
                long long complement = target / num;
                if (seen.count(complement)) {
                    return true;
                }
            }
            seen.insert(num);
        }

        // Step 4: Fallback
        return false;
    }
};
