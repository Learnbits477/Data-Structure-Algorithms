#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

// Helper to format vectors as strings for pretty printing
string vectorToString(const vector<int>& vec) {
    string res = "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        res += to_string(vec[i]);
        if (i + 1 < vec.size()) res += ", ";
    }
    res += "]";
    return res;
}

void runTest(int testNum, const vector<int>& arr, const vector<int>& expected) {
    Solution sol;
    vector<int> arrCopy = arr;
    vector<int> result = sol.optimalArray(arrCopy);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";
    
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);
    
    string inputStr = vectorToString(arr);
    if (inputStr.length() > 25) {
        inputStr = inputStr.substr(0, 22) + "...";
    }
    
    string expectedStr = vectorToString(expected);
    if (expectedStr.length() > 20) {
        expectedStr = expectedStr.substr(0, 17) + "...";
    }
    
    string resultStr = vectorToString(result);
    if (resultStr.length() > 20) {
        resultStr = resultStr.substr(0, 17) + "...";
    }
    
    cout << left << setw(6)  << testId 
         << setw(28) << inputStr
         << setw(22) << expectedStr
         << setw(22) << resultStr
         << status << "\n";
         
    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Input:    " << vectorToString(arr) << "\n"
             << "     Expected: " << vectorToString(expected) << "\n"
             << "     Got:      " << vectorToString(result) << "\n";
    }
}

int main() {
    cout << "\n";
    cout << "  🚀 GeeksforGeeks Day 143 - Equalize All Prefix Sums Test Suite  \n";
    cout << "⇚========================================================================================⇛\n";
    cout << left << setw(6)  << "[ID]" 
         << setw(28) << "Input Array (arr[])" 
         << setw(22) << "Expected Output" 
         << setw(22) << "Actual Output" 
         << "Status\n";
    cout << string(92, '-') << "\n";

    // Example 1
    runTest(1, {1, 6, 9, 12}, {0, 5, 8, 14});
    
    // Example 2
    runTest(2, {1, 1, 1, 7, 7, 10, 19}, {0, 0, 0, 6, 12, 21, 33});
    
    // Test Case 3: Already equal array
    runTest(3, {5, 5, 5, 5}, {0, 0, 0, 0});
    
    // Test Case 4: Single element
    runTest(4, {10}, {0});
    
    // Test Case 5: Negative and positive mixed sorted array
    runTest(5, {-5, -2, 1, 4}, {0, 3, 6, 12});
    
    // Test Case 6: Larger values with large differences
    runTest(6, {100, 200, 300, 400}, {0, 100, 200, 400});
    
    // Test Case 7: Sequence of increasing consecutive numbers
    runTest(7, {1, 2, 3, 4, 5}, {0, 1, 2, 4, 6});

    cout << "⇚========================================================================================⇛\n";
    cout << "                         🎉 All Tests Completed Successfully!                           \n";

    return 0;
}
