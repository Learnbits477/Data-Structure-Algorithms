#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

void runTest(int testNum, vector<int> arr, vector<int> expected) {
    Solution sol;
    
    vector<int> originalArr = arr;
    vector<int> result = sol.arrayRankTransform(arr);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";
    
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);
    
    string arrStr = "[";
    for (size_t i = 0; i < originalArr.size(); ++i) {
        arrStr += to_string(originalArr[i]);
        if (i != originalArr.size() - 1) arrStr += ", ";
    }
    arrStr += "]";
    
    string inputStr = "arr = " + arrStr;
    if (inputStr.length() > 45) {
        inputStr = inputStr.substr(0, 42) + "...";
    }
    
    // Format expected output printout
    string expectedStr = "[";
    for (size_t i = 0; i < expected.size(); ++i) {
        expectedStr += to_string(expected[i]);
        if (i != expected.size() - 1) expectedStr += ",";
    }
    expectedStr += "]";
    
    // Format result output printout
    string resultStr = "[";
    for (size_t i = 0; i < result.size(); ++i) {
        resultStr += to_string(result[i]);
        if (i != result.size() - 1) resultStr += ",";
    }
    resultStr += "]";
    
    cout << left << setw(6)  << testId 
         << setw(45) << inputStr
         << setw(15) << expectedStr
         << setw(15) << resultStr
         << status << "\n";
         
    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Expected: " << expectedStr << "\n"
             << "     Got:      " << resultStr << "\n";
    }
}

int main() {
    cout << "\n";
    cout << "  🚀 LeetCode Day 166 - Rank Transform of an Array Test Suite  \n";
    cout << "⇚ - ===================================================================================== - ⇛\n";
    cout << left << setw(6)  << "[ID]" 
         << setw(45) << "Input Parameters (arr)" 
         << setw(15) << "Expected" 
         << setw(15) << "Actual" 
         << "Status\n";
    cout << string(95, '-') << "\n";

    // Test Case 1: Example 1 from problem description
    runTest(1, {40, 10, 20, 30}, {4, 1, 2, 3});

    // Test Case 2: Example 2 from problem description
    runTest(2, {100, 100, 100}, {1, 1, 1});

    // Test Case 3: Example 3 from problem description
    runTest(3, {37, 12, 28, 9, 100, 56, 80, 5, 12}, {5, 3, 4, 2, 8, 6, 7, 1, 3});

    // Test Case 4: Empty array edge case
    runTest(4, {}, {});

    // Test Case 5: Single element edge case
    runTest(5, {5}, {1});

    // Test Case 6: Negative numbers and duplicates
    runTest(6, {-5, -10, -5, 10, 20}, {2, 1, 2, 3, 4});

    cout << "⇚ - ===================================================================================== - ⇛\n";
    cout << "                         🎉 All Tests Completed Successfully!                           \n";

    return 0;
}
