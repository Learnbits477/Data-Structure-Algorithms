#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

void runTest(int testNum, int n, vector<int>& ladVec, vector<int>& snVec, int expected) {
    Solution sol;
    int result = sol.minThrows(n, ladVec, snVec);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";
    
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);
    
    cout << left << setw(6)  << testId 
         << setw(10) << to_string(n)
         << setw(12) << to_string(ladVec.size() / 2)
         << setw(10) << to_string(snVec.size() / 2)
         << setw(10) << to_string(result)
         << status << "\n";
         
    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Expected: " << expected << "\n"
             << "     Got:      " << result << "\n";
    }
}

int main() {
    cout << "\n🎲 Snake and Ladder Problem — Test Suite\n";
    cout << "※ ========================================================== ※\n";
    cout << left << setw(6)  << "[ID]" 
         << setw(10) << "n" 
         << setw(12) << "Ladders" 
         << setw(10) << "Snakes" 
         << setw(10) << "Result" 
         << "Status\n";
    cout << string(62, '-') << "\n";

    // Test 1: Example 1
    vector<int> lad1 = {3, 22, 5, 8, 11, 35, 20, 32};
    vector<int> sn1 = {17, 4, 19, 7, 34, 1, 21, 9};
    runTest(1, 6, lad1, sn1, 3);

    // Test 2: Example 2
    vector<int> lad2 = {2, 8};
    vector<int> sn2 = {7, 3};
    runTest(2, 3, lad2, sn2, 2);

    // Test 3: Unreachable target due to snake trap
    vector<int> lad3 = {};
    vector<int> sn3 = {2, 1, 3, 1, 4, 1, 5, 1, 6, 1, 7, 1};
    runTest(3, 4, lad3, sn3, -1);

    // Test 4: One huge ladder to victory
    vector<int> lad4 = {2, 99};
    vector<int> sn4 = {};
    runTest(4, 10, lad4, sn4, 2);

    // Test 5: Plain board without any snakes or ladders
    vector<int> lad5 = {};
    vector<int> sn5 = {};
    runTest(5, 5, lad5, sn5, 4);

    cout << "※ ========================================================== ※\n";
    cout << "                  🎉 All Tests Executed!             \n\n";

    return 0;
}
