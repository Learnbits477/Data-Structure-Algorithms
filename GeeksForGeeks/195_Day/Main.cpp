#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

void runTest(int testNum, const vector<int>& h, const vector<int>& l, int expected) {
    Solution sol;
    auto hCopy = h;
    auto lCopy = l;
    int n = h.size();
    int result = sol.maxTasks(n, hCopy, lCopy);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";
    
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);
    
    cout << left << setw(6)  << testId 
         << setw(10) << to_string(n)
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
    cout << "\n🔢 High Effort vs Low Effort — Test Suite\n";
    cout << "⇚ - ============================================== - ⇛\n";
    cout << left << setw(6)  << "[ID]" 
         << setw(10) << "Days (N)" 
         << setw(12) << "Result" 
         << setw(12) << "Expected" 
         << "Status\n";
    cout << string(52, '-') << "\n";

    // Test 1: Example 1
    runTest(1, {2, 8, 1}, {1, 2, 1}, 9);

    // Test 2: Example 2
    runTest(2, {3, 6, 8, 7, 6}, {1, 5, 4, 5, 3}, 20);

    // Test 3: Trivial case (n = 1)
    runTest(3, {5}, {2}, 5);

    // Test 4: Low effort always better
    runTest(4, {1, 1, 1}, {3, 3, 3}, 9);

    // Test 5: High effort always better
    runTest(5, {10, 1, 10, 1, 10}, {2, 2, 2, 2, 2}, 30);

    // Test 6: Mixed inputs
    runTest(6, {5, 8, 2, 9, 10, 3}, {3, 4, 1, 2, 5, 2}, 25);

    cout << "⇚ - ============================================== - ⇛\n";
    cout << "                         🎉 All Tests Executed!                         \n\n";

    return 0;
}
