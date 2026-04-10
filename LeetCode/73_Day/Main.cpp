#include <iostream>
#include <vector>
#include "Solution.cpp"

using namespace std;

int main() {
    Solution sol;
    
    // Example 1
    vector<int> nums1 = {1, 1, 2, 1, 1};
    cout << "Example 1 Output: " << sol.minimumDistance(nums1) << " (Expected: 6)" << endl;

    // Example 2
    vector<int> nums2 = {1, 2, 3};
    cout << "Example 2 Output: " << sol.minimumDistance(nums2) << " (Expected: -1)" << endl;

    // Example 3
    vector<int> nums3 = {1, 1, 1};
    cout << "Example 3 Output: " << sol.minimumDistance(nums3) << " (Expected: 4)" << endl;

    return 0;
}
