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

void runTest(int testNum, string text, int expected) {
    Solution sol;
    int result = sol.maxNumberOfBalloons(text);
    
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";
    
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);
    
    string textStr = formatText(text);
    
    cout << left << setw(6)  << testId 
         << setw(25) << textStr
         << setw(18) << expected
         << setw(18) << result
         << status << "\n";
}

int main() {
    cout << "\n";
    cout << "  🚀 LeetCode Day 146 - Maximum Number of Balloons Test Suite  \n";
    cout << "⇚===========================================================================⇛\n";
    cout << left << setw(6)  << "[ID]" 
         << setw(25) << "Input Text"
         << setw(18) << "Expected Output" 
         << setw(18) << "Actual Output" 
         << "Status\n";
    cout << string(76, '-') << "\n";

    // Example 1
    runTest(1, "nlaebolko", 1);
    
    // Example 2
    runTest(2, "loonbalxballpoon", 2);
    
    // Example 3
    runTest(3, "leetcode", 0);
    
    // Additional Test Cases
    runTest(4, "balloon", 1);
    runTest(5, "bbaalllooonn", 1); // limiting factor is b (2), a (2), l (3 -> 1.5 -> 1), o (3 -> 1.5 -> 1), n (2)
    runTest(6, "ballon", 0);       // missing one 'l' and one 'o'
    runTest(7, "llooooon", 0);   // missing 'b' and 'a'

    cout << "⇚===========================================================================⇛\n";
    cout << "                           🎉 All Tests Completed Successfully!                           \n";
    cout << "\n";

    return 0;
}
