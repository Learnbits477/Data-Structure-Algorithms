#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

void runTest(int testNum, string s, const string& expected, const string& description) {
    // Step: 01 - Compute result using both Two-Pointer and Booth algorithms
    Solution sol;
    string res1 = sol.lexiString(s);
    string res2 = sol.boothMinRotation(s);

    // Step: 02 - Validate correctness against expected output
    bool passed = (res1 == expected) && (res2 == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";

    // Step: 03 - Format test ID and descriptions
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);

    string displayDesc = description;
    if (displayDesc.length() > 34) {
        displayDesc = displayDesc.substr(0, 31) + "...";
    }

    string sDisplay = s.length() > 14 ? s.substr(0, 11) + "..." : s;
    string expDisplay = expected.length() > 14 ? expected.substr(0, 11) + "..." : expected;
    string actDisplay = res1.length() > 14 ? res1.substr(0, 11) + "..." : res1;

    // Step: 04 - Print formatted test result row
    cout << left << setw(6)  << testId
         << setw(36) << displayDesc
         << setw(16) << expDisplay
         << setw(16) << actDisplay
         << status << "\n";

    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Input string:    \"" << s << "\"\n"
             << "     Expected:        \"" << expected << "\"\n"
             << "     Two-Pointer:     \"" << res1 << "\"\n"
             << "     Booth's Algo:    \"" << res2 << "\"\n";
    }
}

int main() {
    // Step: 01 - Print test suite header and table format
    cout << "\n📍 Lexicographically Smallest Rotation — Test Suite\n";
    cout << "※ =================================================================================== ※\n";
    cout << left << setw(6)  << "[ID]"
         << setw(36) << "Description"
         << setw(16) << "Expected"
         << setw(16) << "Result"
         << "Status\n";
    cout << string(85, '-') << "\n";

    // Step: 02 - Run all test cases
    runTest(1, "abcd", "abcd", "Example 1 (Already sorted)");
    runTest(2, "baca", "abac", "Example 2 (Rotation needed)");
    runTest(3, "a", "a", "Single character string");
    runTest(4, "aaaa", "aaaa", "All identical characters");
    runTest(5, "ba", "ab", "Two characters inverted");
    runTest(6, "aba", "aab", "Odd-length palindrome 'aba'");
    runTest(7, "abacaba", "aabacab", "Ruler string 'abacaba'");
    runTest(8, "cba", "acb", "Descending order 'cba'");
    runTest(9, "banana", "abanan", "Classic word 'banana'");
    runTest(10, "mississippi", "imississipp", "Classic word 'mississippi'");
    runTest(11, "abababab", "abababab", "Periodic repeating 'abababab'");
    runTest(12, "bbbaabbb", "aabbbbbb", "Cluster of 'a's in middle");
    runTest(13, "aaabbb", "aaabbb", "Sorted blocks 'aaabbb'");
    runTest(14, "abracadabra", "aabracadabr", "Magic word 'abracadabra'");

    // Step: 03 - Print test completion summary
    cout << "※ =================================================================================== ※\n";
    cout << "                         🎉 All Tests Completed Successfully!                     \n\n";

    return 0;
}
