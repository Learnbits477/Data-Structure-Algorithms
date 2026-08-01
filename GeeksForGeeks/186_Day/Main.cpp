#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void runTest(int testNum, int n, vector<int> a, vector<int> b, vector<int> k, int expected) {
    Solution sol;
    int result = sol.findMax(n, a, b, k);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";
    
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);
    
    cout << left << setw(6)  << testId 
         << setw(8)  << ("n=" + to_string(n))
         << setw(12)  << ("ops=" + to_string(a.size()))
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
    cout << "\n🔢 Max After m Range Increments — Test Suite\n";
    cout << "⇚ - ======================================================================= - ⇛\n";
    cout << left << setw(6)  << "[ID]" 
         << setw(8)  << "Size" 
         << setw(12)  << "Operations" 
         << setw(12) << "Result" 
         << setw(12) << "Expected" 
         << "Status\n";
    cout << string(64, '-') << "\n";

    runTest(1, 5, {0, 1, 2}, {1, 4, 3}, {100, 100, 100}, 200);
    runTest(2, 4, {1, 0, 3}, {2, 0, 3}, {603, 286, 882}, 882);
    runTest(3, 3, {0, 0, 0}, {2, 2, 2}, {5, 10, 15}, 30);
    runTest(4, 1, {0}, {0}, {42}, 42);
    runTest(5, 10, {0, 2, 5, 8}, {9, 7, 6, 8}, {10, 20, 30, 40}, 60);

    cout << "⇚ - ======================================================================= - ⇛\n";
    cout << "                         🎉 All Tests Executed!                         \n\n";

    return 0;
}
