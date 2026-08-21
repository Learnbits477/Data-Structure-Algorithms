#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

void runTest(int testNum, const string& s1, const string& s2, int expected) {
    Solution sol;
    int result = sol.transform(s1, s2);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";

    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);

    string displayS1 = s1;
    if (displayS1.length() > 16) {
        displayS1 = displayS1.substr(0, 13) + "...";
    }

    string displayS2 = s2;
    if (displayS2.length() > 16) {
        displayS2 = displayS2.substr(0, 13) + "...";
    }

    cout << left << setw(6)  << testId
         << setw(18) << displayS1
         << setw(18) << displayS2
         << setw(12) << expected
         << setw(12) << result
         << status << "\n";

    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Expected: " << expected << "\n"
             << "     Got:      " << result << "\n";
    }
}

int main() {
    cout << "\n🔤 Transform String — Test Suite\n";
    cout << "※ ================================================================================== ※\n";
    cout << left << setw(6)  << "[ID]"
         << setw(18) << "String s1"
         << setw(18) << "String s2"
         << setw(12) << "Expected"
         << setw(12) << "Result"
         << "Status\n";
    cout << string(76, '-') << "\n";

    runTest(1, "abd", "bad", 1);
    runTest(2, "GeeksForGeeks", "ForGeeksGeeks", 3);
    runTest(3, "EACBD", "EABCD", 3);
    runTest(4, "A", "A", 0);
    runTest(5, "AB", "BA", 1);
    runTest(6, "abc", "def", -1);
    runTest(7, "hello", "world", -1);
    runTest(8, "abcd", "abcde", -1);
    runTest(9, "aab", "aba", 2);
    runTest(10, "transformation", "tiontransforma", 4);

    cout << "※ ================================================================================== ※\n";
    cout << "                         🎉 All Tests Completed Successfully!                        \n\n";

    return 0;
}
