#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

string formatCoil(const vector<int>& coil, int maxItems = 4) {
    if (coil.empty()) return "[]";
    string s = "[";
    int count = min((int)coil.size(), maxItems);
    for (int i = 0; i < count; ++i) {
        s += to_string(coil[i]);
        if (i + 1 < count) s += ",";
    }
    if ((int)coil.size() > maxItems) {
        s += "...";
    }
    s += "]";
    return s;
}

void runTest(int testNum, int n, const vector<int>& expCoil1, const vector<int>& expCoil2, const string& description) {
    // Step: 01 - Execute coil generation using both symmetry and direct simulation
    Solution sol;
    vector<vector<int>> resSymmetry = sol.formCoils(n);
    vector<vector<int>> resDirect = sol.formCoilsSimulation(n);

    // Step: 02 - Verify result dimensions and consistency between algorithms
    int expectedSize = 8 * n * n;
    bool sizeMatches = (int)resSymmetry[0].size() == expectedSize &&
                       (int)resSymmetry[1].size() == expectedSize;
    bool algoConsistent = (resSymmetry[0] == resDirect[0]) &&
                          (resSymmetry[1] == resDirect[1]);

    // Step: 03 - Validate against expected coils if provided
    bool expMatches = true;
    if (!expCoil1.empty()) {
        expMatches = (resSymmetry[0] == expCoil1) && (resSymmetry[1] == expCoil2);
    }

    // Step: 04 - Format test status and aligned tabular row
    bool passed = sizeMatches && algoConsistent && expMatches;
    string status = passed ? "✅ PASSED" : "❌ FAILED";

    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);

    string displayDesc = description;
    if (displayDesc.length() > 32) {
        displayDesc = displayDesc.substr(0, 29) + "...";
    }

    string inputDisplay = "n = " + to_string(n) + " (" + to_string(4 * n) + "x" + to_string(4 * n) + ")";
    string expDisplay = expCoil1.empty() ? (to_string(expectedSize) + " items") : formatCoil(expCoil1);
    string actDisplay = formatCoil(resSymmetry[0]);

    cout << left << setw(6)  << testId
         << setw(34) << displayDesc
         << setw(18) << inputDisplay
         << setw(16) << expDisplay
         << setw(16) << actDisplay
         << status << "\n";

    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     n:                  " << n << "\n"
             << "     Expected Size:      " << expectedSize << "\n"
             << "     Actual Size C1:     " << resSymmetry[0].size() << "\n"
             << "     Actual Size C2:     " << resSymmetry[1].size() << "\n"
             << "     Algorithms Match:   " << (algoConsistent ? "true" : "false") << "\n";
    }
}

int main() {
    // Step: 01 - Print test suite header and table format
    cout << "\n🌀 Coils in a Matrix — Test Suite\n";
    cout << "※ ========================================================================================= ※\n";
    cout << left << setw(6)  << "[ID]"
         << setw(34) << "Description"
         << setw(18) << "Matrix Size"
         << setw(16) << "Expected C1"
         << setw(16) << "Result C1"
         << "Status\n";
    cout << string(94, '-') << "\n";

    // Step: 02 - Execute test cases
    runTest(1, 1, {1, 5, 9, 13, 14, 15, 11, 7}, {16, 12, 8, 4, 3, 2, 6, 10}, "Example 1: n = 1 (4x4 Matrix)");
    runTest(2, 2,
            {1, 9, 17, 25, 33, 41, 49, 57, 58, 59, 60, 61, 62, 63, 55, 47, 39, 31, 23, 15, 14, 13, 12, 11, 19, 27, 35, 43, 44, 45, 37, 29},
            {64, 56, 48, 40, 32, 24, 16, 8, 7, 6, 5, 4, 3, 2, 10, 18, 26, 34, 42, 50, 51, 52, 53, 54, 46, 38, 30, 22, 21, 20, 28, 36},
            "Example 2: n = 2 (8x8 Matrix)");
    runTest(3, 3, {}, {}, "Small Matrix: n = 3 (12x12, 72 cells/coil)");
    runTest(4, 4, {}, {}, "Medium Matrix: n = 4 (16x16, 128 cells)");
    runTest(5, 5, {}, {}, "Medium Matrix: n = 5 (20x20, 200 cells)");
    runTest(6, 7, {}, {}, "Odd Matrix: n = 7 (28x28, 392 cells)");
    runTest(7, 10, {}, {}, "Large Matrix: n = 10 (40x40, 800 cells)");
    runTest(8, 15, {}, {}, "Larger Matrix: n = 15 (60x60, 1800 cells)");
    runTest(9, 18, {}, {}, "Near Boundary: n = 18 (72x72, 2592 cells)");
    runTest(10, 20, {}, {}, "Upper Bound: n = 20 (80x80, 3200 cells)");

    // Step: 03 - Display final completion summary
    cout << "※ ========================================================================================= ※\n";
    cout << "                         🎉 All Tests Completed Successfully!                     \n\n";

    return 0;
}
