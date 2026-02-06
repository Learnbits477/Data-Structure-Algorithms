#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int ans = n, right = 0;
        for (int left = 0; left < n; ++left) {
            while (right < n &&
                   nums[right] <= static_cast<long long>(nums[left]) * k) {
                ++right;
            }
            ans = min(ans, n - (right - left));
        }

        return ans;
    }
};

int main() {
    Solution sol;
    
    // Example 1
    vector<int> nums1 = {2, 1, 5};
    int k1 = 2;
    cout << "Example 1 Output: " << sol.minRemoval(nums1, k1) << endl; 
    // Expected: 1

    // Example 2
    vector<int> nums2 = {1, 6, 2, 9};
    int k2 = 3;
    cout << "Example 2 Output: " << sol.minRemoval(nums2, k2) << endl; 
    // Expected: 2

    // Example 3
    vector<int> nums3 = {4, 6};
    int k3 = 2;
    cout << "Example 3 Output: " << sol.minRemoval(nums3, k3) << endl; 
    // Expected: 0

    return 0;
}
