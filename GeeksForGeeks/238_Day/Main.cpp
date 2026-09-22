#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

void runTest(int testNum, string s, vector<string> d, const string& expected, const string& description) {
    Solution sol;
    string result = sol.findLongestWord(s, d);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";

    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);

    string displayDesc = description;
    if (displayDesc.length() > 28) {
        displayDesc = displayDesc.substr(0, 25) + "...";
    }

    string displayExpected = expected.empty() ? "\"\"" : expected;
    string displayResult = result.empty() ? "\"\"" : result;

    cout << left << setw(6)  << testId
         << setw(30) << displayDesc
         << setw(16) << displayExpected
         << setw(16) << displayResult
         << status << "\n";

    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     String s:       \"" << s << "\"\n"
             << "     Expected:       \"" << expected << "\"\n"
             << "     Got:            \"" << result << "\"\n";
    }
}

int main() {
    cout << "\n🔤 Longest Matching in Dictionary with Removals — Test Suite\n";
    cout << "※ ============================================================================== ※\n";
    cout << left << setw(6)  << "[ID]"
         << setw(30) << "Description"
         << setw(16) << "Expected"
         << setw(16) << "Result"
         << "Status\n";
    cout << string(80, '-') << "\n";

    // Test 1: Example 1
    runTest(1, "abpcplea", {"ale", "apple", "monkey", "plea"}, "apple", "Example 1 (standard)");

    // Test 2: Example 2 (tie-breaking single chars)
    runTest(2, "abpcplea", {"a", "b", "c"}, "a", "Example 2 (lex tie-break)");

    // Test 3: No valid word formed
    runTest(3, "abcdef", {"xyz", "uvw", "gh"}, "", "No matching words in dict");

    // Test 4: Exact full match
    runTest(4, "competitivetree", {"competitive", "competitivetree", "tree"}, "competitivetree", "Full string exact match");

    // Test 5: Lexicographical tie among same length words
    runTest(5, "abpcplea", {"plea", "alea", "ppla"}, "alea", "Lex tie among length 4");

    // Test 6: Requires duplicate letters correctly ordered
    runTest(6, "aabbccddeeff", {"abc", "aabb", "aabbcc", "aabbccddeeff"}, "aabbccddeeff", "Multiple duplicate counts");

    // Test 7: Word longer than s cannot match
    runTest(7, "short", {"shorter", "shortest", "shot", "so"}, "shot", "Longer words rejected");

    // Test 8: Single letter source string
    runTest(8, "z", {"a", "b", "z"}, "z", "Single character string s");

    // Test 9: Disordered characters / tie-break
    runTest(9, "banana", {"nab", "anna", "bana", "baa"}, "anna", "Lex tie (anna < bana)");

    // Test 10: Multiple ties with identical lengths
    runTest(10, "leetcode", {"leet", "code", "lead", "loot"}, "code", "Tied words lex resolution");

    cout << "※ ============================================================================== ※\n";
    cout << "                         🎉 All Tests Completed Successfully!                     \n\n";

    return 0;
}
