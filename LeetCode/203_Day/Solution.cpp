#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> freq;
        
        // Step 1: Count Frequencies
        for (int num : nums) {
            freq[num]++;
        }
        
        // Step 2: Handle Case k == n
        if (k == n) {
            int max_val = -1;
            for (int num : nums) {
                max_val = max(max_val, num);
            }
            return max_val;
        }
        
        // Step 3: Handle Case k == 1
        if (k == 1) {
            int max_val = -1;
            for (auto& pair : freq) {
                if (pair.second == 1) {
                    max_val = max(max_val, pair.first);
                }
            }
            return max_val;
        }
        
        // Step 4: Handle Case 1 < k < n
        int ans = -1;
        if (freq[nums[0]] == 1) {
            ans = max(ans, nums[0]);
        }
        if (freq[nums[n - 1]] == 1) {
            ans = max(ans, nums[n - 1]);
        }
        
        return ans;
    }
};
