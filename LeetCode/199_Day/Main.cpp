#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

void runTest(int testNum, string s, int expected) {
    Solution sol;
    int result = sol.maximumLengthSubstring(s);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";
    
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);
    
    cout << left << setw(6)  << testId 
         << setw(16) << s
         << setw(12) << to_string(expected)
         << setw(12) << to_string(result)
         << status << "\n";
         
    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Expected: " << expected << "\n"
             << "     Got:      " << result << "\n";
    }
}

int main() {
    cout << "\n🔢 Maximum Length Substring With Two Occurrences — Test Suite\n";
    cout << "⇐ - ====================================================== - ⇒\n";
    cout << left << setw(6)  << "[ID]" 
         << setw(16) << "String" 
         << setw(12) << "Expected" 
         << setw(12) << "Got" 
         << "Status\n";
    cout << string(56, '-') << "\n";

    // Test 1: Example 1
    runTest(1, "bcbbbcba", 4);

    // Test 2: Example 2
    runTest(2, "aaaa", 2);

    // Test 3: All unique characters
    runTest(3, "abcdef", 6);

    // Test 4: Two of each character
    runTest(4, "aabbcc", 6);

    // Test 5: Alternating character pattern
    runTest(5, "abababab", 4);

    // Test 6: Short string
    runTest(6, "ab", 2);

    cout << "⇐ - ====================================================== - ⇒\n";
    cout << "          🎉 All Tests Executed!             \n\n";

    return 0;
}
