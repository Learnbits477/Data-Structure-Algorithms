#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int max_len = 0;
        
        // Using a visited array to track distinct elements for each starting position.
        // Initialize with -1. Size 100005 to cover nums[i] <= 10^5.
        // Making it static or global would clear it, but here local is fine or member variable.
        // Since we need to reset for each starting position i, we can use the technique:
        // visited[v] = i means value 'v' has been seen in the current loop of 'i'.
        vector<int> visited(100005, -1);

        for (int i = 0; i < n; ++i) {
            int odd_count = 0;
            int even_count = 0;
            
            for (int j = i; j < n; ++j) {
                int val = nums[j];
                
                // If we haven't seen this value in the current subarray starting at i
                if (visited[val] != i) {
                    visited[val] = i; 
                    if (val % 2 != 0) {
                        odd_count++;
                    } else {
                        even_count++;
                    }
                }
                
                if (odd_count == even_count) {
                    max_len = max(max_len, j - i + 1);
                }
            }
        }
        
        return max_len;
    }
};

int main() {
    Solution sol;
    
    // Example 1
    vector<int> nums1 = {2, 5, 4, 3};
    cout << "Example 1: " << sol.longestBalanced(nums1) << " Expected: 4" << endl;
    
    // Example 2
    vector<int> nums2 = {3, 2, 2, 5, 4};
    cout << "Example 2: " << sol.longestBalanced(nums2) << " Expected: 5" << endl;
    
    // Example 3
    vector<int> nums3 = {1, 2, 3, 2};
    cout << "Example 3: " << sol.longestBalanced(nums3) << " Expected: 3" << endl;

    return 0;
}
