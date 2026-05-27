#include <iostream>
#include <string>
#include "Solution.cpp"

using namespace std;

// Test runner function
void runTest(int testId, string s, int x, bool expected) {
    cout << "--------------------------------------------------\n";
    cout << "🧪 Test Case " << testId << ":\n";
    cout << "   Input: s = \"" << s << "\", x = " << x << "\n";

    Solution solver;
    bool actual = solver.wifiRange(s, x);
    
    cout << "   Expected Result: " << (expected ? "true" : "false") << "\n";
    cout << "   Actual Result:   " << (actual ? "true" : "false") << "\n";
    
    if (actual == expected) {
        cout << "   🟢 Result: ✅ PASSED\n";
    } else {
        cout << "   🔴 Result: ❌ FAILED\n";
    }
}

int main() {
    cout << "\n🔢 [Day 120] Wifi Range — Test Suite 🚀\n";
    
    // Example 1: Range is 0, room 0 and 2 are left uncovered
    runTest(1, "010", 0, false);
    
    // Example 2: Normal range, all covered
    runTest(2, "10010", 1, true);
    
    // Example 3: Single router, range not enough for room 0
    runTest(3, "001", 1, false);
    
    // Example 4: Single router, range enough to cover all
    runTest(4, "001", 2, true);
    
    // Example 5: Single router in center covers all
    runTest(5, "010", 1, true);
    
    // Example 6: Multi routers overlapping perfectly
    runTest(6, "10101", 1, true);
    
    // Example 7: Gap in the middle
    runTest(7, "10001", 1, false);
    
    // Example 8: No routers at all
    runTest(8, "00000", 5, false);

    // Example 9: Single room, no router
    runTest(9, "0", 1, false);

    // Example 10: Single room with router
    runTest(10, "1", 0, true);

    cout << "--------------------------------------------------\n";
    cout << "🏁 Test execution completed.\n\n";
    return 0;
}
