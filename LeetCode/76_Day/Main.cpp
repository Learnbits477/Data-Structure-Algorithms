#include <iostream>
#include <vector>
#include "Solution.cpp"

using namespace std;

int main() {
    Solution solution;

    // Example 1
    vector<int> nums1 = {1, 2, 3, 4, 5};
    int target1 = 5;
    int start1 = 3;
    cout << "Example 1 Output: " << solution.getMinDistance(nums1, target1, start1) << " (Expected: 1)" << endl;

    // Example 2
    vector<int> nums2 = {1};
    int target2 = 1;
    int start2 = 0;
    cout << "Example 2 Output: " << solution.getMinDistance(nums2, target2, start2) << " (Expected: 0)" << endl;

    // Example 3
    vector<int> nums3 = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    int target3 = 1;
    int start3 = 0;
    cout << "Example 3 Output: " << solution.getMinDistance(nums3, target3, start3) << " (Expected: 0)" << endl;

    return 0;
}
