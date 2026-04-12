#include <iostream>
#include <vector>
#include "Solution.cpp"

using namespace std;

void test(vector<int> nums, int expected) {
    Solution sol;
    int result = sol.minimumDistance(nums);
    cout << "Input: [";
    for(int i=0; i<nums.size(); ++i) cout << nums[i] << (i == nums.size()-1 ? "" : ",");
    cout << "] | Expected: " << expected << " | Result: " << result;
    if (result == expected) {
        cout << " ✅" << endl;
    } else {
        cout << " ❌" << endl;
    }
}

int main() {
    cout << "--- LeetCode 3741: Minimum Distance Between Three Equal Elements II ---" << endl;
    cout << endl;
    
    // Example 1
    test({1, 2, 1, 1, 3}, 6);
    
    // Example 2
    test({1, 1, 2, 3, 2, 1, 2}, 8);
    
    // Example 3
    test({1}, -1);
    
    // Additional Test 1: No triplets
    test({1, 1, 2, 2, 3, 3}, -1);
    
    // Additional Test 2: Multiple triplets, different values
    test({1, 1, 1, 2, 2, 2}, 4); // Min dist for 1 is 2*(2-0)=4, for 2 is 2*(5-3)=4
    
    return 0;
}
