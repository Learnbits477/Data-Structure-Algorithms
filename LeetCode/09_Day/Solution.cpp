#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            
            // Calculate the new index with wrap-around handling for negative value
            int target_index = ((i + nums[i]) % n + n) % n;
            res[i] = nums[target_index];
        }
        return res;
    }
};

int main() {
    Solution sol;

    // Example 1
    vector<int> nums1 = {3, -2, 1, 1};
    vector<int> res1 = sol.constructTransformedArray(nums1);
    cout << "Input: [3, -2, 1, 1]" << endl;
    cout << "Output: [";
    for (int i = 0; i < res1.size(); i++) {
        cout << res1[i] << (i < res1.size() - 1 ? ", " : "");
    }
    cout << "]" << endl;
    // Expected: [1, 1, 1, 3]

    // Example 2
    vector<int> nums2 = {-1, 4, -1};
    vector<int> res2 = sol.constructTransformedArray(nums2);
    cout << "Input: [-1, 4, -1]" << endl;
    cout << "Output: [";
    for (int i = 0; i < res2.size(); i++) {
        cout << res2[i] << (i < res2.size() - 1 ? ", " : "");
    }
    cout << "]" << endl;
    // Expected: [-1, -1, 4]

    return 0;
}
