#include "Solution.cpp"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void printVector(const vector<int>& v) {
    cout << "[";
    for (int i = 0; i < (int)v.size(); i++) {
        cout << v[i];
        if (i + 1 < (int)v.size()) cout << ", ";
    }
    cout << "]";
}

void runTest(int testNum, vector<int> cost, int w, int expected) {
    Solution sol;
    int result = sol.minimumCost(cost, w);
    bool passed = (result == expected);

    cout << "  Test " << testNum << "  |  ";
    cout << "cost = ";
    printVector(cost);
    cout << "  |  w = " << w;
    cout << "  |  Expected: " << expected;
    cout << "  |  Got: " << result;
    cout << "  |  " << (passed ? "PASSED" : "FAILED");
    cout << "\n";
}

int main() {
    cout << "\n";
    cout << "   Minimum Cost to Fill Given Weight - Test Suite\n";
    cout << "                   GFG Day 139\n";
    cout << "==========================================================\n\n";

    cout << "  Provided Examples:\n";
    cout << "  " << string(60, '-') << "\n";

    runTest(1, {20, 10, 4, 50, 100}, 5, 14);
    runTest(2, {-1, -1, 4, 3, -1}, 5, -1);

    cout << "\n  Edge Cases:\n";
    cout << "  " << string(60, '-') << "\n";

    runTest(3, {5}, 3, 15);
    runTest(4, {100}, 1, 100);
    runTest(5, {-1, -1, 7}, 3, 7);
    runTest(6, {-1, -1, -1}, 2, -1);
    runTest(7, {-1, 10}, 1, -1);
    runTest(8, {10, 20, 30, 40, 5}, 5, 5);
    runTest(9, {1, 1000, 1000, 1000}, 4, 4);
    runTest(10, {-1, 3, -1, 2}, 4, 2);

    cout << "\n==========================================================\n";
    cout << "                  All Tests Complete!\n";
    cout << "==========================================================\n\n";

    return 0;
}
