#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

string vectorToString(const vector<int>& vec) {
    string res = "[";
    for (size_t i = 0; i < vec.size(); i++) {
        res += to_string(vec[i]);
        if (i + 1 < vec.size()) res += ", ";
    }
    res += "]";
    return res;
}

void runTest(int testNum, vector<int> arr, int expected) {
    Solution sol;
    int result = sol.maxSumSubarray(arr);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";
    
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);
    
    string inputStr = vectorToString(arr);
    if (inputStr.length() > 30) {
        inputStr = inputStr.substr(0, 27) + "...";
    }
    
    cout << left << setw(6)  << testId 
         << setw(32) << inputStr
         << setw(18) << expected
         << setw(18) << result
         << status << "\n";
         
     if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Input: arr = " << vectorToString(arr) << "\n"
             << "     Expected: " << expected << "\n"
             << "     Got:      " << result << "\n";
     }
}

int main() {
    cout << "\n";
    cout << "  🚀 GeeksforGeeks Day 155 - Max Sum Subarray by Removing at Most One Element Test Suite  \n";
    cout << "⇚ - ===================================================================================== - ⇛\n";
    cout << left << setw(6)  << "[ID]" 
         << setw(32) << "Input (arr)" 
         << setw(18) << "Expected" 
         << setw(18) << "Actual" 
         << "Status\n";
    cout << string(90, '-') << "\n";

    // Example 1
    runTest(1, {1, 2, 3, -4, 5}, 11);
    
    // Example 2
    runTest(2, {-2, -3, 4, -1, -2, 1, 5, -3}, 9);
    
    // Additional Test 3 - All negatives
    runTest(3, {-2, -3, -1, -5}, -1);
    
    // Additional Test 4 - Single element
    runTest(4, {10}, 10);
    
    // Additional Test 5 - Standard subarray with deletion
    runTest(5, {1, -2, 3}, 4);
    
    // Additional Test 6 - All positives (no deletion needed)
    runTest(6, {1, 2, 3}, 6);

    cout << "⇚ - ===================================================================================== - ⇛\n";
    cout << "                         🎉 All Tests Completed Successfully!                           \n";

    return 0;
}
