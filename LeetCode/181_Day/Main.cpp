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
    int result = sol.maxProduct(nums);
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
    cout << "\n🔢 Maximum Product of Two Elements in an Array — Test Suite\n";
    cout << "⇚ - ================================================================================ - ⇛\n";
    cout << left << setw(6)  << "[ID]" 
         << setw(30) << "Input Array" 
         << setw(20) << "Expected Product" 
         << setw(20) << "Actual Product" 
         << "Status\n";
    cout << string(85, '-') << "\n";

    runTest(1, {3, 4, 5, 2}, 12);
    runTest(2, {1, 5, 4, 5}, 16);
    runTest(3, {3, 7}, 12);
    runTest(4, {10, 10}, 81);
    runTest(5, {1, 1, 1, 1}, 0);
    runTest(6, {1000, 1000}, 998001);

    cout << "⇚ - ================================================================================= - ⇛\n";
    cout << "                           🎉 All Tests Completed Successfully!                           \n\n";

    return 0;
}
