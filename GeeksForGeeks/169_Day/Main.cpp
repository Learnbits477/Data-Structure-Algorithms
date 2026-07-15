#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

void runTest(int testNum, vector<int> arr, int expected) {
    Solution sol;
    
    vector<int> originalArr = arr;
    
    int result = sol.bitonic(arr);
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
    
    cout << left << setw(6)  << testId 
         << setw(45) << inputStr
         << setw(12) << expected
         << setw(12) << result
         << status << "\n";
         
    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Expected: " << expected << "\n"
             << "     Got:      " << result << "\n";
    }
}

int main() {
    cout << "\n";
    cout << "  🚀 GeeksforGeeks Day 169 - Longest Bitonic Subarray Test Suite  \n";
    cout << "⇚ - ===================================================================================== - ⇛\n";
    cout << left << setw(6)  << "[ID]" 
         << setw(45) << "Input Parameters (arr[])" 
         << setw(12) << "Expected" 
         << setw(12) << "Actual" 
         << "Status\n";
    cout << string(90, '-') << "\n";

    // Test Case 1: Example 1 from GFG description
    // arr[] = [12, 4, 78, 90, 45, 23] -> Expected: 5
    runTest(1, {12, 4, 78, 90, 45, 23}, 5);

    // Test Case 2: Example 2 from GFG description
    // arr[] = [10, 20, 30, 40] -> Expected: 4
    runTest(2, {10, 20, 30, 40}, 4);

    // Test Case 3: Example 3 from GFG description
    // arr[] = [10, 10, 10, 10] -> Expected: 4
    runTest(3, {10, 10, 10, 10}, 4);

    // Test Case 4: Strictly decreasing sequence
    // arr[] = [40, 30, 20, 10] -> Expected: 4
    runTest(4, {40, 30, 20, 10}, 4);

    // Test Case 5: Single element sequence
    // arr[] = [5] -> Expected: 1
    runTest(5, {5}, 1);

    // Test Case 6: Duplicate inheritance on transition back to increasing
    // arr[] = [30, 20, 20, 20, 30, 20] -> Expected: 5 (subarray: [20, 20, 20, 30, 20])
    runTest(6, {30, 20, 20, 20, 30, 20}, 5);

    // Test Case 7: Peak and duplicate valley tracing
    // arr[] = [10, 20, 30, 20, 20, 20, 30, 20] -> Expected: 6 (subarray: [10, 20, 30, 20, 20, 20])
    runTest(7, {10, 20, 30, 20, 20, 20, 30, 20}, 6);

    // Test Case 8: Alternating peaks and valleys
    // arr[] = [10, 5, 20, 15, 30] -> Expected: 3 (subarray: [10, 5] or [5, 20, 15] or [15, 30])
    runTest(8, {10, 5, 20, 15, 30}, 3);

    cout << "⇚ - ===================================================================================== - ⇛\n";
    cout << "                         🎉 All Tests Completed Successfully!                           \n";

    return 0;
}
