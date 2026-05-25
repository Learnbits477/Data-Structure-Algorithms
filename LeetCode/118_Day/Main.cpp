#include <iostream>
#include <string>
#include <vector>
#include "Solution.cpp"

using namespace std;

// Test runner function
void runTest(int testId, string s, int minJump, int maxJump, bool expected) {
    cout << "--------------------------------------------------\n";
    cout << "🧪 Test Case " << testId << ":\n";
    cout << "   String:   \"" << s << "\"\n";
    cout << "   minJump:  " << minJump << ", maxJump: " << maxJump << "\n";

    Solution solver;
    bool actual = solver.canReach(s, minJump, maxJump);
    
    cout << "   Expected Result: " << (expected ? "true" : "false") << "\n";
    cout << "   Actual Result:   " << (actual ? "true" : "false") << "\n";
    
    if (actual == expected) {
        cout << "   🟢 Result: ✅ PASSED\n";
    } else {
        cout << "   🔴 Result: ❌ FAILED\n";
    }
}

int main() {
    cout << "\n🔢 [Day 118] Jump Game VII — Test Suite 🚀\n";
    
    // Example 1: Standard reachable case
    runTest(1, "011010", 2, 3, true);
    
    // Example 2: Standard unreachable case
    runTest(2, "01101110", 2, 3, false);
    
    // Example 3: Immediate reachability
    runTest(3, "00", 1, 1, true);
    
    // Example 4: Destination blocked by 1
    runTest(4, "011011", 2, 3, false);

    // Example 5: Unreachable due to long chain of 1s at beginning
    runTest(5, "01111100010", 3, 5, false);

    // Example 6: Large jumps exceeding bounds
    runTest(6, "0110", 3, 3, true);

    // Example 7: Long string with valid jumps
    runTest(7, "01100010", 3, 5, true);

    cout << "--------------------------------------------------\n";
    cout << "🏁 Test execution completed.\n\n";
    return 0;
}
