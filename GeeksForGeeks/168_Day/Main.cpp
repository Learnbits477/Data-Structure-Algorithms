#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <numeric>
using namespace std;

void runTest(int testNum, vector<int> arr, int expected) {
    Solution sol;
    
    vector<int> originalArr = arr;
    
    int result = sol.find(arr);
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
    cout << "  🚀 GeeksforGeeks Day 168 - Smallest Non-Zero Number Test Suite  \n";
    cout << "⇚ - ===================================================================================== - ⇛\n";
    cout << left << setw(6)  << "[ID]" 
         << setw(45) << "Input Parameters (arr[])" 
         << setw(12) << "Expected" 
         << setw(12) << "Actual" 
         << "Status\n";
    cout << string(90, '-') << "\n";

    // Test Case 1: Example 1 from GFG description
    // arr[] = [3, 4, 3, 2, 4] -> Expected: 4
    runTest(1, {3, 4, 3, 2, 4}, 4);

    // Test Case 2: Example 2 from GFG description
    // arr[] = [4, 4] -> Expected: 3
    runTest(2, {4, 4}, 3);

    // Test Case 3: Single element odd
    // arr[] = [3] -> Expected: 2
    runTest(3, {3}, 2);

    // Test Case 4: Single element even
    // arr[] = [10000] -> Expected: 5000
    runTest(4, {10000}, 5000);

    // Test Case 5: Monotonically increasing elements
    // arr[] = [1, 2, 3, 4] -> Expected: 2
    runTest(5, {1, 2, 3, 4}, 2);

    // Test Case 6: Decreasing elements
    // arr[] = [4, 3, 2, 1] -> Expected: 4
    runTest(6, {4, 3, 2, 1}, 4);

    // Test Case 7: All elements are 1
    // arr[] = [1, 1, 1, 1] -> Expected: 1
    runTest(7, {1, 1, 1, 1}, 1);

    cout << "⇚ - ===================================================================================== - ⇛\n";
    cout << "                         🎉 All Tests Completed Successfully!                           \n";

    return 0;
}
