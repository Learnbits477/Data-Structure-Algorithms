#include <iostream>
#include <string>
#include <vector>
#include "Solution.cpp"

using namespace std;

// Test runner function
void runTest(int testId, string word, int expected) {
    cout << "--------------------------------------------------\n";
    cout << "🧪 Test Case " << testId << ":\n";
    cout << "   Input Word: \"" << word << "\"\n";

    Solution solver;
    int actual = solver.numberOfSpecialChars(word);
    
    cout << "   Expected Result: " << expected << "\n";
    cout << "   Actual Result:   " << actual << "\n";
    
    if (actual == expected) {
        cout << "   🟢 Result: ✅ PASSED\n";
    } else {
        cout << "   🔴 Result: ❌ FAILED\n";
    }
}

int main() {
    cout << "\n🔢 [Day 119] Count the Number of Special Characters I — Test Suite 🚀\n";
    
    // Example 1: aaAbcBC
    runTest(1, "aaAbcBC", 3);
    
    // Example 2: abc
    runTest(2, "abc", 0);
    
    // Example 3: abBCab
    runTest(3, "abBCab", 1);
    
    // Example 4: Mixed casing with multiple occurrences
    runTest(4, "dDcCbBaA", 4);
    
    // Example 5: Single character strings
    runTest(5, "z", 0);
    runTest(6, "Z", 0);
    
    // Example 6: Same lowercase and uppercase character only
    runTest(7, "xX", 1);

    cout << "--------------------------------------------------\n";
    cout << "🏁 Test execution completed.\n\n";
    return 0;
}
