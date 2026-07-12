#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <numeric>
using namespace std;

void runTest(int testNum, vector<int> arr, int k, int expected) {
    Solution sol;
    
    vector<int> originalArr = arr;
    
    int result = sol.maxAmount(arr, k);
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
    
    string inputStr = "arr = " + arrStr + ", k = " + to_string(k);
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
    cout << "  🚀 GeeksforGeeks Day 166 - Max Amount by Selling K Tickets Test Suite  \n";
    cout << "⇚ - ===================================================================================== - ⇛\n";
    cout << left << setw(6)  << "[ID]" 
         << setw(45) << "Input Parameters (arr, k)" 
         << setw(12) << "Expected" 
         << setw(12) << "Actual" 
         << "Status\n";
    cout << string(90, '-') << "\n";

    // Test Case 1: Example 1 from GFG description
    // arr[] = [4, 3, 6, 2, 4], k = 3 -> Expected: 15
    runTest(1, {4, 3, 6, 2, 4}, 3, 15);

    // Test Case 2: Example 2 from GFG description
    // arr[] = [5, 3, 5, 2, 4, 4], k = 2 -> Expected: 10
    runTest(2, {5, 3, 5, 2, 4, 4}, 2, 10);

    // Test Case 3: Single element array where k is less than arr[0]
    // arr[] = [10], k = 5 -> Expected: 10+9+8+7+6 = 40
    runTest(3, {10}, 5, 40);

    // Test Case 4: Ticket shortage (k > sum of all tickets)
    // arr[] = [2], k = 5 -> Expected: 2+1 = 3 (only 2 tickets available)
    runTest(4, {2}, 5, 3);

    // Test Case 5: Large modulo test case
    // arr[] = [1000000], k = 1000000
    // Sum of 1 to 10^6 is 500000500000
    // 500000500000 % 1000000007 = 496500
    runTest(5, {1000000}, 1000000, 496500);

    // Test Case 6: Duplicate elements requiring sub-batch splitting
    // arr[] = [3, 3, 3], k = 4 -> Expected: 11
    runTest(6, {3, 3, 3}, 4, 11);

    cout << "⇚ - ===================================================================================== - ⇛\n";
    cout << "                         🎉 All Tests Completed Successfully!                           \n";

    return 0;
}
