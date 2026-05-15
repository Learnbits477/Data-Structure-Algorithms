#include <iostream>
#include "Solution.cpp"

using namespace std;

void runTest(int n, long long int expected) {
    Solution sol;
    long long int result = sol.optimalKeys(n);
    
    cout << "Input: n = " << n << "\n";
    cout << "Expected: " << expected << " | Output: " << result << "\n";
    
    if (result == expected) {
        cout << "✅ PASSED\n";
    } else {
        cout << "❌ FAILED\n";
    }
    cout << "----------------------------------------\n";
}

int main() {
    cout << "\n🔢 Special Keyboard — Test Suite\n";
    cout << "========================================\n";

    // Example 1
    runTest(3, 3);

    // Example 2
    runTest(7, 9);
    
    // Additional Test Cases
    runTest(1, 1);
    runTest(6, 6);
    runTest(11, 27);

    return 0;
}
