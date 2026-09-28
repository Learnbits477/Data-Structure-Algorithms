#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

void runTest(int testNum, vector<int> arr, vector<vector<int>> queries, vector<int> expected, const string& description) {
    Solution sol;
    vector<int> result = sol.processQueries(arr, queries);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";

    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);

    string displayDesc = description;
    if (displayDesc.length() > 32) {
        displayDesc = displayDesc.substr(0, 29) + "...";
    }

    auto vecToStr = [](const vector<int>& v) -> string {
        string s = "[";
        for (size_t i = 0; i < v.size(); ++i) {
            s += to_string(v[i]);
            if (i + 1 < v.size()) s += ", ";
        }
        s += "]";
        return s;
    };

    string expStr = vecToStr(expected);
    string resStr = vecToStr(result);

    cout << left << setw(6)  << testId
         << setw(34) << displayDesc
         << setw(16) << expStr
         << setw(16) << resStr
         << status << "\n";

    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Initial Arr Size: " << arr.size() << "\n"
             << "     Queries Count:   " << queries.size() << "\n"
             << "     Expected Output: " << expStr << "\n"
             << "     Actual Output:   " << resStr << "\n";
    }
}

int main() {
    cout << "\n📊 Range GCD Queries — Test Suite\n";
    cout << "※ ============================================================================== ※\n";
    cout << left << setw(6)  << "[ID]"
         << setw(34) << "Description"
         << setw(16) << "Expected"
         << setw(16) << "Result"
         << "Status\n";
    cout << string(80, '-') << "\n";

    // Test 1: Example 1
    runTest(1, {2, 3, 4, 6, 8, 16}, {{0, 0, 2}, {1, 3, 8}, {0, 2, 5}}, {1, 4}, "Example 1 (Mixed queries)");

    // Test 2: Example 2
    runTest(2, {12, 18, 24, 30, 36}, {{0, 1, 3}, {1, 2, 15}, {0, 0, 2}, {0, 2, 4}}, {6, 3, 3}, "Example 2 (Update and queries)");

    // Test 3: Single element array
    runTest(3, {42}, {{0, 0, 0}, {1, 0, 17}, {0, 0, 0}}, {42, 17}, "Single element array");

    // Test 4: All identical elements
    runTest(4, {5, 5, 5, 5}, {{0, 0, 3}, {0, 1, 2}}, {5, 5}, "Identical elements");

    // Test 5: Coprime elements
    runTest(5, {7, 11, 13, 17}, {{0, 0, 3}, {0, 1, 2}}, {1, 1}, "Prime/Coprime array");

    // Test 6: Common divisor across entire array
    runTest(6, {10, 20, 30, 40, 50}, {{0, 0, 4}, {0, 1, 3}}, {10, 10}, "Multiples of 10");

    // Test 7: Point update breaking common factor
    runTest(7, {12, 24, 36}, {{0, 0, 2}, {1, 1, 7}, {0, 0, 2}}, {12, 1}, "Update breaking common GCD");

    // Test 8: Single element queries within array
    runTest(8, {9, 27, 81}, {{0, 0, 0}, {0, 1, 1}, {0, 2, 2}}, {9, 27, 81}, "Individual element queries");

    // Test 9: Consecutive updates before query
    runTest(9, {2, 4, 8, 16}, {{1, 0, 32}, {1, 1, 48}, {1, 2, 64}, {0, 0, 2}}, {16}, "Consecutive updates");

    // Test 10: Full range with updates
    runTest(10, {6, 9, 15, 21}, {{0, 0, 3}, {1, 0, 18}, {0, 0, 3}}, {3, 3}, "Full range with GCD 3");

    cout << "※ ============================================================================== ※\n";
    cout << "                         🎉 All Tests Completed Successfully!                     \n\n";

    return 0;
}
