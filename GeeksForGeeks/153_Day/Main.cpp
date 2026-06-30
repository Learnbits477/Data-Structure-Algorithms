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

void runTest(int testNum, vector<int> a, vector<int> b, int expected) {
    Solution sol;
    int result = sol.maxDotProduct(a, b);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";
    
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);
    
    string inputStr = "a: " + vectorToString(a) + ", b: " + vectorToString(b);
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
             << "     Input: a = " << vectorToString(a) << ", b = " << vectorToString(b) << "\n"
             << "     Expected: " << expected << "\n"
             << "     Got:      " << result << "\n";
    }
}

int main() {
    cout << "\n";
    cout << "  🚀 GeeksforGeeks Day 153 - Maximize Dot Product Test Suite  \n";
    cout << "⇚======================================================================================================================⇛\n";
    cout << left << setw(6)  << "[ID]" 
         << setw(32) << "Input (a, b)" 
         << setw(18) << "Expected" 
         << setw(18) << "Actual" 
         << "Status\n";
    cout << string(90, '-') << "\n";

    // Example 1
    runTest(1, {2, 3, 1, 7, 8}, {3, 6, 7}, 107);
    
    // Example 2
    runTest(2, {1, 2, 3}, {4}, 12);
    
    // Additional Test 3
    runTest(3, {10, 20, 30}, {5, 10}, 400);
    
    // Additional Test 4
    runTest(4, {1, 2, 3, 4}, {1, 2}, 11);
    
    // Additional Test 5
    runTest(5, {5, 4, 3, 2, 1}, {1, 2, 3}, 22);

    cout << "⇚======================================================================================================================⇛\n";
    cout << "                         🎉 All Tests Completed Successfully!                           \n";

    return 0;
}
