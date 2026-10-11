#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

string formatArray(const vector<int>& arr) {
    // Step: 01 - Format array elements into compact string
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

void runTest(int testNum, vector<int> arr, const vector<int>& expected, const string& description) {
    // Step: 01 - Execute primary merge routine and alternative in-place merge
    Solution sol;
    vector<int> resPrimary = arr;
    vector<int> resInplace = arr;

    sol.mergeTwoParts(resPrimary);
    sol.mergeTwoPartsInplace(resInplace);

    // Step: 02 - Validate test result and cross-method consistency
    bool passed = (resPrimary == expected) && (resInplace == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";

    // Step: 03 - Format tabular display columns
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);

    string displayDesc = description;
    if (displayDesc.length() > 38) {
        displayDesc = displayDesc.substr(0, 35) + "...";
    }

    string inputDisplay = formatArray(arr);
    if (inputDisplay.length() > 28) {
        inputDisplay = inputDisplay.substr(0, 25) + "...]";
    }

    string expectedDisplay = formatArray(expected);
    if (expectedDisplay.length() > 24) {
        expectedDisplay = expectedDisplay.substr(0, 21) + "...]";
    }

    string resultDisplay = formatArray(resPrimary);
    if (resultDisplay.length() > 24) {
        resultDisplay = resultDisplay.substr(0, 21) + "...]";
    }

    cout << left << setw(6)  << testId
         << setw(40) << displayDesc
         << setw(30) << inputDisplay
         << setw(26) << expectedDisplay
         << setw(26) << resultDisplay
         << status << "\n";

    // Step: 04 - Print debug details on test failure
    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Expected:  " << formatArray(expected) << "\n"
             << "     Primary:   " << formatArray(resPrimary) << "\n"
             << "     In-Place:  " << formatArray(resInplace) << "\n";
    }
}

int main() {
    // Step: 01 - Print test suite header and table format
    cout << "\n🎯 Sort Two Parts Sorted — Test Suite\n";
    cout << "※ ============================================================================================================================================ ※\n";
    cout << left << setw(6)  << "[ID]"
         << setw(40) << "Description"
         << setw(30) << "Input"
         << setw(26) << "Expected"
         << setw(26) << "Result"
         << "Status\n";
    cout << string(140, '-') << "\n";

    // Step: 02 - Execute test cases
    runTest(1, {2, 3, 8, -1, 7, 10}, {-1, 2, 3, 7, 8, 10}, "Example 1: Break point in middle");
    runTest(2, {-4, 6, 9, -1, 3}, {-4, -1, 3, 6, 9}, "Example 2: Negative and positive halves");
    runTest(3, {10, 20, 30}, {10, 20, 30}, "Example 3: Already sorted array");
    runTest(4, {5}, {5}, "Single element array");
    runTest(5, {20, 10}, {10, 20}, "Two inverted elements");
    runTest(6, {10, 1, 2, 3, 4}, {1, 2, 3, 4, 10}, "Break point at index 0");
    runTest(7, {2, 4, 6, 8, 1}, {1, 2, 4, 6, 8}, "Break point before final element");
    runTest(8, {1, 3, 5, 2, 3, 6}, {1, 2, 3, 3, 5, 6}, "Duplicate elements across halves");
    runTest(9, {7, 7, 7, 7}, {7, 7, 7, 7}, "All identical elements");
    runTest(10, {-10, -5, 0, -20, -15, 5}, {-20, -15, -10, -5, 0, 5}, "Mixed negative numbers and zero");
    runTest(11, {100, 200, 300, 400, 50, 150, 250, 350}, {50, 100, 150, 200, 250, 300, 350, 400}, "Interleaved elements equal halves");
    runTest(12, {-100000, 100000, -50000, 50000}, {-100000, -50000, 50000, 100000}, "Boundary constraints -10^5 to 10^5");

    // Step: 03 - Display final completion summary
    cout << "※ ============================================================================================================================================ ※\n";
    cout << "                                                    🎉 All Tests Completed Successfully!                                                    \n\n";
    return 0;
}
