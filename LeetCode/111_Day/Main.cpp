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

void runTest(int testNum, vector<int> arr, int expected) {
    Solution sol;
    cout << "🧪 Test Case " << testNum << ": arr = ";
    printVector(arr);
    cout << "\n";
    
    vector<int> arrCopy = arr; // Copy to prevent mutating printout
    int result = sol.minJumps(arrCopy);
    
    if (result == expected) {
        cout << "   ✅ PASSED (Result: " << result << ")\n";
    } else {
        cout << "   ❌ FAILED (Expected: " << expected << ", Got: " << result << ")\n";
    }
    cout << "-------------------------------------------\n";
}

int main() {
    cout << "\n🔢 [Jump Game IV] — Test Suite\n";
    cout << "===========================================\n";

    // Example 1: Standard input with various duplicates
    runTest(1, {100, -23, -23, 404, 100, 23, 23, 23, 3, 404}, 3);

    // Example 2: Single element array (already at last index)
    runTest(2, {7}, 0);

    // Example 3: Immediate jump to last index via duplicate
    runTest(3, {7, 6, 9, 6, 9, 6, 9, 7}, 1);

    // Example 4: Linear steps (no duplicates)
    runTest(4, {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 9);

    // Example 5: Duplicate jumps with trailing step
    runTest(5, {11, 22, 7, 7, 7, 7, 7, 7, 7, 22, 13}, 3);

    // Example 6: Alternating values
    runTest(6, {1, 2, 1, 2, 1, 2, 1, 2, 1, 2}, 2);

    cout << "\n🚀 All tests completed!\n";
    
    return 0;
}
