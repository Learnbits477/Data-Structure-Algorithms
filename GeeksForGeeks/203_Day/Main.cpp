#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void runTest(int testNum, const string& s, const string& expected) {
    Solution sol;
    string result = sol.compress(s);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";
    
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);
    
    string displayS = s;
    if (displayS.length() > 17) {
        displayS = displayS.substr(0, 14) + "...";
    }

    string displayRes = result;
    if (displayRes.length() > 17) {
        displayRes = displayRes.substr(0, 14) + "...";
    }

    cout << left << setw(6)  << testId 
         << setw(20) << displayS
         << setw(20) << displayRes
         << status << "\n";
         
    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Expected: " << expected << "\n"
             << "     Got:      " << result << "\n";
    }
}

int main() {
    cout << "\n🔢 Secret Cipher — Test Suite\n";
    cout << "※ ========================================================== ※\n";
    cout << left << setw(6)  << "[ID]" 
         << setw(20) << "Input (s)" 
         << setw(20) << "Result" 
         << "Status\n";
    cout << string(62, '-') << "\n";

    // Test 1: Example 1
    runTest(1, "ababcababcd", "ab*c*d");

    // Test 2: Example 2
    runTest(2, "zzzzzzz", "z*z*z");

    // Test 3: No repeating pattern
    runTest(3, "abcdef", "abcdef");

    // Test 4: Single char
    runTest(4, "a", "a");

    // Test 5: Complex repeating
    runTest(5, "ababab", "ab*ab");

    cout << "※ ========================================================== ※\n";
    cout << "                  🎉 All Tests Executed!             \n\n";

    return 0;
}
