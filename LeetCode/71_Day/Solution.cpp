#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        const int MOD = 1e9 + 7;

        for (const auto& query : queries) {
            int li = query[0];
            int ri = query[1];
            int ki = query[2];
            int vi = query[3];

            // Perform multiplication for each required index
            for (int idx = li; idx <= ri; idx += ki) {
                // Use long long to avoid overflow during multiplication
                nums[idx] = (1LL * nums[idx] * vi) % MOD;
            }
        }

        // Calculate the final XOR of all elements
        int result = 0;
        for (int num : nums) {
            result ^= num;
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
