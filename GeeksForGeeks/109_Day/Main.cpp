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

void runTest(int testNum, vector<int> arr, long long expected) {
    Solution sol;
    cout << "🧪 Test Case " << testNum << ": ";
    printVector(arr);
    cout << "\n";
    
    long long result = sol.findSmallest(arr);
    
    if (result == expected) {
        cout << "   ✅ PASSED (Result: " << result << ")\n";
    } else {
        cout << "   ❌ FAILED (Expected: " << expected << ", Got: " << result << ")\n";
    }
    cout << "-------------------------------------------\n";
}

int main() {
    cout << "\n🔢 [Not a subset sum] — Test Suite\n";
    cout << "===========================================\n";

    // Example 1: arr[] = [3, 1, 2]
    runTest(1, {3, 1, 2}, 7);

    // Example 2: arr[] = [3, 10, 9, 6, 20, 28]
    runTest(2, {3, 10, 9, 6, 20, 28}, 1);

    // Additional Edge Case: Single element 1
    runTest(3, {1}, 2);

    // Additional Edge Case: Single element > 1
    runTest(4, {2}, 1);

    // Additional Edge Case: Sequence starting from 1
    runTest(5, {1, 1, 1, 1}, 5);

    cout << "\n🚀 All tests completed!\n";
    
    return 0;
}
