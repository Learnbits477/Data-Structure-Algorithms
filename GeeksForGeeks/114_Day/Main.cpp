#include <iostream>
#include <string>
#include "Solution.cpp"

using namespace std;

void runTest(int testId, int n, bool expected) {
    Solution solver;
    bool actual = solver.isBitSet(n);
    
    cout << "--------------------------------------------------\n";
    cout << "🧪 Test Case " << testId << ":\n";
    cout << "   Input n:  " << n << "\n";
    cout << "   Expected: " << (expected ? "true" : "false") << "\n";
    cout << "   Actual:   " << (actual ? "true" : "false") << "\n";
    
    if (actual == expected) {
        cout << "   🟢 Result: ✅ PASSED\n";
    } else {
        cout << "   🔴 Result: ❌ FAILED\n";
    }
}

int main() {
    cout << "\n🔢 [Day 114] Check if All Bits Set — Test Suite 🚀\n";
    
    // Example 1
    runTest(1, 7, true);
    
    // Example 2
    runTest(2, 8, false);
    
    // Example 3
    runTest(3, 0, false);

    // Extra Edge Cases
    runTest(4, 1, true);       // Binary: 1
    runTest(5, 3, true);       // Binary: 11
    runTest(6, 15, true);      // Binary: 1111
    runTest(7, 31, true);      // Binary: 11111
    runTest(8, 1023, true);    // Binary: 1111111111
    runTest(9, 1024, false);   // Binary: 10000000000
    runTest(10, 127, true);    // Binary: 1111111
    runTest(11, 126, false);   // Binary: 1111110
    
    cout << "--------------------------------------------------\n";
    cout << "🏁 Test execution completed.\n\n";
    return 0;
}
