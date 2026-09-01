#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

void runTest(int testNum, vector<string> classroom, int energy, int expected) {
    Solution sol;
    int result = sol.minMoves(classroom, energy);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";

    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);

    cout << left << setw(6)  << testId
         << setw(10) << (to_string(classroom.size()) + "x" + to_string(classroom[0].size()))
         << setw(10) << energy
         << setw(12) << result
         << setw(12) << expected
         << status << "\n";

    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Grid:\n";
        for (const auto& row : classroom) {
            cout << "       " << row << "\n";
        }
        cout << "     Energy:   " << energy << "\n"
             << "     Expected: " << expected << "\n"
             << "     Got:      " << result << "\n";
    }
}

int main() {
    cout << "\n🎯 3568. Minimum Moves to Clean the Classroom — Test Suite\n";
    cout << "※ ========================================================================= ※\n";
    cout << left << setw(6)  << "[ID]"
         << setw(10) << "Grid"
         << setw(10) << "Energy"
         << setw(12) << "Result"
         << setw(12) << "Expected"
         << "Status\n";
    cout << string(65, '-') << "\n";

    // Test 1: Example 1 from problem description
    runTest(1, {"S.", "XL"}, 2, 2);

    // Test 2: Example 2 from problem description
    runTest(2, {"LS", "RL"}, 4, 3);

    // Test 3: Example 3 from problem description (Impossible due to energy/obstacles)
    runTest(3, {"L.S", "RXL"}, 3, -1);

    // Test 4: Single cell start with no litter
    runTest(4, {"S"}, 5, 0);

    // Test 5: Immediate neighbor litter
    runTest(5, {"SL"}, 1, 1);

    // Test 6: Requires using Reset area multiple times
    // S . R . L
    // energy = 2
    // S(0) -> .(1) -> R(2, energy resets to 2) -> .(3) -> L(4) = 4 moves
    runTest(6, {"S.R.L"}, 2, 4);

    // Test 7: Complex grid with multiple litters and reset stations
    // Path: S(0,0) -> (0,1) -> (0,2) -> (0,3)[L] -> (1,3)[R] -> (2,3)[L] -> (2,2) -> (2,1) -> (2,0)[L] = 8 moves
    runTest(7, {
        "S..L",
        ".X.R",
        "L..L"
    }, 4, 8);

    // Test 8: Path around obstacle through reset station
    // S(0,0) -> (1,0) -> (2,0)[R] -> (2,1) -> (2,2) -> (1,2)[L] = 5 moves
    runTest(8, {
        "S.X",
        ".XL",
        "R.."
    }, 5, 5);

    // Test 9: Truly unreachable litter (completely surrounded by obstacles)
    runTest(9, {
        "S..",
        "XXX",
        "L.."
    }, 5, -1);

    cout << "※ ========================================================================= ※\n";
    cout << "                             🎉 All Tests Executed!                               \n\n";

    return 0;
}
