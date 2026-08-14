#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

string formatBool(int val) {
    return val ? "true" : "false";
}

// Test runner function
void runTest(int testNum, long long s, vector<long long> arr, long long x, int expected) {
    Solution sol;
    int result = sol.isPossible(s, arr, x);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";
    
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);
    
    cout << left << setw(6)  << testId 
         << setw(12) << to_string(s)
         << setw(12) << to_string(x)
         << setw(10) << formatBool(result)
         << status << "\n";
         
    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Expected: " << formatBool(expected) << "\n"
             << "     Got:      " << formatBool(result) << "\n";
    }
}

int main() {
    cout << "\n🔢 Tricky Subset Problem — Test Suite\n";
    cout << "========================================================\n";
    cout << left << setw(6)  << "[ID]" 
         << setw(12) << "Initial s" 
         << setw(12) << "Target x" 
         << setw(10) << "Result" 
         << "Status\n";
    cout << string(50, '-') << "\n";

    // Test 1: Example 1
    runTest(1, 1, {1, 2, 4, 2}, 7, 1);

    // Test 2: Example 2
    runTest(2, 100, {51, 88}, 500, 0);

    // Test 3: Single element target equal to s
    runTest(3, 5, {1, 2, 3}, 5, 1);

    // Test 4: Single element target equal to paper sequence term
    runTest(4, 10, {10}, 20, 1);

    // Test 5: Large values
    runTest(5, 1000000000LL, {1000000000LL}, 3000000000LL, 1);

    // Test 6: Impossible target
    runTest(6, 1, {1, 2, 4}, 100, 0);

    cout << "========================================================\n";
    cout << "          🎉 All Tests Executed!             \n\n";

    return 0;
}
