#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        if (nums[0] >= nums[1]) {
            return false;
        }
        int count = 1;
        for (int i = 2; i < n; i++) {
            if (nums[i - 1] == nums[i]) {
                return false;
            }
            if ((static_cast<long long>(nums[i - 2]) - nums[i - 1]) * (nums[i - 1] - nums[i]) < 0) {
                count++;
            }
        }
        return count == 3;
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {1, 3, 5, 4, 2, 6};
    vector<int> nums2 = {2, 1, 3};
    vector<int> nums3 = {1, 5, 2, 6, 3}; // Edge case: too many turns

    cout << "Test Case 1: " << (sol.isTrionic(nums1) ? "true" : "false") << endl;
    cout << "Test Case 2: " << (sol.isTrionic(nums2) ? "true" : "false") << endl;
    cout << "Test Case 3: " << (sol.isTrionic(nums3) ? "true" : "false") << endl;

    return 0;
}
