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
    cout << "\n🔢 Minimum Number of Pushes to Type Word II — Test Suite\n";
    cout << "⇚ - ======================================================================= - ⇛\n";
    cout << left << setw(6)  << "[ID]" 
         << setw(20) << "Input Word" 
         << setw(12) << "Result" 
         << setw(12) << "Expected" 
         << "Status\n";
    cout << string(64, '-') << "\n";

    // Example 1: "abcde"
    runTest(1, "abcde", 5);
    
    // Example 2: "xyzxyzxyzxyz"
    runTest(2, "xyzxyzxyzxyz", 12);
    
    // Example 3: "aabbccddeeffgghhiiiiii"
    runTest(3, "aabbccddeeffgghhiiiiii", 24);
    
    // Test Case 4: Single character
    runTest(4, "q", 1);
    
    // Test Case 5: 26 letters with frequency = 1 each
    runTest(5, "abcdefghijklmnopqrstuvwxyz", 56);
    
    // Test Case 6: 8 distinct characters repeating (fills only 1st slots)
    runTest(6, "aaaabbbbccccddddeeeeffffgggghhhh", 32);

    // Test Case 7: All same character
    runTest(7, "aaaaaaaaaa", 10);

    cout << "⇚ - ======================================================================= - ⇛\n";
    cout << "                         🎉 All Tests Executed!                         \n\n";

    return 0;
}
