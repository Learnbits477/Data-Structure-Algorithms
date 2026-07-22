#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

void runTest(int testNum, const vector<int>& arr, int expected) {
    Solution sol;
    vector<int> arrCopy = arr; // pass a copy just in case the solution modifies the vector
    int result = sol.minDeletions(arrCopy);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";
    
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);
    
    // Format array output
    string arrStr = "[";
    for (size_t i = 0; i < arr.size(); ++i) {
        arrStr += to_string(arr[i]);
        if (i + 1 < arr.size()) arrStr += ", ";
    }
    arrStr += "]";
    if (arrStr.length() > 30) {
        arrStr = arrStr.substr(0, 27) + "...]";
    }
    
    cout << left << setw(6)  << testId 
         << setw(32) << arrStr
         << setw(18) << expected
         << setw(18) << result
         << status << "\n";
         
    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Expected: " << expected << "\n"
             << "     Got:      " << result << "\n";
    }
}

int main() {
    cout << "\n";
    cout << "  🚀 GeeksforGeeks Day 176 - Minimum Deletions to Make Sorted Test Suite  \n";
    cout << "⇚ - ==================================================================================== - ⇛\n";
    cout << left << setw(6)  << "[ID]" 
         << setw(32) << "Input Array (arr)" 
         << setw(18) << "Expected Deletes" 
         << setw(18) << "Actual Deletes" 
         << "Status\n";
    cout << string(88, '-') << "\n";

    // Test Case 1: Example 1 from GFG
    runTest(1, {5, 6, 1, 7, 4}, 2);

    // Test Case 2: Example 2 from GFG (all same)
    runTest(2, {1, 1, 1}, 2);

    // Test Case 3: Already sorted (strictly increasing)
    runTest(3, {1, 2, 3, 4, 5}, 0);

    // Test Case 4: Reverse sorted (strictly decreasing)
    runTest(4, {5, 4, 3, 2, 1}, 4);

    // Test Case 5: Single element
    runTest(5, {10}, 0);

    // Test Case 6: Mixed element LIS sequence
    runTest(6, {2, 5, 3, 7, 11, 8, 10, 13, 6}, 3);

    // Test Case 7: Standard LIS problem test case
    runTest(7, {10, 22, 9, 33, 21, 50, 41, 60, 80}, 3);

    cout << "⇚ - ==================================================================================== - ⇛\n";
    cout << "                         🎉 All Tests Completed Successfully!                           \n\n";

    return 0;
}
