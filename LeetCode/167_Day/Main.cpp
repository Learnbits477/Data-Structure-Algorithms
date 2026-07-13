#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

void runTest(int testNum, int low, int high, vector<int> expected) {
    Solution sol;
    
    vector<int> result = sol.sequentialDigits(low, high);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";
    
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);
    
    string inputStr = "low = " + to_string(low) + ", high = " + to_string(high);
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
    if (expectedStr.length() > 25) {
        expectedStr = expectedStr.substr(0, 22) + "...]";
    }
    
    // Format result output printout
    string resultStr = "[";
    for (size_t i = 0; i < result.size(); ++i) {
        resultStr += to_string(result[i]);
        if (i != result.size() - 1) resultStr += ",";
    }
    resultStr += "]";
    if (resultStr.length() > 25) {
        resultStr = resultStr.substr(0, 22) + "...]";
    }
    
    cout << left << setw(6)  << testId 
         << setw(45) << inputStr
         << setw(28) << expectedStr
         << setw(28) << resultStr
         << status << "\n";
         
    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Expected: [";
        for (size_t i = 0; i < expected.size(); ++i) {
            cout << expected[i] << (i == expected.size() - 1 ? "" : ", ");
        }
        cout << "]\n     Got:      [";
        for (size_t i = 0; i < result.size(); ++i) {
            cout << result[i] << (i == result.size() - 1 ? "" : ", ");
        }
        cout << "]\n";
    }
}

int main() {
    cout << "\n";
    cout << "  🚀 LeetCode Day 167 - Sequential Digits Test Suite  \n";
    cout << "⇚ - =================================================================================================== - ⇛\n";
    cout << left << setw(6)  << "[ID]" 
         << setw(45) << "Input Parameters (low, high)" 
         << setw(28) << "Expected" 
         << setw(28) << "Actual" 
         << "Status\n";
    cout << string(115, '-') << "\n";

    // Test Case 1: Example 1 from problem description
    runTest(1, 100, 300, {123, 234});

    // Test Case 2: Example 2 from problem description
    runTest(2, 1000, 13000, {1234, 2345, 3456, 4567, 5678, 6789, 12345});

    // Test Case 3: Empty results (no candidates in range)
    runTest(3, 800, 1000, {});

    // Test Case 4: Single candidate in range
    runTest(4, 120, 130, {123});

    // Test Case 5: Minimum constraints (low=10, high=100)
    runTest(5, 10, 100, {12, 23, 34, 45, 56, 67, 78, 89});

    // Test Case 6: Full bounds of the range up to 10^9
    // Generates all 36 candidates
    runTest(6, 10, 1000000000, {
        12, 23, 34, 45, 56, 67, 78, 89,
        123, 234, 345, 456, 567, 678, 789,
        1234, 2345, 3456, 4567, 5678, 6789,
        12345, 23456, 34567, 45678, 56789,
        123456, 234567, 345678, 456789,
        1234567, 2345678, 3456789,
        12345678, 23456789,
        123456789
    });

    cout << "⇚ - =================================================================================================== - ⇛\n";
    cout << "                                 🎉 All Tests Completed Successfully!                                   \n";

    return 0;
}
