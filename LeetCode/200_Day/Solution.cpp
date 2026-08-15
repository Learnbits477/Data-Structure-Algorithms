#include <vector>

using namespace std;

class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        // Step 1: Compute total XOR and check for any non-zero element
        int total_xor = 0;
        bool has_nonzero = false;

        for (int num : nums) {
            total_xor ^= num;
            if (num > 0) {
                has_nonzero = true;
            }
        }

        // Step 2: Handle all-zero array edge case
        if (!has_nonzero) {
            return 0;
        }

        // Step 3: Check if total XOR is already non-zero
        if (total_xor != 0) {
            return nums.size();
        }

        // Step 4: If total XOR is zero, removing 1 non-zero element gives non-zero XOR of length N - 1
        return nums.size() - 1;
    }
};
