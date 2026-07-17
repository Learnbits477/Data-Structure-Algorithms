#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

string vectorToString(const vector<int>& v) {
    string s = "[";
    for (size_t i = 0; i < v.size(); ++i) {
        s += to_string(v[i]);
        if (i < v.size() - 1) s += ", ";
    }
    s += "]";
    return s;
}

void runTest(int testNum, vector<int> arr, int expected) {
    Solution sol;
    
    int result = sol.maxDiffSubArrays(arr);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";
    
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);
    
    string inputStr = vectorToString(arr);
    if (inputStr.length() > 42) {
        inputStr = inputStr.substr(0, 39) + "...";
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
    cout << "  🚀 GeeksforGeeks Day 171 - Max Absolute Diff of Two Subarrays Test Suite  \n";
    cout << "⇚ - ===================================================================================== - ⇛\n";
    cout << left << setw(6)  << "[ID]" 
         << setw(45) << "Input Array (arr)" 
         << setw(12) << "Expected" 
         << setw(12) << "Actual" 
         << "Status\n";
    cout << string(90, '-') << "\n";

    // Test Case 1: Example 1 from GFG description
    runTest(1, {-2, -3, 4, -1, -2, 1, 5, -3}, 12);

    // Test Case 2: Example 2 from GFG description
    runTest(2, {2, -1, -2, 1, -4, 2, 8}, 16);

    // Test Case 3: Smallest size boundary case
    runTest(3, {1, -1}, 2);

    // Test Case 4: All positive elements
    runTest(4, {1, 2, 3, 4}, 8);

    // Test Case 5: All negative elements
    runTest(5, {-1, -2, -3, -4}, 8);

    // Test Case 6: Mixed elements with single large element
    runTest(6, {10, -20, 30, -40, 50}, 90);

    // Test Case 7: Alternating signs
    runTest(7, {5, -5, 5, -5, 5, -5}, 10);

    cout << "⇚ - ===================================================================================== - ⇛\n";
    cout << "                         🎉 All Tests Completed Successfully!                           \n";

    return 0;
}

