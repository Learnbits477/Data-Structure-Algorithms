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

void runTest(int testNum, vector<int> arr, vector<int> expected) {
    Solution sol;
    cout << "🧪 Test Case " << testNum << ": ";
    printVector(arr);
    cout << "\n";
    
    vector<int> result = sol.makeBeautiful(arr);
    
    if (result == expected) {
        cout << "   ✅ PASSED (Result: ";
        printVector(result);
        cout << ")\n";
    } else {
        cout << "   ❌ FAILED\n";
        cout << "      Expected: ";
        printVector(expected);
        cout << "\n      Got:      ";
        printVector(result);
        cout << "\n";
    }
    cout << "-------------------------------------------\n";
}

int main() {
    cout << "\n🔢 [Make the array beautiful] — Test Suite\n";
    cout << "===========================================\n";

    // Example 1: arr[] = [4, 2, -2, 1]
    runTest(1, {4, 2, -2, 1}, {4, 1});

    // Example 2: arr[] = [2, -2, -1, 1]
    runTest(2, {2, -2, -1, 1}, {});

    // Additional Edge Case 3: Empty Array
    runTest(3, {}, {});

    // Additional Edge Case 4: All Positive Elements
    runTest(4, {1, 2, 3, 4}, {1, 2, 3, 4});

    // Additional Edge Case 5: All Negative Elements
    runTest(5, {-1, -2, -3, -4}, {-1, -2, -3, -4});

    // Additional Edge Case 6: Alternating signs that completely cancel
    runTest(6, {1, -1, 2, -2, 3, -3}, {});

    // Additional Edge Case 7: Alternating signs involving zero (treated as non-negative)
    runTest(7, {0, -1, 0, -2}, {});

    cout << "\n🚀 All tests completed!\n";
    
    return 0;
}
