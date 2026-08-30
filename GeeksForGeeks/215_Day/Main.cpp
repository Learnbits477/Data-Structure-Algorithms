#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

string formatVector(const vector<int>& v, int maxItems = 5) {
    ostringstream oss;
    oss << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        if (static_cast<int>(i) >= maxItems) {
            oss << "...";
            break;
        }
        oss << v[i];
        if (i + 1 < v.size() && static_cast<int>(i + 1) < maxItems) {
            oss << ",";
        }
    }
    oss << "]";
    return oss.str();
}

void runTest(int testNum, vector<int> l, vector<int> r, vector<int> rank, vector<int> expected) {
    Solution sol;
    vector<int> result = sol.getMarks(l, r, rank);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";

    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);

    cout << left << setw(6)  << testId
         << setw(16) << formatVector(l)
         << setw(16) << formatVector(r)
         << setw(18) << formatVector(rank)
         << setw(18) << formatVector(result)
         << setw(18) << formatVector(expected)
         << status << "\n";

    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Input l:    " << formatVector(l, 100) << "\n"
             << "     Input r:    " << formatVector(r, 100) << "\n"
             << "     Input rank: " << formatVector(rank, 100) << "\n"
             << "     Expected:   " << formatVector(expected, 100) << "\n"
             << "     Got:        " << formatVector(result, 100) << "\n";
    }
}

int main() {
    cout << "\n🎯 Marks from Ranks — Test Suite\n";
    cout << "※ ============================================================================================== ※\n";
    cout << left << setw(6)  << "[ID]"
         << setw(16) << "l[]"
         << setw(16) << "r[]"
         << setw(18) << "rank[]"
         << setw(18) << "Result"
         << setw(18) << "Expected"
         << "Status\n";
    cout << string(96, '-') << "\n";

    // Test 1: Example 1 from problem description
    runTest(1, {1, 6, 14}, {3, 9, 15}, {2, 5, 8}, {2, 7, 14});

    // Test 2: Example 2 from problem description
    runTest(2, {5, 10}, {7, 12}, {1, 4, 6}, {5, 10, 12});

    // Test 3: Single interval
    runTest(3, {10}, {20}, {1, 5, 11}, {10, 14, 20});

    // Test 4: Single point intervals
    runTest(4, {2, 5, 8}, {2, 5, 8}, {1, 2, 3}, {2, 5, 8});

    // Test 5: First and last rank of every interval
    runTest(5, {1, 10, 20}, {5, 15, 25}, {1, 5, 6, 11, 12, 17}, {1, 5, 10, 15, 20, 25});

    // Test 6: Queries with single rank
    runTest(6, {100, 200}, {105, 205}, {7}, {200});

    // Test 7: Intervals with large mark gaps
    runTest(7, {10, 1000}, {12, 1002}, {1, 3, 4, 6}, {10, 12, 1000, 1002});

    // Test 8: Multiple queries pointing to the same interval
    runTest(8, {1, 10}, {4, 15}, {2, 3, 4}, {2, 3, 4});

    cout << "※ ============================================================================================== ※\n";
    cout << "                             🎉 All Tests Executed!                               \n\n";

    return 0;
}
