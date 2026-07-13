#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <numeric>
using namespace std;

void runTest(int testNum, vector<int> b, int expected) {
    Solution sol;
    
    vector<int> originalB = b;
    
    int result = sol.minOperations(b);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";
    
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);
    
    string bStr = "[";
    for (size_t i = 0; i < originalB.size(); ++i) {
        bStr += to_string(originalB[i]);
        if (i != originalB.size() - 1) bStr += ", ";
    }
    bStr += "]";
    
    string inputStr = "b = " + bStr;
    if (inputStr.length() > 45) {
        inputStr = inputStr.substr(0, 42) + "...";
    }
    
    cout << left << setw(6)  << testId 
         << setw(45) << inputStr
         << setw(12) << expected
         << setw(12) << result
         << status << "\n";
         
    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Expected: " << expected << "\n"
             << "     Got:      " << result << "\n";
    }
}

int main() {
    cout << "\n";
    cout << "  🚀 GeeksforGeeks Day 167 - Rearrange the Array Test Suite  \n";
    cout << "⇚ - ===================================================================================== - ⇛\n";
    cout << left << setw(6)  << "[ID]" 
         << setw(45) << "Input Parameters (b[])" 
         << setw(12) << "Expected" 
         << setw(12) << "Actual" 
         << "Status\n";
    cout << string(90, '-') << "\n";

    // Test Case 1: Example 1 from GFG description
    // b[] = [1, 2, 3] -> Expected: 1
    runTest(1, {1, 2, 3}, 1);

    // Test Case 2: Example 2 from GFG description
    // b[] = [2, 3, 1, 5, 4] -> Expected: 6
    runTest(2, {2, 3, 1, 5, 4}, 6);

    // Test Case 3: Identity Permutation of larger size
    // b[] = [1, 2, 3, 4, 5, 6, 7] -> Expected: 1
    runTest(3, {1, 2, 3, 4, 5, 6, 7}, 1);

    // Test Case 4: Single Large Cycle of size 5
    // b[] = [2, 3, 4, 5, 1] -> Expected: 5
    runTest(4, {2, 3, 4, 5, 1}, 5);

    // Test Case 5: Disjoint cycles with lengths 3 and 4
    // b[] = [2, 3, 1, 5, 6, 7, 4] -> Expected: 12
    runTest(5, {2, 3, 1, 5, 6, 7, 4}, 12);

    // Test Case 6: Multiple small cycles (lengths 2, 2, 2)
    // b[] = [2, 1, 4, 3, 6, 5] -> Expected: 2
    runTest(6, {2, 1, 4, 3, 6, 5}, 2);

    cout << "⇚ - ===================================================================================== - ⇛\n";
    cout << "                         🎉 All Tests Completed Successfully!                           \n";

    return 0;
}
