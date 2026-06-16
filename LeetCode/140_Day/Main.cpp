#include "Solution.cpp"
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

void runTest(int testNum, string s, string expected) {
    Solution sol;
    string result = sol.processStr(s);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";
    
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);
    
    cout << left << setw(6)  << testId 
         << setw(20) << ("\"" + s + "\"")
         << setw(20) << ("\"" + expected + "\"")
         << setw(20) << ("\"" + result + "\"")
         << status << "\n";
}

int main() {
    cout << endl << "  🧪 LeetCode Day 140 - Process String with Special Operations I Test Suite  \n";
    cout << endl << "==============================================================================\n";
    cout << left << setw(6)  << "[ID]" 
         << setw(20) << "Input String" 
         << setw(20) << "Expected Output" 
         << setw(20) << "Actual Output" 
         << "Status\n";
    cout <<     string(78, '-') << "\n";

    runTest(1, "a#b%*", "ba");
    runTest(2, "z*#", "");
    runTest(3, "abc***", "");
    runTest(4, "%", "");
    runTest(5, "a##", "aaaa");
    runTest(6, "ab%#", "baba");
    runTest(7, "xyz*%#*", "yxy");

    cout << endl << "                      🎉 All Tests Completed Successfully!                     \n";
    cout << endl << "--------------------------------------------------------------------------- \n";

    return 0;
}
