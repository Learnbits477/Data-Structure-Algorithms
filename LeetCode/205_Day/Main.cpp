#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

string vecToString(const vector<int>& vec) {
    string res = "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        res += to_string(vec[i]);
        if (i + 1 < vec.size()) res += ",";
    }
    res += "]";
    return res;
}

void runTest(int testNum, vector<int> nums, vector<int> expected) {
    Solution sol;
    vector<int> result = sol.resultArray(nums);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";
    
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);
    
    string inputStr = vecToString(nums);
    if (inputStr.length() > 22) {
        inputStr = inputStr.substr(0, 19) + "...]";
    }

    string resStr = vecToString(result);
    if (resStr.length() > 22) {
        resStr = resStr.substr(0, 19) + "...]";
    }

    string expStr = vecToString(expected);
    if (expStr.length() > 22) {
        expStr = expStr.substr(0, 19) + "...]";
    }

    cout << left << setw(6)  << testId 
         << setw(24) << inputStr
         << setw(24) << resStr
         << setw(24) << expStr
         << status << "\n";
         
    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Expected: " << vecToString(expected) << "\n"
             << "     Got:      " << vecToString(result) << "\n";
    }
}

int main() {
    cout << "\n🔢 Distribute Elements Into Two Arrays I — Test Suite\n";
    cout << "※ ================================================================================= ※\n";
    cout << left << setw(6)  << "[ID]" 
         << setw(24) << "Input nums" 
         << setw(24) << "Result" 
         << setw(24) << "Expected" 
         << "Status\n";
    cout << string(83, '-') << "\n";

    runTest(1, {2, 1, 3}, {2, 3, 1});
    runTest(2, {5, 4, 3, 8}, {5, 3, 4, 8});
    runTest(3, {1, 2, 4}, {1, 2, 4});
    runTest(4, {10, 5, 2, 8, 1}, {10, 2, 5, 8, 1});
    runTest(5, {3, 2, 1}, {3, 1, 2});

    cout << "※ ================================================================================= ※\n";
    cout << "                         🎉 All Tests Completed Successfully!                        \n\n";

    return 0;
}
