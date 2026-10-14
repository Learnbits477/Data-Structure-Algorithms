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

void runTest(int testNum, string s, vector<int> roll, const string& expected, const string& description) {
    // Step: 01 - Execute primary forward difference and alternative suffix solvers
    Solution sol;
    string sPrimary = s;
    string resPrimary = sol.findRollOut(sPrimary, roll);
    string resSuffix = sol.findRollOutSuffix(s, roll);

    // Step: 02 - Verify result correctness and cross-algorithm agreement
    bool passed = (resPrimary == expected) && (resSuffix == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";

    // Step: 03 - Format tabular display columns
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);

    string displayDesc = description;
    if (displayDesc.length() > 38) {
        displayDesc = displayDesc.substr(0, 35) + "...";
    }

    stringstream inputSs;
    inputSs << "\"" << s << "\", " << formatArray(roll);
    string inputDisplay = inputSs.str();
    if (inputDisplay.length() > 28) {
        inputDisplay = inputDisplay.substr(0, 25) + "...]";
    }

    string expDisplay = "\"" + expected + "\"";
    string resDisplay = "\"" + resPrimary + "\"";

    cout << left << setw(6)  << testId
         << setw(40) << displayDesc
         << setw(30) << inputDisplay
         << setw(16) << expDisplay
         << setw(16) << resDisplay
         << status << "\n";

    // Step: 04 - Print debug details on failure
    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Expected:  \"" << expected << "\"\n"
             << "     Primary:   \"" << resPrimary << "\"\n"
             << "     Suffix:    \"" << resSuffix << "\"\n";
    }
}

int main() {
    // Step: 01 - Print test suite header and table format
    cout << "\n🎯 Roll Characters of String — Test Suite\n";
    cout << "※ ===================================================================================================================== ※\n";
    cout << left << setw(6)  << "[ID]"
         << setw(40) << "Description"
         << setw(30) << "Input"
         << setw(16) << "Expected"
         << setw(16) << "Result"
         << "Status\n";
    cout << string(118, '-') << "\n";

    // Step: 02 - Execute test cases
    runTest(1, "bca", {1, 2, 3}, "eeb", "Example 1: Sequential roll 1, 2, 3");
    runTest(2, "zcza", {1, 1, 3, 4}, "debb", "Example 2: Repeated rolls with wraps");
    runTest(3, "a", {1}, "b", "Single character single roll");
    runTest(4, "z", {1}, "a", "Single character wrap-around z to a");
    runTest(5, "a", vector<int>(26, 1), "a", "Full 26 alphabet circular cycle");
    runTest(6, "abcdef", {6}, "bcdefg", "Full length roll by 1");
    runTest(7, "abcdef", {1, 1, 1}, "dbcdef", "Multiple rolls on first char");
    runTest(8, "zzz", {3, 3}, "bbb", "Multiple full rolls with wraps");
    runTest(9, "hello", {5, 3, 1}, "kgnmp", "Staggered descending rolls");
    runTest(10, "wxyz", {4, 4, 4}, "zabc", "Multiple characters wrapping across z");
    runTest(11, "abc", {}, "abc", "Empty roll array no changes");
    runTest(12, "banana", {2, 4, 6}, "edpcob", "Prefix rolls on repeated letters");

    // Step: 03 - Display final completion summary
    cout << "※ ===================================================================================================================== ※\n";
    cout << "                                         🎉 All Tests Completed Successfully!                                         \n\n";
    return 0;
}
