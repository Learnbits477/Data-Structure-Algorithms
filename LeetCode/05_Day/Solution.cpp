#include <vector>
#include <algorithm>
#include <iostream>
#include <climits>

using namespace std;

class Solution {
public:
    int minimumCost(vector<int>& nums) {
        // nums[0] is always part of the cost.
        int cost = nums[0];
        
        // We need to find the two smallest elements from nums[1] to nums[n-1].
        // Since n is small (<= 50), sorting is perfectly fine.
        // We can sort a portion of the array or use a temporary vector.
        
        // Strategy: Iterate and find min1 and min2
        int min1 = INT_MAX;
        int min2 = INT_MAX;
        
        for (size_t i = 1; i < nums.size(); ++i) {
            if (nums[i] < min1) {
                min2 = min1;
                min1 = nums[i];
            } else if (nums[i] < min2) {
                min2 = nums[i];
            }
        }
        
        return cost + min1 + min2;
    }
};

int main() {
    Solution sol;
    
    // Example 1
    vector<int> nums1 = {1, 2, 3, 12};
    cout << "Input: [1, 2, 3, 12]" << endl;
    cout << "Output: " << sol.minimumCost(nums1) << " (Expected: 6)" << endl;
    
    // Example 2
    vector<int> nums2 = {5, 4, 3};
    cout << "Input: [5, 4, 3]" << endl;
    cout << "Output: " << sol.minimumCost(nums2) << " (Expected: 12)" << endl;

    // Example 3
    vector<int> nums3 = {10, 3, 1, 1};
    cout << "Input: [10, 3, 1, 1]" << endl;
    cout << "Output: " << sol.minimumCost(nums3) << " (Expected: 12)" << endl;

    return 0;
}
