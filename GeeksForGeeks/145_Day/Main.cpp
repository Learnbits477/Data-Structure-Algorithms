#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

void runTest(int testNum, string s, string expected) {
    Solution sol;
    string inputCopy = s;
    string result = sol.chooseSwap(inputCopy);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";
    
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);
    
    string displayInput = s;
    if (displayInput.length() > 20) {
        displayInput = displayInput.substr(0, 17) + "...";
    }
    string displayExpected = expected;
    if (displayExpected.length() > 20) {
        displayExpected = displayExpected.substr(0, 17) + "...";
    }
    string displayResult = result;
    if (displayResult.length() > 20) {
        displayResult = displayResult.substr(0, 17) + "...";
    }
    
    cout << left << setw(6)  << testId 
         << setw(24) << displayInput
         << setw(24) << displayExpected
         << setw(24) << displayResult
         << status << "\n";
         
    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Input:    " << s << "\n"
             << "     Expected: " << expected << "\n"
             << "     Got:      " << result << "\n";
    }
}

int main() {
    cout << "\n";
    cout << "  🚀 GeeksforGeeks Day 145 - Choose and Swap Test Suite  \n";
    cout << "⇚======================================================================================⇛\n";
    cout << left << setw(6)  << "[ID]" 
         << setw(24) << "Input String (s)" 
         << setw(24) << "Expected Output" 
         << setw(24) << "Actual Output" 
         << "Status\n";
    cout << string(88, '-') << "\n";

    // Example 1
    runTest(1, "ccad", "aacd");
    
    // Example 2
    runTest(2, "abba", "abba");
    
    // Test Case 3: Already sorted string
    runTest(3, "abcdef", "abcdef");
    
    // Test Case 4: Completely reversed string
    runTest(4, "fedcba", "aedcbf"); // Swap 'f' and 'a'
    
    // Test Case 5: Repeating characters where swap is beneficial
    runTest(5, "ba", "ab");
    
    // Test Case 6: Single character string
    runTest(6, "z", "z");
    
    // Test Case 7: Complex duplicate occurrences
    runTest(7, "daba", "adbd"); // 'd' and 'a' swapped

    cout << "⇚======================================================================================⇛\n";
    cout << "                         🎉 All Tests Completed Successfully!                           \n";

    return 0;
}
