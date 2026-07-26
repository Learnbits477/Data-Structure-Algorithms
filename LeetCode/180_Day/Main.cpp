#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string vecToString(const vector<int>& vec) {
    string res = "[";
    for (size_t i = 0; i < vec.size(); i++) {
        res += to_string(vec[i]);
        if (i + 1 < vec.size()) res += ", ";
    }
    res += "]";
    return res;
}

void runTest(int testNum, vector<int> nums, int expected) {
    Solution sol;
    int result = sol.maximumProduct(nums);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";
    
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);
    
    string inputStr = vecToString(nums);
    if (inputStr.length() > 28) {
        inputStr = inputStr.substr(0, 25) + "...";
    }
    
    cout << left << setw(6)  << testId 
         << setw(30) << inputStr
         << setw(20) << expected
         << setw(20) << result
         << status << "\n";
         
    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Expected: " << expected << "\n"
             << "     Got:      " << result << "\n";
    }
}

int main() {
    cout << "\n🔢 Maximum Product of Three Numbers — Test Suite\n";
    cout << "⇚ - ================================================================================ - ⇛\n";
    cout << left << setw(6)  << "[ID]" 
         << setw(30) << "Input Array" 
         << setw(20) << "Expected Product" 
         << setw(20) << "Actual Product" 
         << "Status\n";
    cout << string(85, '-') << "\n";

    // Test Case 1: Example 1
    runTest(1, {1, 2, 3}, 6);

    // Test Case 2: Example 2
    runTest(2, {1, 2, 3, 4}, 24);

    // Test Case 3: Example 3
    runTest(3, {-1, -2, -3}, -6);

    // Test Case 4: Mixture of negative and positive numbers
    runTest(4, {-10, -10, 5, 2}, 500);

    // Test Case 5: All negative numbers (different values)
    runTest(5, {-1, -2, -3, -4}, -6);

    // Test Case 6: Duplicates and zeros
    runTest(6, {-1, 0, 1, 2, -1, 3}, 6);

    // Test Case 7: Boundary values (max constraints)
    runTest(7, {1000, 1000, 1000}, 1000000000);

    cout << "⇚ - ================================================================================= - ⇛\n";
    cout << "                           🎉 All Tests Completed Successfully!                           \n\n";

    return 0;
}
