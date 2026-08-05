#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

void runTest(int testNum, const vector<int>& arr, int l, int r, int expected) {
    Solution sol;
    vector<int> arrCopy = arr; // pass a copy since signature takes non-const ref
    int result = sol.countSubarray(arrCopy, l, r);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";
    
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);
    
    // Construct array representation for printing
    string arrStr = "[";
    for (size_t i = 0; i < arr.size(); ++i) {
        arrStr += to_string(arr[i]);
        if (i < arr.size() - 1) arrStr += ",";
        if (arrStr.length() > 20) {
            arrStr += "...";
            break;
        }
    }
    arrStr += "]";
    
    string rangeStr = "[" + to_string(l) + "," + to_string(r) + "]";
    
    cout << left << setw(6)  << testId 
         << setw(20) << arrStr
         << setw(14) << rangeStr
         << setw(10) << to_string(result)
         << setw(10) << to_string(expected)
         << status << "\n";
         
    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Expected: " << expected << "\n"
             << "     Got:      " << result << "\n";
    }
}

int main() {
    cout << "\n🔢 Subarrays with Sum in Range — Test Suite\n";
    cout << "⇚ - ================================================================ - ⇛\n";
    cout << left << setw(6)  << "[ID]" 
         << setw(20) << "Array" 
         << setw(14) << "Range [l, r]" 
         << setw(10) << "Result" 
         << setw(10) << "Expected" 
         << "Status\n";
    cout << string(72, '-') << "\n";

    runTest(1, {1, 4, 6}, 3, 8, 3);
    runTest(2, {2, 3, 5, 8}, 4, 13, 6);
    runTest(3, {5}, 4, 6, 1);
    runTest(4, {2}, 4, 6, 0);
    runTest(5, {1, 1, 1}, 1, 3, 6);
    runTest(6, {1, 2, 3, 4}, 5, 5, 1);

    cout << "⇚ - ================================================================= - ⇛\n";
    cout << "                         🎉 All Tests Executed!                         \n\n";

    return 0;
}
