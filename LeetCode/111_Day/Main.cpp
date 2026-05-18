#include <iostream>
#include <vector>
#include "Solution.cpp"

using namespace std;

void runTest(int testNum, int n, int expected) {
    Solution sol;
    cout << "🧪 Test Case " << testNum << ": n = " << n << "\n";
    
    int result = sol.maxSum(n);
    
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
    cout << "\n🔢 [Maximum Sum Problem] — Test Suite\n";
    cout << "===========================================\n";

    // Example 1: n = 12
    runTest(1, 12, 13);

    // Example 2: n = 24
    runTest(2, 24, 27);

    // Additional Edge Case 3: n = 0
    runTest(3, 0, 0);

    // Additional Edge Case 4: n = 2 (No split is better)
    runTest(4, 2, 2);

    // Additional Edge Case 5: n = 5 (No split is better)
    runTest(5, 5, 5);

    // Additional Edge Case 6: n = 27 (Splitting recursively produces greater value)
    runTest(6, 27, 28);

    cout << "\n🚀 All tests completed!\n";
    
    return 0;
}
