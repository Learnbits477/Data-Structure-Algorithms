#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

string vectorToString(const vector<int>& nums) {
    stringstream ss;
    ss << "[";
    for (size_t i = 0; i < nums.size(); ++i) {
        ss << nums[i];
        if (i + 1 < nums.size()) ss << ", ";
    }
    ss << "]";
    return ss.str();
}

void runTest(int testNum, vector<int> nums1, bool expected) {
    Solution sol;
    bool result = sol.uniformArray(nums1);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";

    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);

    cout << left << setw(6)  << testId
         << setw(26) << vectorToString(nums1)
         << setw(12) << (result ? "true" : "false")
         << setw(12) << (expected ? "true" : "false")
         << status << "\n";

    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     nums1=" << vectorToString(nums1) << "\n"
             << "     Expected: " << (expected ? "true" : "false") << "\n"
             << "     Got:      " << (result ? "true" : "false") << "\n";
    }
}

int main() {
    cout << "\n🔢 3875. Construct Uniform Parity Array I — Test Suite\n";
    cout << "※ ========================================================================= ※\n";
    cout << left << setw(6)  << "[ID]"
         << setw(26) << "nums1"
         << setw(12) << "Result"
         << setw(12) << "Expected"
         << "Status\n";
    cout << string(70, '-') << "\n";

    // Test 1: Example 1 from problem description (mixed parity [2, 3])
    runTest(1, {2, 3}, true);

    // Test 2: Example 2 from problem description (all even [4, 6])
    runTest(2, {4, 6}, true);

    // Test 3: All odd numbers
    runTest(3, {1, 5, 9}, true);

    // Test 4: Single element array
    runTest(4, {7}, true);

    // Test 5: Single even element
    runTest(5, {8}, true);

    // Test 6: Larger mixed parity array
    runTest(6, {1, 2, 3, 4, 5, 6}, true);

    // Test 7: Multiple evens, one odd
    runTest(7, {10, 20, 30, 7}, true);

    // Test 8: Multiple odds, one even
    runTest(8, {3, 5, 7, 10}, true);

    cout << "※ ========================================================================= ※\n";
    cout << "                             🎉 All Tests Executed!                               \n\n";

    return 0;
}
