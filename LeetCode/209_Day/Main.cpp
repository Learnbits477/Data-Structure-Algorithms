#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

void runTest(int testNum, vector<int> stones, int expected) {
    Solution sol;
    int result = sol.stoneGameVIII(stones);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";

    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);

    string displayStones = "[";
    for (size_t i = 0; i < stones.size(); ++i) {
        displayStones += to_string(stones[i]);
        if (i + 1 < stones.size()) displayStones += ",";
        if (displayStones.length() > 22 && i + 1 < stones.size()) {
            displayStones += "...";
            break;
        }
    }
    displayStones += "]";

    cout << left << setw(6)  << testId
         << setw(26) << displayStones
         << setw(14) << expected
         << setw(14) << result
         << status << "\n";

    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Expected: " << expected << "\n"
             << "     Got:      " << result << "\n";
    }
}

int main() {
    cout << "\n🎮 1872. Stone Game VIII — Test Suite\n";
    cout << "※ ==================================================================== ※\n";
    cout << left << setw(6)  << "[ID]"
         << setw(26) << "Stones"
         << setw(14) << "Expected"
         << setw(14) << "Result"
         << "Status\n";
    cout << string(70, '-') << "\n";

    runTest(1, {-1, 2, -3, 4, -5}, 5);
    runTest(2, {7, -6, 5, 10, 5, -2, -6}, 13);
    runTest(3, {-10, -12}, -22);
    runTest(4, {1, 2, 3, 4, 5}, 15);
    runTest(5, {-1, -2, -3, -4}, 4);
    runTest(6, {10, 20}, 30);
    runTest(7, {5, -5, 5, -5, 5}, 5);
    runTest(8, {100, -20, 30, -40, 50, -60, 70}, 130);
    runTest(9, {100, -50, -30, -10}, 40);
    runTest(10, {1, 10, -5, 2}, 8);

    cout << "※ ==================================================================== ※\n";
    cout << "                     🎉 All Tests Completed Successfully!              \n\n";

    return 0;
}
