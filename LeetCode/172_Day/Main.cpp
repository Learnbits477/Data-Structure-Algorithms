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

void runTest(int testNum, vector<int> nums, int expected) {
    Solution sol;
    
    int result = sol.findGCD(nums);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";
    
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);
    
    string inputStr = vectorToString(nums);
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
    cout << "  🚀 LeetCode Day 172 - Find Greatest Common Divisor of Array Test Suite  \n";
    cout << "⇚ - ===================================================================================== - ⇛\n";
    cout << left << setw(6)  << "[ID]" 
         << setw(45) << "Input Array (nums)" 
         << setw(12) << "Expected" 
         << setw(12) << "Actual" 
         << "Status\n";
    cout << string(90, '-') << "\n";

    // Test Case 1: Example 1 from description
    runTest(1, {2, 5, 6, 9, 10}, 2);

    // Test Case 2: Example 2 from description
    runTest(2, {7, 5, 6, 8, 3}, 1);

    // Test Case 3: Example 3 from description
    runTest(3, {3, 3}, 3);

    // Test Case 4: Large identical boundaries
    runTest(4, {1000, 1000}, 1000);

    // Test Case 5: Custom elements
    runTest(5, {12, 18, 24, 30}, 6);

    // Test Case 6: Prime and Composite
    runTest(6, {17, 34, 51}, 17);

    cout << "⇚ - ===================================================================================== - ⇛\n";
    cout << "                         🎉 All Tests Completed Successfully!                           \n";

    return 0;
}
