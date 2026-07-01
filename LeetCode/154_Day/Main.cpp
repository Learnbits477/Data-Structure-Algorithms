#include "Solution.cpp"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

string formatText(const string& text) {
    if (text.length() > 20) {
        return text.substr(0, 17) + "...";
    }
    return text;
}

void runTest(int testNum, string s, int expected) {
    Solution sol;
    int result = sol.numberOfSubstrings(s);
    
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";
    
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);
    
    string sStr = formatText(s);
    
    cout << left << setw(6)  << testId 
         << setw(25) << sStr
         << setw(18) << expected
         << setw(18) << result
         << status << "\n";
}

int main() {
    cout << "\n";
    cout << "  🚀 LeetCode Day 154 - Substrings Containing All Three Characters Test Suite  \n";
    cout << "⇚ - ======================================================================= - ⇛\n";
    cout << left << setw(6)  << "[ID]" 
         << setw(25) << "Input String"
         << setw(18) << "Expected Output" 
         << setw(18) << "Actual Output" 
         << "Status\n";
    cout << string(76, '-') << "\n";

    // Example 1
    runTest(1, "abcabc", 10);
    
    // Example 2
    runTest(2, "aaacb", 3);
    
    // Example 3
    runTest(3, "abc", 1);
    
    // Additional Test Cases
    runTest(4, "abccba", 7); // abc, abcc, abccb, abccba, bccba, ccba, cba
    runTest(5, "aaaa", 0);
    runTest(6, "aabbcc", 4);

    cout << "⇚ - ======================================================================= - ⇛\n";
    cout << "                           🎉 All Tests Completed Successfully!                           \n";
    cout << "\n";

    return 0;
}
