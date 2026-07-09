#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

string vectorToString(const vector<int>& vec) {
    if (vec.empty()) return "[]";
    string res = "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        res += to_string(vec[i]);
        if (i < vec.size() - 1) res += ", ";
    }
    res += "]";
    return res;
}

void runTest(int testNum, const vector<int>& arr, int k, int expected) {
    Solution sol;
    vector<int> arrCopy = arr;
    int result = sol.countKdivPairs(arrCopy, k);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";
    
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);
    
    string inputStr = "Arr: " + vectorToString(arr) + ", k: " + to_string(k);
    if (inputStr.length() > 45) {
        inputStr = inputStr.substr(0, 42) + "...";
    }
    
    cout << left << setw(6)  << testId 
         << setw(45) << inputStr
         << setw(12) << expected
         << setw(12) << result
         << status << "\n";
         
    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Array:    " << vectorToString(arr) << "\n"
             << "     k:        " << k << "\n"
             << "     Expected: " << expected << "\n"
             << "     Got:      " << result << "\n";
    }
}

int main() {
    cout << "\n";
    cout << "  🚀 GeeksforGeeks Day 163 - Count Pairs Divisible By K Test Suite  \n";
    cout << "⇚ - ===================================================================================== - ⇛\n";
    cout << left << setw(6)  << "[ID]" 
         << setw(45) << "Input Parameters (Array, k)" 
         << setw(12) << "Expected" 
         << setw(12) << "Actual" 
         << "Status\n";
    cout << string(90, '-') << "\n";

    runTest(1, {2, 2, 1, 7, 5, 3}, 4, 5);
    runTest(2, {5, 9, 36, 74, 52, 31, 42}, 3, 7);
    runTest(3, {5}, 3, 0);
    runTest(4, {3, 6, 9, 12}, 3, 6);
    runTest(5, {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 5, 9);

    cout << "⇚ - ===================================================================================== - ⇛\n";
    cout << "                         🎉 All Tests Completed Successfully!                           \n";

    return 0;
}
