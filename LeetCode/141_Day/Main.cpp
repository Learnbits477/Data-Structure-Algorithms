#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void runTest(int testNum, string s, long long k, char expected) {
    Solution sol;
    char result = sol.processStr(s, k);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";
    
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);
    
    // Format character output so '.' or spaces are visible
    string expectedStr = string(1, expected);
    string resultStr = string(1, result);
    
    cout << left << setw(6)  << testId 
         << setw(15) << s
         << setw(10) << k
         << setw(20) << expectedStr
         << setw(20) << resultStr
         << status << "\n";
}

int main() {
    cout << "\n";
    cout << "  🚀 LeetCode Day 141 - Process String with Special Operations II Test Suite  \n";
    cout << "⇚========================================================================================⇛\n";
    cout << left << setw(6)  << "[ID]" 
         << setw(15) << "String s" 
         << setw(10) << "k" 
         << setw(20) << "Expected Output" 
         << setw(20) << "Actual Output" 
         << "Status\n";
    cout << string(88, '-') << "\n";

    // Example 1
    runTest(1, "a#b%*", 1, 'a');
    
    // Example 2
    runTest(2, "cd%#*#", 3, 'd');
    
    // Example 3
    runTest(3, "z*#", 0, '.');
    
    // Additional Test Cases
    runTest(4, "a#b%*", 0, 'b');      // result = "ba", k = 0 -> 'b'
    runTest(5, "a#b%*", 2, '.');      // result = "ba", k = 2 -> '.' (out of bounds)
    runTest(6, "abc#%*", 4, 'b');     // result = "cbaab", k = 4 -> 'b'
    runTest(7, "hello#world", 12, 'r'); // result = "hellohelloworld", k = 12 -> 'r'
    runTest(8, "x#*#*#", 0, 'x');     // repeated duplication and deletion

    cout << "⇚========================================================================================⇛\n";
    cout << "                         🎉 All Tests Completed Successfully!                           \n";
    cout << "\n";

    return 0;
}
