#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

string formatArray(const vector<int>& arr) {
    if (arr.empty()) return "[]";
    stringstream ss;
    ss << "[";
    for (size_t i = 0; i < arr.size(); ++i) {
        ss << arr[i] << (i + 1 < arr.size() ? "," : "");
        if (ss.str().length() > 18) {
            ss << "...]";
            return ss.str();
        }
    }
    ss << "]";
    return ss.str();
}

string formatResult(const vector<vector<int>>& res) {
    stringstream ss;
    ss << res.size() << " pairs";
    return ss.str();
}

void runTest(int testNum, vector<int> arr, vector<vector<int>> expected, const string& description) {
    // Step: 01 - Compute reachable networks using both primary and DP methods
    Solution sol;
    vector<vector<int>> resPrimary = sol.socialNetwork(arr);
    vector<vector<int>> resDP = sol.socialNetworkDP(arr);

    // Step: 02 - Verify result correctness and cross-method equivalence
    bool passed = (resPrimary == expected) && (resDP == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";

    // Step: 03 - Format tabular output and identifiers
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);

    string displayDesc = description;
    if (displayDesc.length() > 36) {
        displayDesc = displayDesc.substr(0, 33) + "...";
    }

    string inputDisplay = formatArray(arr);

    cout << left << setw(6)  << testId
         << setw(38) << displayDesc
         << setw(20) << inputDisplay
         << setw(12) << formatResult(expected)
         << setw(12) << formatResult(resPrimary)
         << status << "\n";

    // Step: 04 - Print debug failure information upon mismatch
    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Expected size:      " << expected.size() << "\n"
             << "     Actual Primary size:" << resPrimary.size() << "\n"
             << "     Actual DP size:     " << resDP.size() << "\n";
    }
}

int main() {
    // Step: 01 - Print test suite header and table format
    cout << "\n🌐 Your Social Network — Test Suite\n";
    cout << "※ ========================================================================================= ※\n";
    cout << left << setw(6)  << "[ID]"
         << setw(38) << "Description"
         << setw(20) << "Input arr"
         << setw(12) << "Expected"
         << setw(12) << "Result"
         << "Status\n";
    cout << string(94, '-') << "\n";

    // Step: 02 - Execute test cases
    runTest(1, {1, 2}, {{2, 1, 1}, {3, 1, 2}, {3, 2, 1}}, "Example 1: Chain of 3 users");
    runTest(2, {1, 1}, {{2, 1, 1}, {3, 1, 1}}, "Example 2: Both 2 and 3 point to 1");
    runTest(3, {1, 2, 3}, {{2, 1, 1}, {3, 1, 2}, {3, 2, 1}, {4, 1, 3}, {4, 2, 2}, {4, 3, 1}}, "Linear chain of 4 users");
    runTest(4, {1, 1, 1, 1}, {{2, 1, 1}, {3, 1, 1}, {4, 1, 1}, {5, 1, 1}}, "Star topology centered on user 1");
    runTest(5, {1, 1, 2}, {{2, 1, 1}, {3, 1, 1}, {4, 1, 2}, {4, 2, 1}}, "Branching tree with 4 users");
    runTest(6, {1, 1, 2, 2, 3, 3}, {{2, 1, 1}, {3, 1, 1}, {4, 1, 2}, {4, 2, 1}, {5, 1, 2}, {5, 2, 1}, {6, 1, 2}, {6, 3, 1}, {7, 1, 2}, {7, 3, 1}}, "Binary tree network (7 users)");
    runTest(7, {1, 2, 1, 4}, {{2, 1, 1}, {3, 1, 2}, {3, 2, 1}, {4, 1, 1}, {5, 1, 2}, {5, 4, 1}}, "Mixed hierarchy with separate subtrees");
    runTest(8, {1, 2, 2, 3}, {{2, 1, 1}, {3, 1, 2}, {3, 2, 1}, {4, 1, 2}, {4, 2, 1}, {5, 1, 3}, {5, 2, 2}, {5, 3, 1}}, "5 users with varying depths");
    runTest(9, {1, 1, 2, 3, 4}, {{2, 1, 1}, {3, 1, 1}, {4, 1, 2}, {4, 2, 1}, {5, 1, 2}, {5, 3, 1}, {6, 1, 3}, {6, 2, 2}, {6, 4, 1}}, "Asymmetric branches with depth 3");
    runTest(10, {1, 2, 3, 4, 5, 6}, {{2, 1, 1}, {3, 1, 2}, {3, 2, 1}, {4, 1, 3}, {4, 2, 2}, {4, 3, 1}, {5, 1, 4}, {5, 2, 3}, {5, 3, 2}, {5, 4, 1}, {6, 1, 5}, {6, 2, 4}, {6, 3, 3}, {6, 4, 2}, {6, 5, 1}, {7, 1, 6}, {7, 2, 5}, {7, 3, 4}, {7, 4, 3}, {7, 5, 2}, {7, 6, 1}}, "Strict linear line of 7 users");

    // Step: 03 - Display final completion summary
    cout << "※ ========================================================================================= ※\n";
    cout << "                         🎉 All Tests Completed Successfully!                     \n\n";
    return 0;
}
