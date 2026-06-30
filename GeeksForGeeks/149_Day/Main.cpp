#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

string serializeVector(const vector<int>& vec) {
    if (vec.empty()) return "[]";
    string res = "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        res += to_string(vec[i]);
        if (i + 1 < vec.size()) res += ",";
    }
    res += "]";
    return res;
}

void runTest(int testNum, int n, vector<int> expected) {
    Solution sol;
    vector<int> result = sol.increasingNumbers(n);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";
    
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);
    
    string inputStr = "n = " + to_string(n);
    string expectedStr = serializeVector(expected);
    string actualStr = serializeVector(result);
    
    cout << left << setw(6)  << testId 
         << setw(15) << inputStr
         << setw(50) << (expectedStr.length() > 47 ? expectedStr.substr(0, 44) + "..." : expectedStr)
         << setw(50) << (actualStr.length() > 47 ? actualStr.substr(0, 44) + "..." : actualStr)
         << status << "\n";
         
    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Input: " << n << "\n"
             << "     Expected: " << expectedStr << "\n"
             << "     Got:      " << actualStr << "\n";
    }
}

int main() {
    cout << "\n";
    cout << "  🚀 GeeksforGeeks Day 149 - N-Digit Numbers with Increasing Digits Test Suite  \n";
    cout << "⇚======================================================================================================================⇛\n";
    cout << left << setw(6)  << "[ID]" 
         << setw(15) << "Input" 
         << setw(50) << "Expected Numbers" 
         << setw(50) << "Actual Numbers" 
         << "Status\n";
    cout << string(130, '-') << "\n";

    runTest(1, 1, {0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
    runTest(2, 2, {12, 13, 14, 15, 16, 17, 18, 19, 23, 24, 25, 26, 27, 28, 29, 34, 35, 36, 37, 38, 39, 45, 46, 47, 48, 49, 56, 57, 58, 59, 67, 68, 69, 78, 79, 89});
    runTest(3, 15, {});
    runTest(4, 3, {
        123, 124, 125, 126, 127, 128, 129, 134, 135, 136, 137, 138, 139, 145, 146, 147, 148, 149, 
        156, 157, 158, 159, 167, 168, 169, 178, 179, 189, 234, 235, 236, 237, 238, 239, 245, 246, 
        247, 248, 249, 256, 257, 258, 259, 267, 268, 269, 278, 279, 289, 345, 346, 347, 348, 349, 
        356, 357, 358, 359, 367, 368, 369, 378, 379, 389, 456, 457, 458, 459, 467, 468, 469, 478, 
        479, 489, 567, 568, 569, 578, 579, 589, 678, 679, 689, 789
    });
    runTest(5, 9, {123456789});
    runTest(6, 10, {});

    cout << "⇚======================================================================================================================⇛\n";
    cout << "                         🎉 All Tests Completed Successfully!                           \n";

    return 0;
}
