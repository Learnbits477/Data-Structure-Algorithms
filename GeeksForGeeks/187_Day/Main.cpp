#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

void runTest(int testNum, int n, int m, int expected) {
    Solution sol;
    int result = sol.count(n, m);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";
    
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);
    
    cout << left << setw(6)  << testId 
         << setw(8)  << ("n=" + to_string(n))
         << setw(8)  << ("m=" + to_string(m))
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
    cout << "\n🔢 Sequences where Adjacent Divide — Test Suite\n";
    cout << "⇚ - ======================================================= - ⇛\n";
    cout << left << setw(6)  << "[ID]" 
         << setw(8)  << "Length" 
         << setw(8)  << "Range" 
         << setw(12) << "Result" 
         << setw(12) << "Expected" 
         << "Status\n";
    cout << string(52, '-') << "\n";

    runTest(1, 3, 3, 17);
    runTest(2, 1, 10, 10);
    runTest(3, 2, 3, 7); // [1,1],[1,2],[1,3],[2,1],[2,2],[3,1],[3,3]
    runTest(4, 5, 1, 1);  // only [1,1,1,1,1]
    runTest(5, 11, 11, 157014051); // Max constraints
    runTest(6, 1, 1, 1);

    cout << "⇚ - ======================================================= - ⇛\n";
    cout << "                         🎉 All Tests Executed!                         \n\n";

    return 0;
}
