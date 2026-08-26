#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

void runTest(int testNum, string s, int k, string expected) {
    Solution sol;
    string result = sol.shortestBeautifulSubstring(s, k);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";

    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);

    cout << left << setw(6)  << testId
         << setw(26) << (s.length() > 22 ? s.substr(0, 19) + "..." : s)
         << setw(6)  << k
         << setw(16) << ("\"" + expected + "\"")
         << setw(16) << ("\"" + result + "\"")
         << status << "\n";

    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Expected: \"" << expected << "\"\n"
             << "     Got:      \"" << result << "\"\n";
    }
}

int main() {
    cout << "\n🎮 Shortest & Lexicographically Smallest Beautiful String — Test Suite\n";
    cout << "※ ============================================================================== ※\n";
    cout << left << setw(6)  << "[ID]"
         << setw(26) << "Binary String s"
         << setw(6)  << "k"
         << setw(16) << "Expected"
         << setw(16) << "Result"
         << "Status\n";
    cout << string(76, '-') << "\n";

    runTest(1, "100011001", 3, "11001");
    runTest(2, "1011", 2, "11");
    runTest(3, "000", 1, "");
    runTest(4, "10101", 2, "101");
    runTest(5, "1", 1, "1");
    runTest(6, "0", 1, "");
    runTest(7, "1111", 2, "11");
    runTest(8, "1101011", 3, "1011");
    runTest(9, "000000000000000000010000000000000000", 1, "1");
    runTest(10, "100000000001", 2, "100000000001");

    cout << "※ ============================================================================== ※\n";
    cout << "                         🎉 All Tests Completed Successfully!                        \n\n";

    return 0;
}
