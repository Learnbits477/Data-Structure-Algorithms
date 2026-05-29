#include "Solution.cpp"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void printSeparator() {
    cout << "  " << string(48, '-') << "\n";
}

void runTest(int testNo, vector<int> nums, int expected) {
    Solution sol;
    int result = sol.minElement(nums);

    cout << "  Test #" << testNo << "\n";
    cout << "    Input    : nums = [";
    for (int i = 0; i < (int)nums.size(); i++) {
        cout << nums[i];
        if (i + 1 < (int)nums.size()) cout << ", ";
    }
    cout << "]\n";
    cout << "    Expected : " << expected << "\n";
    cout << "    Got      : " << result << "\n";

    if (result == expected)
        cout << "    Status   : PASSED\n";
    else
        cout << "    Status   : FAILED\n";

    printSeparator();
}

int main() {
    cout << "\n  3300. Minimum Element After Replacement With Digit Sum\n\n";
    printSeparator();

    runTest(1, {10, 12, 13, 14}, 1);
    runTest(2, {1, 2, 3, 4},    1);
    runTest(3, {999, 19, 199},  10);
    runTest(4, {9999},          36);
    runTest(5, {10000},          1);

    cout << "  All tests completed!\n\n";
    return 0;
}
