#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

string vectorToString(const vector<string>& vec) {
    string s = "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        s += "\"" + vec[i] + "\"";
        if (i < vec.size() - 1) s += ", ";
    }
    s += "]";
    return s;
}

void runTest(int testNum, vector<string> arr, vector<string> expected) {
    Solution sol;
    
    // Test with the vector signature
    vector<string> result = sol.findPrefixes(arr);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";
    
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);
    
    string arrStr = vectorToString(arr);
    if (arrStr.length() > 40) {
        arrStr = arrStr.substr(0, 37) + "...";
    }
    
    string expectedStr = vectorToString(expected);
    if (expectedStr.length() > 25) {
        expectedStr = expectedStr.substr(0, 22) + "...";
    }
    
    string actualStr = vectorToString(result);
    if (actualStr.length() > 25) {
        actualStr = actualStr.substr(0, 22) + "...";
    }
    
    cout << left << setw(6)  << testId 
         << setw(42) << arrStr
         << setw(27) << expectedStr
         << setw(27) << actualStr
         << status << "\n";
         
    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Expected: " << vectorToString(expected) << "\n"
             << "     Got:      " << vectorToString(result) << "\n";
    }
}

int main() {
    cout << "\n";
    cout << "  🚀 GeeksforGeeks Day 174 - Shortest Unique Prefix Test Suite  \n";
    cout << "⇚ - ========================================================================================================== - ⇛\n";
    cout << left << setw(6)  << "[ID]" 
         << setw(42) << "Input Array" 
         << setw(27) << "Expected Prefix" 
         << setw(27) << "Actual Prefix" 
         << "Status\n";
    cout << string(110, '-') << "\n";

    // Test Case 1: Example 1 from GFG
    runTest(1, {"zebra", "dog", "duck", "dove"}, {"z", "dog", "du", "dov"});

    // Test Case 2: Example 2 from GFG
    runTest(2, {"geeksgeeks", "geeksquiz", "geeksforgeeks"}, {"geeksg", "geeksq", "geeksf"});

    // Test Case 3: Simple distinct starting characters
    runTest(3, {"apple", "banana", "cherry", "date"}, {"a", "b", "c", "d"});

    // Test Case 4: Long common prefixes
    runTest(4, {"abcdefgh", "abcdefgi", "abcdefgj"}, {"abcdefgh", "abcdefgi", "abcdefgj"});

    // Test Case 5: Standard test case from GFG with short/long mixes
    runTest(5, {"first", "second", "third", "fourth", "fifth"}, {"fir", "s", "t", "fo", "fif"});

    cout << "⇚ - ========================================================================================================== - ⇛\n";
    cout << "                         🎉 All Tests Completed Successfully!                           \n";

    return 0;
}
