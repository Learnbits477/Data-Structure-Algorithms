#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

void runTest(int testNum, string word, int expected) {
    Solution sol;
    int result = sol.minimumPushes(word);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";
    
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);
    
    string previewStr = word;
    if (previewStr.length() > 15) {
        previewStr = previewStr.substr(0, 12) + "...";
    }

    cout << left << setw(6)  << testId 
         << setw(20) << ("\"" + previewStr + "\"")
         << setw(12) << to_string(result)
         << setw(12) << to_string(expected)
         << status << "\n";
         
    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Expected: " << expected << "\n"
             << "     Got:      " << result << "\n";
    }
}

int main() {
    cout << "\n🔢 Minimum Number of Pushes to Type Word I — Test Suite\n";
    cout << "⇚ - ======================================================================= - ⇛\n";
    cout << left << setw(6)  << "[ID]" 
         << setw(20) << "Input Word" 
         << setw(12) << "Result" 
         << setw(12) << "Expected" 
         << "Status\n";
    cout << string(64, '-') << "\n";

    // Example 1: abcde
    runTest(1, "abcde", 5);
    
    // Example 2: xycdefghij
    runTest(2, "xycdefghij", 12);
    
    // Test Case 3: Single character
    runTest(3, "a", 1);
    
    // Test Case 4: Exactly 8 characters (fills first slot of all keys)
    runTest(4, "abcdefgh", 8);
    
    // Test Case 5: 16 characters (fills 1st and 2nd slot of all keys)
    runTest(5, "abcdefghijklmnop", 24);
    
    // Test Case 6: 24 characters (fills 1st, 2nd, and 3rd slot of all keys)
    runTest(6, "abcdefghijklmnopqrstuvwx", 48);

    // Test Case 7: Max length 26 characters
    runTest(7, "abcdefghijklmnopqrstuvwxyz", 56);

    cout << "⇚ - ======================================================================= - ⇛\n";
    cout << "                         🎉 All Tests Executed!                         \n\n";

    return 0;
}
