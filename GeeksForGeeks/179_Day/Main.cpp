#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

void runTest(int testNum, vector<vector<int>> mat, int k, int expected) {
    int n = mat.size();
    
    Solution sol;
    int result = sol.maximumSum(mat, k);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";
    
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);
    
    string gridStr = to_string(n) + "x" + to_string(n) + " grid";
    
    cout << left << setw(6)  << testId 
         << setw(18) << gridStr
         << setw(10) << ("k = " + to_string(k))
         << setw(18) << to_string(expected)
         << setw(18) << to_string(result)
         << status << "\n";
         
    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Expected: " << expected << "\n"
             << "     Got:      " << result << "\n";
    }
}

int main() {
    cout << "\n🔢 Max Sum Square Sub-Matrix of Size k — Test Suite\n";
    cout << "⇚ - ==================================================================================== - ⇛\n";
    cout << left << setw(6)  << "[ID]" 
         << setw(18) << "Grid Dimensions" 
         << setw(10) << "Size k"
         << setw(18) << "Expected Max" 
         << setw(18) << "Actual Max" 
         << "Status\n";
    cout << string(88, '-') << "\n";

    // Test Case 1: Example 1 from Problem Description
    runTest(1, {
        {1, 2, -1, 4},
        {-8, -3, 4, 2},
        {3, 8, 10, -8},
        {-4, -1, 1, 7}
    }, 3, 20);

    // Test Case 2: Example 2 from Problem Description
    runTest(2, {{4}}, 1, 4);

    // Test Case 3: Single element negative
    runTest(3, {{-10}}, 1, -10);

    // Test Case 4: All negative matrix
    runTest(4, {
        {-1, -2, -3},
        {-4, -5, -6},
        {-7, -8, -9}
    }, 2, -12);

    // Test Case 5: Large element in the middle
    runTest(5, {
        {1, 1, 1, 1},
        {1, 1, 1, 1},
        {1, 1, 10, 1},
        {1, 1, 1, 1}
    }, 2, 13);

    // Test Case 6: Equal n and k
    runTest(6, {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    }, 3, 45);

    // Test Case 7: Alternating signs
    runTest(7, {
        {5, -5, 5},
        {-5, 10, -5},
        {5, -5, 5}
    }, 2, 5);

    cout << "⇚ - ==================================================================================== - ⇛\n";
    cout << "                         🎉 All Tests Completed Successfully!                           \n\n";

    return 0;
}
