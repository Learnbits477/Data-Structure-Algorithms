#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

string vectorToString(const vector<int>& vec) {
    string res = "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        res += to_string(vec[i]);
        if (i + 1 < vec.size()) res += ", ";
    }
    res += "]";
    return res;
}

void runTest(int testNum, vector<int> height, int expected) {
    Solution sol;
    vector<int> heightCopy = height;
    int result = sol.maxArea(heightCopy);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";
    
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);
    
    string displayInput = vectorToString(height);
    if (displayInput.length() > 24) {
        displayInput = displayInput.substr(0, 21) + "...";
    }
    
    cout << left << setw(6)  << testId 
         << setw(28) << displayInput
         << setw(18) << expected
         << setw(18) << result
         << status << "\n";
         
    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Input:    " << vectorToString(height) << "\n"
             << "     Expected: " << expected << "\n"
             << "     Got:      " << result << "\n";
    }
}

int main() {
    cout << "\n";
    cout << "  🚀 GeeksforGeeks Day 146 - Dam of Candies Test Suite  \n";
    cout << "⇚======================================================================================⇛\n";
    cout << left << setw(6)  << "[ID]" 
         << setw(28) << "Height Array (height[])" 
         << setw(18) << "Expected Area" 
         << setw(18) << "Actual Area" 
         << "Status\n";
    cout << string(88, '-') << "\n";

    // Example 1
    runTest(1, {2, 5, 4, 3, 7}, 10);
    
    // Example 2
    runTest(2, {1, 3, 4}, 1);
    
    // Test Case 3: Only two bars (width is 0, so area should be 0)
    runTest(3, {5, 10}, 0);
    
    // Test Case 4: Increasing sequence
    runTest(4, {1, 2, 3, 4, 5}, 4);
    
    // Test Case 5: Bottleneck on ends with empty space in between
    runTest(5, {10, 1, 1, 10}, 20);
    
    // Test Case 6: Decreasing sequence
    runTest(6, {5, 4, 3, 2, 1}, 4);
    
    // Test Case 7: Uniform heights
    runTest(7, {5, 5, 5, 5, 5}, 15);

    cout << "⇚======================================================================================⇛\n";
    cout << "                         🎉 All Tests Completed Successfully!                           \n";

    return 0;
}
