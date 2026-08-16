#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

void runTest(int testNum, vector<int> arr, long long expected) {
    Solution sol;
    long long result = sol.minProductSubset(arr);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";
    
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);
    
    string arrStr = "[";
    for (size_t i = 0; i < arr.size(); ++i) {
        arrStr += to_string(arr[i]);
        if (i + 1 < arr.size()) arrStr += ", ";
    }
    arrStr += "]";

    cout << left << setw(6)  << testId 
         << setw(24) << arrStr
         << setw(12) << to_string(result)
         << status << "\n";
         
    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Expected: " << expected << "\n"
             << "     Got:      " << result << "\n";
    }
}

int main() {
    cout << "\n🔢 Min Product Subset — Test Suite\n";
    cout << "※ ======================================================== ※\n";
    cout << left << setw(6)  << "[ID]" 
         << setw(24) << "Array" 
         << setw(12) << "Result" 
         << "Status\n";
    cout << string(56, '-') << "\n";

    runTest(1, {1, 2, 3}, 1);
    runTest(2, {4, -2, 5}, -40);
    runTest(3, {-1, -2}, -2);
    runTest(4, {-1, -2, 0}, -2);
    runTest(5, {0, 0, 0}, 0);
    runTest(6, {-5}, -5);
    runTest(7, {7}, 7);
    runTest(8, {-1, -2, -3, 0, 4}, -24);

    cout << "※ ======================================================== ※\n";
    cout << "          🎉 All Tests Executed!             \n\n";

    return 0;
}
