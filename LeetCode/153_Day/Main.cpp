#include "Solution.cpp"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

string formatPatterns(const vector<string>& patterns) {
    if (patterns.empty()) return "[]";
    if (patterns.size() > 4) {
        return "[" + patterns[0] + "," + patterns[1] + "... (" + to_string(patterns.size()) + " items)]";
    }
    string res = "[";
    for (size_t i = 0; i < patterns.size(); ++i) {
        res += "\"" + patterns[i] + "\"";
        if (i + 1 < patterns.size()) res += ",";
    }
    res += "]";
    return res;
}

void runTest(int testNum, vector<string> patterns, string word, int expected) {
    Solution sol;
    int result = sol.numOfStrings(patterns, word);
    
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";
    
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);
    
    string patternsStr = formatPatterns(patterns);
    
    cout << left << setw(6)  << testId 
         << setw(35) << patternsStr
         << setw(12) << word
         << setw(18) << expected
         << setw(18) << result
         << status << "\n";
}

int main() {
    cout << "\n";
    cout << "  🚀 LeetCode Day 153 - Strings as Substrings in Word Test Suite  \n";
    cout << "⇚ - ============================================================================================= - ⇛\n";
    cout << left << setw(6)  << "[ID]" 
         << setw(35) << "Patterns"
         << setw(12) << "Word" 
         << setw(18) << "Expected Output" 
         << setw(18) << "Actual Output" 
         << "Status\n";
    cout << string(94, '-') << "\n";

    // Example 1
    runTest(1, {"a", "abc", "bc", "d"}, "abc", 3);
    
    // Example 2
    runTest(2, {"a", "b", "c"}, "aaaaabbbbb", 2);
    
    // Example 3
    runTest(3, {"a", "a", "a"}, "ab", 3);
    
    // Additional Test Cases
    runTest(4, {"xyz", "pq"}, "abcdef", 0);
    runTest(5, {"de", "ef", "cde"}, "abcdef", 3);
    runTest(6, {""}, "abc", 1); // empty string is always a substring

    cout << "⇚ - ============================================================================================= - ⇛\n";
    cout << "                           🎉 All Tests Completed Successfully!                           \n";
    cout << "\n";

    return 0;
}
