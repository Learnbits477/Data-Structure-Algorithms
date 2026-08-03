#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

void runTest(int testNum, const vector<int>& arr, int k, long long expected) {
    Solution sol;
    vector<int> arrCopy = arr; // pass a copy since signature takes non-const ref
    long long result = sol.maxSumWithK(arrCopy, k);
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
         << setw(6)  << ("k=" + to_string(k))
         << setw(12) << to_string(result)
         << setw(12) << to_string(expected)
         << status << "\n";
         
    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Expected: " << expected << "\n"
             << "     Got:      " << result << "\n";
    }
}

int main() {
    cout << "\n🔢 Max Sum Subarray of Size at least K — Test Suite\n";
    cout << "⇚ - ================================================================= - ⇛\n";
    cout << left << setw(6)  << "[ID]" 
         << setw(25) << "Array" 
         << setw(6)  << "k" 
         << setw(12) << "Result" 
         << setw(12) << "Expected" 
         << "Status\n";
    cout << string(68, '-') << "\n";

    runTest(1, {1, -2, 2, -3}, 3, 1);
    runTest(2, {1, 1, 1, 1, 1, 1}, 2, 6);
    runTest(3, {-4, -2, 1, -3}, 2, -1);
    runTest(4, {1, 2, 3, 4, 5}, 1, 15);
    runTest(5, {-1, -2, -3, -4}, 2, -3);
    runTest(6, {5, -10, 6, 9, 0}, 2, 15); // [6, 9, 0] or [6, 9]

    cout << "⇚ - ================================================================= - ⇛\n";
    cout << "                         🎉 All Tests Executed!                         \n\n";

    return 0;
}
