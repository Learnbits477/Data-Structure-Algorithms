#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

void runTest(int testNum, int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2, bool expected) {
    Solution sol;
    bool result = sol.checkOverlap(radius, xCenter, yCenter, x1, y1, x2, y2);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";

    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);

    stringstream circleSs;
    circleSs << "r=" << radius << " (" << xCenter << "," << yCenter << ")";
    string displayCircle = circleSs.str();

    stringstream rectSs;
    rectSs << "[" << x1 << "," << y1 << "][" << x2 << "," << y2 << "]";
    string displayRect = rectSs.str();

    cout << left << setw(6)  << testId
         << setw(18) << displayCircle
         << setw(24) << displayRect
         << setw(12) << (expected ? "true" : "false")
         << setw(12) << (result ? "true" : "false")
         << status << "\n";

    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Circle:    r=" << radius << " center=(" << xCenter << "," << yCenter << ")\n"
             << "     Rectangle: [" << x1 << ", " << y1 << "] to [" << x2 << ", " << y2 << "]\n"
             << "     Expected:  " << boolalpha << expected << "\n"
             << "     Got:       " << boolalpha << result << "\n";
    }
}

int main() {
    cout << "\n⭕ 1401. Circle and Rectangle Overlapping — Test Suite\n";
    cout << "※ ================================================================================= ※\n";
    cout << left << setw(6)  << "[ID]"
         << setw(18) << "Circle"
         << setw(24) << "Rectangle"
         << setw(12) << "Expected"
         << setw(12) << "Result"
         << "Status\n";
    cout << string(78, '-') << "\n";

    // Test 1: Example 1 (tangent at vertical edge)
    runTest(1, 1, 0, 0, 1, -1, 3, 1, true);

    // Test 2: Example 2 (disjoint)
    runTest(2, 1, 1, 1, 1, -3, 2, -1, false);

    // Test 3: Example 3 (circle center is a corner of rectangle)
    runTest(3, 1, 0, 0, -1, 0, 0, 1, true);

    // Test 4: Circle entirely inside rectangle
    runTest(4, 2, 5, 5, 0, 0, 10, 10, true);

    // Test 5: Rectangle entirely inside circle
    runTest(5, 10, 0, 0, -1, -1, 1, 1, true);

    // Test 6: Circle touches corner diagonally (3-4-5 right triangle)
    runTest(6, 5, 0, 0, 3, 4, 10, 10, true);

    // Test 7: Circle just misses corner diagonally
    runTest(7, 4, 0, 0, 3, 4, 10, 10, false);

    // Test 8: Negative coordinates with intersection
    runTest(8, 5, -10, -10, -8, -7, -4, -3, true);

    // Test 9: Disjoint near boundary limits
    runTest(9, 2000, 10000, 10000, 7000, 7000, 8000, 8000, false);

    // Test 10: Touching exactly at edge at boundary limit
    runTest(10, 2000, 10000, 0, 0, -500, 8000, 500, true);

    cout << "※ ================================================================================= ※\n";
    cout << "                         🎉 All Tests Completed Successfully!                     \n\n";

    return 0;
}
