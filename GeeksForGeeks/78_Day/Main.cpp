#include "Solution.cpp"

// ── Test counters ──────────────────────────────
static int passed = 0, failed = 0, total = 0;

void runTest(int testNum, const string& input, const string& expected) {
    Solution sol;
    string result = sol.URLify(input);
    bool ok = (result == expected);
    total++;
    ok ? passed++ : failed++;

    cout << "[Test " << testNum << "] "
         << (ok ? "PASS" : "FAIL") << "\n"
         << "  Input    : \"" << input    << "\"\n"
         << "  Expected : \"" << expected << "\"\n"
         << "  Got      : \"" << result   << "\"\n\n";
}

int main() {
    cout << "============================================\n"
         << "  Problem  : URLify a Given String          \n"
         << "  Platform : GeeksForGeeks | Day 78         \n"
         << "============================================\n\n";

    // ── GFG Examples ──────────────────────────
    runTest(1, "i love programming",      "i%20love%20programming");
    runTest(2, "Mr Benedict Cumberbatch", "Mr%20Benedict%20Cumberbatch");

    // ── Edge Cases ────────────────────────────
    runTest(3, "hello",  "hello");        // No spaces
    runTest(4, " ",      "%20");          // Single space
    runTest(5, "  ",     "%20%20");       // Only spaces
    runTest(6, " a b ",  "%20a%20b%20"); // Leading & trailing spaces

    // ── Summary ───────────────────────────────
    cout << "============================================\n"
         << "  Results  : " << passed << " / " << total << " passed"
         << (failed ? "  |  " + to_string(failed) + " failed" : "  |  All tests passed!")
         << "\n"
         << "============================================\n";

    return (failed == 0) ? 0 : 1;
}
