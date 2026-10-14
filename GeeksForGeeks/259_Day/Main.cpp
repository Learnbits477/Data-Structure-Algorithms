#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

string formatArray(const vector<int>& arr) {
    // Step: 01 - Format vector into compact bracketed string representation
    stringstream ss;
    ss << "[";
    for (size_t i = 0; i < arr.size(); i++) {
        ss << arr[i];
        if (i + 1 < arr.size()) {
            ss << ", ";
        }
    }
    ss << "]";
    return ss.str();
}

void runTest(int testNum, int n, vector<int> updates, vector<int> expected, const string& description) {
    // Step: 01 - Execute primary vector and alternative running sum methods
    Solution sol;
    vector<int> updatesCopy = updates;
    vector<int> resPrimary = sol.update(n, updates);
    vector<int> resAlternative = sol.updateRunningSum(n, updatesCopy);

    // Step: 02 - Also verify raw array in-place pointer overload
    vector<int> rawArr(n, 0);
    sol.update(rawArr.data(), n, updatesCopy.data(), static_cast<int>(updatesCopy.size()));

    // Step: 03 - Check validity and agreement across all three execution paths
    bool passed = (resPrimary == expected) && (resAlternative == expected) && (rawArr == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";

    // Step: 04 - Format tabular display columns
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);

    string displayDesc = description;
    if (displayDesc.length() > 36) {
        displayDesc = displayDesc.substr(0, 33) + "...";
    }

    stringstream inputSs;
    inputSs << "n=" << n << ", up=" << formatArray(updates);
    string inputDisplay = inputSs.str();
    if (inputDisplay.length() > 26) {
        inputDisplay = inputDisplay.substr(0, 23) + "...]";
    }

    string expDisplay = formatArray(expected);
    if (expDisplay.length() > 18) {
        expDisplay = expDisplay.substr(0, 15) + "...]";
    }

    string resDisplay = formatArray(resPrimary);
    if (resDisplay.length() > 18) {
        resDisplay = resDisplay.substr(0, 15) + "...]";
    }

    cout << left << setw(6)  << testId
         << setw(38) << displayDesc
         << setw(28) << inputDisplay
         << setw(20) << expDisplay
         << setw(20) << resDisplay
         << status << "\n";

    // Step: 05 - Print debug details on failure
    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Expected:    " << formatArray(expected) << "\n"
             << "     Primary:     " << formatArray(resPrimary) << "\n"
             << "     Alternative: " << formatArray(resAlternative) << "\n"
             << "     Raw Array:   " << formatArray(rawArr) << "\n";
    }
}

int main() {
    // Step: 01 - Print test suite header and table format
    cout << "\n🎯 Adding Ones — Test Suite\n";
    cout << "※ ========================================================================================================================= ※\n";
    cout << left << setw(6)  << "[ID]"
         << setw(38) << "Description"
         << setw(28) << "Input"
         << setw(20) << "Expected"
         << setw(20) << "Result"
         << "Status\n";
    cout << string(120, '-') << "\n";

    // Step: 02 - Execute test cases
    runTest(1, 3, {1, 1, 2, 3}, {2, 3, 4}, "Example 1: Multiple updates n=3");
    runTest(2, 2, {1, 1, 1}, {3, 3}, "Example 2: All updates at start n=2");
    runTest(3, 1, {1}, {1}, "Single element single update");
    runTest(4, 1, {1, 1, 1, 1, 1}, {5}, "Single element five updates");
    runTest(5, 5, {5, 5}, {0, 0, 0, 0, 2}, "All updates at last element");
    runTest(6, 4, {1, 1}, {2, 2, 2, 2}, "All updates at first index");
    runTest(7, 5, {2, 4}, {0, 1, 1, 2, 2}, "Two spaced updates");
    runTest(8, 4, {4, 3, 2, 1}, {1, 2, 3, 4}, "Reverse staircase updates");
    runTest(9, 6, {1, 3, 2, 5, 2, 4}, {1, 3, 4, 5, 6, 6}, "Staggered unordered updates");
    runTest(10, 8, {3, 6, 8}, {0, 0, 1, 1, 1, 2, 2, 3}, "Spaced sparse updates n=8");
    runTest(11, 4, {}, {0, 0, 0, 0}, "Empty updates vector");
    runTest(12, 7, {1, 2, 3, 4, 5, 6, 7}, {1, 2, 3, 4, 5, 6, 7}, "Sequential diagonal updates");

    // Step: 03 - Display final completion summary
    cout << "※ ========================================================================================================================= ※\n";
    cout << "                                         🎉 All Tests Completed Successfully!                                         \n\n";
    return 0;
}
