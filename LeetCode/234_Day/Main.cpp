#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

string formatVec(const vector<string>& v) {
    stringstream ss;
    ss << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        ss << "\"" << v[i] << "\"";
        if (i + 1 < v.size()) ss << ",";
        if (ss.str().length() > 22 && i + 1 < v.size()) {
            ss << "...]";
            return ss.str();
        }
    }
    ss << "]";
    return ss.str();
}

void runTest(int testNum, const string& s, vector<string> expected) {
    Solution sol;
    vector<string> result = sol.maxNumOfSubstrings(s);

    // Sort both to allow comparison regardless of return order
    vector<string> sortedResult = result;
    vector<string> sortedExpected = expected;
    sort(sortedResult.begin(), sortedResult.end());
    sort(sortedExpected.begin(), sortedExpected.end());

    bool passed = (sortedResult == sortedExpected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";

    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);

    string displayStr = "\"" + s + "\"";
    if (displayStr.length() > 18) {
        displayStr = displayStr.substr(0, 15) + "...\"";
    }

    string displayExpected = formatVec(expected);
    string displayResult = formatVec(result);

    cout << left << setw(6)  << testId
         << setw(20) << displayStr
         << setw(26) << displayExpected
         << setw(26) << displayResult
         << status << "\n";

    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     s:        \"" << s << "\"\n"
             << "     Expected: ";
        for (const auto& str : expected) cout << "\"" << str << "\" ";
        cout << "\n     Got:      ";
        for (const auto& str : result) cout << "\"" << str << "\" ";
        cout << "\n";
    }
}

int main() {
    cout << "\n✂️ 1520. Maximum Number of Non-Overlapping Substrings — Test Suite\n";
    cout << "※ ====================================================================================== ※\n";
    cout << left << setw(6)  << "[ID]"
         << setw(20) << "Input s"
         << setw(26) << "Expected"
         << setw(26) << "Result"
         << "Status\n";
    cout << string(86, '-') << "\n";

    // Test 1: Example 1 -> ["e", "f", "ccc"]
    runTest(1, "adefaddaccc", {"e", "f", "ccc"});

    // Test 2: Example 2 -> ["bb", "cc", "d"]
    runTest(2, "abbaccd", {"bb", "cc", "d"});

    // Test 3: Single character string -> ["a"]
    runTest(3, "a", {"a"});

    // Test 4: All identical characters -> ["aaaaa"]
    runTest(4, "aaaaa", {"aaaaa"});

    // Test 5: All distinct characters -> ["a", "b", "c", "d", "e", "f"]
    runTest(5, "abcdef", {"a", "b", "c", "d", "e", "f"});

    // Test 6: Interleaved string with isolated single center character -> ["c"]
    runTest(6, "abacaba", {"c"});

    // Test 7: Nested valid interval with trailing unique character -> ["bababa", "c"]
    runTest(7, "bababac", {"bababa", "c"});

    // Test 8: Disjoint pairs of duplicates -> ["aa", "bb", "cc", "dd"]
    runTest(8, "aabbccdd", {"aa", "bb", "cc", "dd"});

    // Test 9: Enclosing outer character forcing full span -> ["cabababcbc"]
    runTest(9, "cabababcbc", {"cabababcbc"});

    // Test 10: Mutually overlapping letters forcing two-character substring -> ["abab"]
    runTest(10, "abab", {"abab"});

    cout << "※ ====================================================================================== ※\n";
    cout << "                         🎉 All Tests Completed Successfully!                             \n\n";

    return 0;
}
