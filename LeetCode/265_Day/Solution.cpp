#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int lessCount = 0;
        int equalCount = 0;

        // Step: 01 - Count frequencies of elements smaller than and equal to target
        for (int num : nums) {
            if (num < target) {
                lessCount++;
            } else if (num == target) {
                equalCount++;
            }
        }

        // Step: 02 - Construct contiguous target index range
        vector<int> result;
        result.reserve(equalCount);
        for (int i = 0; i < equalCount; i++) {
            result.push_back(lessCount + i);
        }

        // Step: 03 - Return list of target indices
        return result;
    }

    vector<int> targetIndicesSorting(vector<int> nums, int target) {
        // Step: 01 - Sort copy of array in non-decreasing order
        sort(nums.begin(), nums.end());

        // Step: 02 - Filter indices containing matching target value
        vector<int> result;
        for (int i = 0; i < (int)nums.size(); i++) {
            if (nums[i] == target) {
                result.push_back(i);
            } else if (nums[i] > target) {
                break;
            }
        }

        // Step: 03 - Return collected target indices
        return result;
    }

    vector<int> targetIndicesBinarySearch(vector<int> nums, int target) {
        // Step: 01 - Sort copy of array to enable logarithmic searching
        sort(nums.begin(), nums.end());

        // Step: 02 - Locate first and upper boundary iterators
        auto first = lower_bound(nums.begin(), nums.end(), target);
        auto last = upper_bound(nums.begin(), nums.end(), target);

        // Step: 03 - Collect all contiguous matching index positions
        vector<int> result;
        int startIdx = (int)(first - nums.begin());
        int endIdx = (int)(last - nums.begin());

        for (int i = startIdx; i < endIdx; i++) {
            result.push_back(i);
        }

        // Step: 04 - Return binary search verified indices
        return result;
    }
};
