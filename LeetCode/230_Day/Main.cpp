#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

string formatRect(const vector<int>& r) {
    if (r.size() < 4) return "[]";
    return "[" + to_string(r[0]) + "," + to_string(r[1]) + "," +
           to_string(r[2]) + "," + to_string(r[3]) + "]";
}

void runTest(int testNum, vector<int> rec1, vector<int> rec2, bool expected) {
    Solution sol;
    bool result = sol.isRectangleOverlap(rec1, rec2);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";

    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);

    cout << left << setw(6)  << testId
         << setw(18) << formatRect(rec1)
         << setw(18) << formatRect(rec2)
         << setw(12) << (result ? "true" : "false")
         << setw(12) << (expected ? "true" : "false")
         << status << "\n";

    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     rec1     = " << formatRect(rec1) << "\n"
             << "     rec2     = " << formatRect(rec2) << "\n"
             << "     Expected = " << (expected ? "true" : "false") << "\n"
             << "     Got      = " << (result ? "true" : "false") << "\n";
    }
}

int main() {
    cout << "\n📐 836. Rectangle Overlap — Test Suite\n";
    cout << "※ ========================================================================= ※\n";
    cout << left << setw(6)  << "[ID]"
         << setw(18) << "Rectangle 1"
         << setw(18) << "Rectangle 2"
         << setw(12) << "Result"
         << setw(12) << "Expected"
         << "Status\n";
    cout << string(74, '-') << "\n";

    // Test 1: Example 1 (Standard positive overlap) -> true
    runTest(1, {0, 0, 2, 2}, {1, 1, 3, 3}, true);

    // Test 2: Example 2 (Touching along vertical edge x = 1) -> false
    runTest(2, {0, 0, 1, 1}, {1, 0, 2, 1}, false);

    // Test 3: Example 3 (Completely disjoint) -> false
    runTest(3, {0, 0, 1, 1}, {2, 2, 3, 3}, false);

    // Test 4: Touching at a single corner point (1, 1) -> false
    runTest(4, {0, 0, 1, 1}, {1, 1, 2, 2}, false);

    // Test 5: rec2 completely nested inside rec1 -> true
    runTest(5, {0, 0, 5, 5}, {1, 1, 4, 4}, true);

    // Test 6: Identical rectangles -> true
    runTest(6, {0, 0, 2, 2}, {0, 0, 2, 2}, true);

    // Test 7: Negative coordinates overlap -> true
    runTest(7, {-5, -5, -1, -1}, {-3, -3, 0, 0}, true);

    // Test 8: Cross/Plus-shaped intersection -> true
    runTest(8, {0, 2, 6, 4}, {2, 0, 4, 6}, true);

    cout << "※ ========================================================================= ※\n";
    cout << "                         🎉 All Tests Executed!                             \n\n";

    return 0;
}
