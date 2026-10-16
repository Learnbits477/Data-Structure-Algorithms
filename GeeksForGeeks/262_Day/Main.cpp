#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

void runTest(int testNum, const vector<int>& arr, int expected, const string& description) {
    // Step: 01 - Execute primary and alternative implementations
    Solution sol;
    vector<int> arrCopy1 = arr;
    vector<int> arrCopy2 = arr;
    vector<int> arrCopy3 = arr;

    int resPrimary = sol.countAlwaysFound(arrCopy1);
    int resDual = sol.countAlwaysFoundPrefixSuffix(arrCopy2);
    int resFilter = sol.countAlwaysFoundFilter(arrCopy3);

    // Step: 02 - Validate outputs and agreement across implementations
    bool passed = (resPrimary == expected) && (resDual == expected) && (resFilter == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";

    // Step: 03 - Format tabular display columns
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);

    string displayDesc = description;
    if (displayDesc.length() > 42) {
        displayDesc = displayDesc.substr(0, 39) + "...";
    }

    stringstream ss;
    ss << "[";
    for (size_t i = 0; i < arr.size(); ++i) {
        ss << arr[i];
        if (i + 1 < arr.size()) ss << ",";
        if (ss.str().length() > 24) {
            ss << "...";
            break;
        }
    }
    ss << "]";
    string inputDisplay = ss.str();
    if (inputDisplay.length() > 26) {
        inputDisplay = inputDisplay.substr(0, 23) + "...]";
    }

    string expDisplay = to_string(expected);
    string resDisplay = to_string(resPrimary);

    cout << left << setw(6)  << testId
         << setw(44) << displayDesc
         << setw(28) << inputDisplay
         << setw(14) << expDisplay
         << setw(14) << resDisplay
         << status << "\n";

    // Step: 04 - Print debug failure details if mismatch occurs
    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Expected:  " << expected << "\n"
             << "     Primary:   " << resPrimary << "\n"
             << "     Dual:      " << resDual << "\n"
             << "     Filter:    " << resFilter << "\n";
    }
}

int main() {
    // Step: 01 - Print test suite header and table format
    cout << "\n🎯 Successful Binary Searches Irrespective of Pivot — Test Suite\n";
    cout << "※ ===================================================================================================================== ※\n";
    cout << left << setw(6)  << "[ID]"
         << setw(44) << "Description"
         << setw(28) << "Input"
         << setw(14) << "Expected"
         << setw(14) << "Result"
         << "Status\n";
    cout << string(118, '-') << "\n";

    // Step: 02 - Execute test cases
    runTest(1, {3, 7, 9, 8, 15}, 3, "Example 1: Indices 0, 1, 4 valid");
    runTest(2, {9, 4, 1, 10, 22, 23, 20}, 1, "Example 2: Only index 3 valid");
    runTest(3, {42}, 1, "Single element: Always found");
    runTest(4, {1, 2, 3, 4, 5}, 5, "Strictly sorted array: All found");
    runTest(5, {5, 4, 3, 2, 1}, 0, "Strictly reverse sorted: None found");
    runTest(6, {1, 3, 2}, 1, "Three elements: First valid");
    runTest(7, {2, 1, 3}, 1, "Three elements: Last valid");
    runTest(8, {5, 1, 4, 3, 6, 8, 7, 10}, 2, "Two partition points: 6 and 10");
    runTest(9, {2, 3, 4, 1, 8, 9, 10}, 3, "Prefix rotated: Last 3 elements valid");
    runTest(10, {1000000, 1, 500000}, 0, "High first element blocking all");
    runTest(11, {10, 20, 30, 40, 50, 60, 70, 80}, 8, "Eight elements strictly ascending");
    runTest(12, {5, 10, 8, 12, 14, 13, 20}, 3, "Mixed sequence: 5, 12, 20 valid");

    // Step: 03 - Display final completion summary
    cout << "※ ===================================================================================================================== ※\n";
    cout << "                                         🎉 All Tests Completed Successfully!                                         \n\n";
    return 0;
}
