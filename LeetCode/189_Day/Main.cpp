#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

string vecToString(const vector<int>& vec) {
    string s = "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        s += to_string(vec[i]);
        if (i < vec.size() - 1) s += ",";
    }
    s += "]";
    return s;
}

void runTest(int testNum, const vector<int>& nums, const vector<int>& expected) {
    Solution sol;
    vector<int> numsCopy = nums;
    vector<int> result = sol.findMissingElements(numsCopy);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";
    
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);
    
    string inputStr = vecToString(nums);
    if (inputStr.length() > 22) {
        inputStr = inputStr.substr(0, 19) + "...]";
    }
    
    string resultStr = vecToString(result);
    if (resultStr.length() > 22) {
        resultStr = resultStr.substr(0, 19) + "...]";
    }
    
    string expectedStr = vecToString(expected);
    if (expectedStr.length() > 22) {
        expectedStr = expectedStr.substr(0, 19) + "...]";
    }
    
    cout << left << setw(6)  << testId 
         << setw(24) << inputStr
         << setw(24) << resultStr
         << setw(24) << expectedStr
         << status << "\n";
         
    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Expected: " << vecToString(expected) << "\n"
             << "     Got:      " << vecToString(result) << "\n";
    }
}

int main() {
    cout << "\n🔢 [3731. Find Missing Elements] — Test Suite\n";
    cout << "⇚ - ==================================================================================== - ⇛\n";
    cout << left << setw(6)  << "[ID]" 
         << setw(24) << "Input Array" 
         << setw(24) << "Result" 
         << setw(24) << "Expected" 
         << "Status\n";
    cout << string(90, '-') << "\n";

    runTest(1, {1, 4, 2, 5}, {3});
    runTest(2, {7, 8, 6, 9}, {});
    runTest(3, {5, 1}, {2, 3, 4});
    runTest(4, {3, 4}, {});
    runTest(5, {1, 10}, {2, 3, 4, 5, 6, 7, 8, 9});

    cout << "⇚ - ==================================================================================== - ⇛\n";
    cout << "                         🎉 All Tests Executed!                         \n\n";

    return 0;
}
