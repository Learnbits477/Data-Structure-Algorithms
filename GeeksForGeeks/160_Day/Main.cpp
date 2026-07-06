#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

string vectorToString(const vector<int>& v) {
    string res = "[";
    for (size_t i = 0; i < v.size(); ++i) {
        res += to_string(v[i]);
        if (i < v.size() - 1) res += ", ";
    }
    res += "]";
    return res;
}

void runTest(int testNum, vector<int> a, vector<int> b, int expected) {
    Solution sol;
    int result = sol.maxPathSum(a, b);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";
    
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);
    
    string inputStr = vectorToString(a) + ", " + vectorToString(b);
    if (inputStr.length() > 42) {
        inputStr = inputStr.substr(0, 39) + "...";
    }
    
    cout << left << setw(6)  << testId 
         << setw(42) << inputStr
         << setw(15) << expected
         << setw(15) << result
         << status << "\n";
         
     if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Input a: " << vectorToString(a) << "\n"
             << "     Input b: " << vectorToString(b) << "\n"
             << "     Expected: " << expected << "\n"
             << "     Got:      " << result << "\n";
     }
}

int main() {
    cout << "\n";
    cout << "  🚀 GeeksforGeeks Day 160 - Max Sum Path in Two Arrays Test Suite  \n";
    cout << "⇚ - ===================================================================================== - ⇛\n";
    cout << left << setw(6)  << "[ID]" 
         << setw(42) << "Input Arrays (a, b)" 
         << setw(15) << "Expected" 
         << setw(15) << "Actual" 
         << "Status\n";
    cout << string(90, '-') << "\n";

    // Example 1
    runTest(1, {2, 3, 7, 10, 12}, {1, 5, 7, 8}, 35);
    
    // Example 2
    runTest(2, {1, 2, 3}, {3, 4, 5}, 15);
    
    // Additional Test 3: No common elements
    runTest(3, {1, 3, 5}, {2, 4, 6}, 12);
    
    // Additional Test 4: All common elements
    runTest(4, {1, 2, 3}, {1, 2, 3}, 6);
    
    // Additional Test 5: Multiple intersection segments
    runTest(5, {1, 5, 10, 15}, {2, 5, 8, 10, 12}, 40);

    cout << "⇚ - ===================================================================================== - ⇛\n";
    cout << "                         🎉 All Tests Completed Successfully!                           \n";

    return 0;
}
