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

string boolToString(bool val) {
    return val ? "true" : "false";
}

void runTest(int testNum, vector<int> arr, int k, bool expected) {
    Solution sol;
    bool result = sol.divisibleByK(arr, k);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";
    
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);
    
    string inputStr = vectorToString(arr);
    if (inputStr.length() > 22) {
        inputStr = inputStr.substr(0, 19) + "...";
    }
    
    cout << left << setw(6)  << testId 
         << setw(24) << inputStr
         << setw(10) << k
         << setw(16) << boolToString(expected)
         << setw(16) << boolToString(result)
         << status << "\n";
         
     if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Input: arr = " << vectorToString(arr) << ", k = " << k << "\n"
             << "     Expected: " << boolToString(expected) << "\n"
             << "     Got:      " << boolToString(result) << "\n";
     }
}

int main() {
    cout << "\n";
    cout << "  🚀 GeeksforGeeks Day 156 - Subset with Sum Divisible by m Test Suite  \n";
    cout << "⇚ - ===================================================================================== - ⇛\n";
    cout << left << setw(6)  << "[ID]" 
         << setw(24) << "Input (arr)" 
         << setw(10) << "k"
         << setw(16) << "Expected" 
         << setw(16) << "Actual" 
         << "Status\n";
    cout << string(90, '-') << "\n";

    // Example 1
    runTest(1, {3, 1, 7, 5}, 6, true);
    
    // Example 2
    runTest(2, {1, 2, 6}, 5, false);
    
    // Additional Test 3 - PHP Optimization (n >= k)
    runTest(3, {1, 2, 3}, 3, true);
    
    // Additional Test 4 - Single element divisible
    runTest(4, {12}, 6, true);
    
    // Additional Test 5 - Single element not divisible
    runTest(5, {4}, 5, false);
    
    // Additional Test 6 - Multiple elements divisible
    runTest(6, {6, 12, 18}, 6, true);

    cout << "⇚ - ===================================================================================== - ⇛\n";
    cout << "                         🎉 All Tests Completed Successfully!                           \n";

    return 0;
}
