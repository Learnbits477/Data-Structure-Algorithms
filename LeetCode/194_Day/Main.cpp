#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

void runTest(int testNum, const vector<int>& piles, int expected) {
    Solution sol;
    auto pilesCopy = piles;
    int result = sol.stoneGameII(pilesCopy);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";
    
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);
    
    string sizeStr = to_string(piles.size()) + " piles";
    
    cout << left << setw(6)  << testId 
         << setw(15) << sizeStr
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
    cout << "\n💎 Stone Game II — Test Suite\n";
    cout << "⇚ - ================================================================ - ⇛\n";
    cout << left << setw(6)  << "[ID]" 
         << setw(15) << "Piles Count" 
         << setw(12) << "Result" 
         << setw(12) << "Expected" 
         << "Status\n";
    cout << string(65, '-') << "\n";

    // Test 1: Example 1
    runTest(1, {2, 7, 9, 4, 4}, 10);

    // Test 2: Example 2
    runTest(2, {1, 2, 3, 4, 5, 100}, 104);

    // Test 3: Single pile case
    runTest(3, {5}, 5);

    // Test 4: Two piles case
    runTest(4, {3, 8}, 11);

    // Test 5: Standard test case with alternating sizes
    runTest(5, {1, 100, 1}, 101);

    cout << "⇚ - ================================================================ - ⇛\n";
    cout << "                         🎉 All Tests Executed!                         \n\n";

    return 0;
}
