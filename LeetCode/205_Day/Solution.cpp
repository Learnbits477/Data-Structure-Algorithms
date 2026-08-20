#include <vector>

using namespace std;

class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        // Step 1: Initialize arr1 and arr2 with the first two elements
        vector<int> arr1, arr2;
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);

        // Step 2: Distribute remaining elements based on the last element comparison
        for (size_t i = 2; i < nums.size(); ++i) {
            if (arr1.back() > arr2.back()) {
                arr1.push_back(nums[i]);
            } else {
                arr2.push_back(nums[i]);
            }
        }

        // Step 3: Concatenate arr1 and arr2
        arr1.insert(arr1.end(), arr2.begin(), arr2.end());

        // Step 4: Return the concatenated result
        return arr1;
    }
};
