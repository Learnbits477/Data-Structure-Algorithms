#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "Solution.cpp"

using namespace std;

void printVector(const vector<int>& v) {
    cout << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        cout << v[i] << (i == v.size() - 1 ? "" : ", ");
    }
    cout << "]";
}

void runTest(int testNum, vector<int> arr, int start, bool expected) {
    Solution sol;
    cout << "🧪 Test Case " << testNum << ": arr = ";
    printVector(arr);
    cout << ", start = " << start << "\n";
    
    vector<int> arrCopy = arr; // Copy to prevent mutating printout
    bool result = sol.canReach(arrCopy, start);
    
    string resStr = result ? "true" : "false";
    string expStr = expected ? "true" : "false";
    
    if (result == expected) {
        cout << "   ✅ PASSED (Result: " << resStr << ")\n";
    } else {
        cout << "   ❌ FAILED (Expected: " << expStr << ", Got: " << resStr << ")\n";
    }
    cout << "-------------------------------------------\n";
}

int main() {
    cout << "\n🔢 [Jump Game III] — Test Suite\n";
    cout << "===========================================\n";

    // Example 1: arr = [4,2,3,0,3,1,2], start = 5
    runTest(1, {4, 2, 3, 0, 3, 1, 2}, 5, true);

    // Example 2: arr = [4,2,3,0,3,1,2], start = 0
    runTest(2, {4, 2, 3, 0, 3, 1, 2}, 0, true);

    // Example 3: arr = [3,0,2,1,2], start = 2
    runTest(3, {3, 0, 2, 1, 2}, 2, false);

    // Edge Case 4: Already at zero
    runTest(4, {0}, 0, true);

    // Edge Case 5: Single element non-zero (cannot reach zero)
    runTest(5, {2}, 0, false);

    // Edge Case 6: Cyclic jumps without zero
    runTest(6, {1, 1, 1}, 0, false);

    // Edge Case 7: Complex paths with multiple zeroes
    runTest(7, {2, 0, 2, 0, 1}, 2, true);

    cout << "\n🚀 All tests completed!\n";
    
    return 0;
}
