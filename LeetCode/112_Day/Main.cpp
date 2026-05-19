#include <iostream>
#include <vector>
#include "Solution.cpp"

using namespace std;

void runTest(int testNum, vector<int> nums1, vector<int> nums2, int expected) {
    Solution sol;
    cout << "🧪 Test Case " << testNum << ":\n";
    cout << "   nums1 = [";
    for (size_t i = 0; i < nums1.size(); ++i) {
        cout << nums1[i] << (i == nums1.size() - 1 ? "" : ", ");
    }
    cout << "]\n";
    cout << "   nums2 = [";
    for (size_t i = 0; i < nums2.size(); ++i) {
        cout << nums2[i] << (i == nums2.size() - 1 ? "" : ", ");
    }
    cout << "]\n";

    int result = sol.getCommon(nums1, nums2);

    if (result == expected) {
        cout << "   ✅ PASSED (Result: " << result << ")\n";
    } else {
        cout << "   ❌ FAILED\n";
        cout << "      Expected: " << expected << "\n";
        cout << "      Got:      " << result << "\n";
    }
    cout << "-------------------------------------------\n";
}

int main() {
    cout << "\n🔢 [Minimum Common Value] — Test Suite\n";
    cout << "===========================================\n";

    // Example 1
    runTest(1, {1, 2, 3}, {2, 4}, 2);

    // Example 2
    runTest(2, {1, 2, 3, 6}, {2, 3, 4, 5}, 2);

    // Additional Edge Case 3: No common element
    runTest(3, {1, 3, 5}, {2, 4, 6}, -1);

    // Additional Edge Case 4: First element matches
    runTest(4, {1, 2, 3}, {1, 5, 9}, 1);

    // Additional Edge Case 5: Large values and bounds
    runTest(5, {1000000000}, {1000000000}, 1000000000);

    cout << "\n🚀 All tests completed!\n";

    return 0;
}
