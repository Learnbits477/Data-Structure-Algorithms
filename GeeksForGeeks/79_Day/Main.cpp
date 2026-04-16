#include "Solution.cpp"

static int passed = 0, failed = 0, total = 0;

void runTest(int testNum, const string& input, int expected) {
    Solution sol;
    int result = sol.myAtoi(input);
    bool ok = (result == expected);
    total++;
    ok ? passed++ : failed++;

    cout << "[Test " << testNum << "] "
         << (ok ? "PASS" : "FAIL") << "\n"
         << "  Input    : \"" << input    << "\"\n"
         << "  Expected : "  << expected  << "\n"
         << "  Got      : "  << result    << "\n\n";
}

int main() {
    runTest(1, "-123",               -123);
    runTest(2, " -",                  0);
    runTest(3, " 1231231231311133",  2147483647);
    runTest(4, "-999999999999",      -2147483648);
    runTest(5, "  -0012gfg4",        -12);

    runTest(6, "42",           42);          // Simple positive
    runTest(7, "+42",          42);          // Explicit positive sign
    runTest(8, "0",             0);          // Zero
    runTest(9, "  ",            0);          // Only spaces
    runTest(10, "abc",          0);          // No digits at all
    runTest(11, "2147483647",   2147483647); // Exact INT_MAX
    runTest(12, "-2147483648", -2147483648); // Exact INT_MIN
    runTest(13, "00123",        123);        // Leading zeros

    cout << "============================================\n"
         << "  Results  : " << passed << " / " << total << " passed"
         << (failed ? "  |  " + to_string(failed) + " failed" : "  |  All tests passed!")
         << "\n"
         << "============================================\n";

    return (failed == 0) ? 0 : 1;
}
