#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

void runTest(int testNum, const vector<int>& arr, int expected) {
    Solution sol;
    vector<int> arrCopy = arr; // pass a copy since signature takes non-const ref
    int result = sol.countMinOperations(arrCopy);
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
    
    cout << left << setw(6)  << testId 
         << setw(25) << arrStr
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
    cout << "\n🔢 Minimum Steps to Get Desired Array — Test Suite\n";
    cout << "⇚ - ================================================================ - ⇛\n";
    cout << left << setw(6)  << "[ID]" 
         << setw(25) << "Array" 
         << setw(10) << "Result" 
         << setw(10) << "Expected" 
         << "Status\n";
    cout << string(72, '-') << "\n";

    runTest(1, {16, 16, 16}, 7);
    runTest(2, {2, 3}, 4);
    runTest(3, {0, 0}, 0);
    runTest(4, {1}, 1);
    runTest(5, {2, 1, 4}, 5);
    runTest(6, {10}, 5);

    cout << "⇚ - ================================================================= - ⇛\n";
    cout << "                         🎉 All Tests Executed!                         \n\n";

    return 0;
}
