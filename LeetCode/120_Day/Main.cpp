#include <iostream>
#include <string>
#include "Solution.cpp"

using namespace std;

// Test runner function
void runTest(int testId, string word, int expected) {
    cout << "--------------------------------------------------\n";
    cout << "🧪 Test Case " << testId << ":\n";
    cout << "   Input: word = \"" << word << "\"\n";

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
    cout << "\n🔢 [Day 120] Count the Number of Special Characters II — Test Suite 🚀\n";
    
    // Example 1: 'a', 'b', and 'c' are special
    runTest(1, "aaAbcBC", 3);
    
    // Example 2: No uppercase occurrences at all
    runTest(2, "abc", 0);
    
    // Example 3: Lowercase occurrence appears after uppercase occurrence
    runTest(3, "AbBCab", 0);
    
    // Example 4: Mixed case where 'b' (1 < 7) and 'e' (4 < 5) are special
    runTest(4, "abCDeEdB", 2);
    
    // Example 5: Case where first_upper is set once and last_lower is before it
    runTest(5, "aA", 1);
    
    // Example 6: Two characters, both are special
    runTest(6, "xXyY", 2);
    
    // Example 7: Duplicate upper before lower
    runTest(7, "BAb", 0);
    
    // Example 8: Uppercase 'C' at index 0 occurs before lowercase 'c' at indices 1, 2, 3
    runTest(8, "cCccCC", 0);

    cout << "--------------------------------------------------\n";
    cout << "🏁 Test execution completed.\n\n";
    return 0;
}
