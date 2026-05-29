#include "Solution.cpp"
#include <iostream>
#include <string>
using namespace std;

void printSeparator() {
    cout << "  " << string(50, '-') << "\n";
}

void runTest(int testNo, string input, int expected) {
    Solution sol;
    int result = sol.validGroups(input);

    cout << "  Test #" << testNo << "\n";
    cout << "    Input    : s = \"" << input << "\"\n";
    cout << "    Expected : " << expected << "\n";
    cout << "    Got      : " << result << "\n";

    if (result == expected)
        cout << "    Status   : PASSED\n";
    else
        cout << "    Status   : FAILED\n";

    printSeparator();
}

int main() {
    cout << "\n  Count Sorted Digit Groupings - Test Suite\n\n";
    printSeparator();

    runTest(1, "1119", 7);
    runTest(2, "12",   2);
    runTest(3, "5",    1);
    runTest(4, "00",   2);
    runTest(5, "123",  4);
    runTest(6, "99",   2);
    runTest(7, "1111", 5);

    cout << "  All tests completed!\n\n";
    return 0;
}
