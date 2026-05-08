#include <iostream>
#include <vector>
#include <string>
#include "Solution.cpp"

using namespace std;

void printResult(int res) {
    cout << "Result: " << res << endl;
}

void runTest(vector<int> nums, int testNum) {
    Solution sol;
    cout << "Test Case " << testNum << ": nums = [";
    for (size_t i = 0; i < nums.size(); ++i) {
        cout << nums[i] << (i == nums.size() - 1 ? "" : ", ");
    }
    cout << "]" << endl;
    
    int result = sol.minJumps(nums);
    cout << "Output: " << result << endl;
    cout << "------------------------------------------" << endl;
}

int main() {
    cout << "--- Minimum Jumps via Prime Teleportation ---" << endl << endl;

    // Test Case 1: Example 1
    runTest({1, 2, 4, 6}, 1);

    // Test Case 2: Example 2
    runTest({2, 3, 4, 7, 9}, 2);

    // Test Case 3: Example 3 (No teleportation)
    runTest({4, 6, 5, 8}, 3);

    // Test Case 4: Larger case with multiple teleportation options
    runTest({1, 2, 10, 15, 20, 3, 30}, 4);

    return 0;
}
