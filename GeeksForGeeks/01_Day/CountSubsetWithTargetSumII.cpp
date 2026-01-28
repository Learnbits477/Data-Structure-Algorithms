#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Helper function to generate all subset sums for a given array segment
    void getSubsetSums(const vector<int>& nums, vector<long long>& sums) {
        int n = nums.size();
        for (int i = 0; i < (1 << n); ++i) {
            long long currentSum = 0;
            for (int j = 0; j < n; ++j) {
                if ((i >> j) & 1) {
                    currentSum += nums[j];
                }
            }
            sums.push_back(currentSum);
        }
    }

    int countSubset(vector<int>& arr, int k) {
        int n = arr.size();
        
        // Meet-in-the-middle: split into two halves
        int mid = n / 2;
        vector<int> leftValidPart(arr.begin(), arr.begin() + mid);
        vector<int> rightValidPart(arr.begin() + mid, arr.end());
        
        vector<long long> leftSums;
        vector<long long> rightSums;
        
        getSubsetSums(leftValidPart, leftSums);
        getSubsetSums(rightValidPart, rightSums);
        
        // Sort rightSums for binary search
        sort(rightSums.begin(), rightSums.end());
        
        long long count = 0;
        
        // Iterate through each sum in leftSums and find complements in rightSums
        for (long long s : leftSums) {
            long long target = k - s;
            
            // Find the range of elements equal to target in rightSums
            auto lower = lower_bound(rightSums.begin(), rightSums.end(), target);
            auto upper = upper_bound(rightSums.begin(), rightSums.end(), target);
            
            count += (upper - lower);
        }
        
        return count;
    }
};

int main() {
    Solution sol;

    // Example 1
    vector<int> arr1 = {1, 3, 2};
    int k1 = 3;
    cout << "Example 1: " << sol.countSubset(arr1, k1) << " (Expected: 2)" << endl;

    // Example 2
    vector<int> arr2 = {4, 2, 3, 1, 2};
    int k2 = 4;
    cout << "Example 2: " << sol.countSubset(arr2, k2) << " (Expected: 3)" << endl;

    // Example 3
    vector<int> arr3 = {10, 20, 30};
    int k3 = 25;
    cout << "Example 3: " << sol.countSubset(arr3, k3) << " (Expected: 0)" << endl;

    return 0;
}
