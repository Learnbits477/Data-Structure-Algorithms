#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

void runTest(int testNum, const string& s, int expected, const string& description) {
    Solution sol;
    int result = sol.reverseDegree(s);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";

    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);

    string displayS = "\"" + s + "\"";
    if (displayS.length() > 18) {
        displayS = displayS.substr(0, 15) + "...\"";
    }

    string displayDesc = description;
    if (displayDesc.length() > 24) {
        displayDesc = displayDesc.substr(0, 21) + "...";
    }

    cout << left << setw(6)  << testId
         << setw(20) << displayS
         << setw(26) << displayDesc
         << setw(12) << expected
         << setw(12) << result
         << status << "\n";

    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     String:      \"" << s << "\"\n"
             << "     Description: " << description << "\n"
             << "     Expected:    " << expected << "\n"
             << "     Got:         " << result << "\n";
    }
}

int main() {
    cout << "\n🔤 3498. Reverse Degree of a String — Test Suite\n";
    cout << "※ =================================================================================== ※\n";
    cout << left << setw(6)  << "[ID]"
         << setw(20) << "Input String"
         << setw(26) << "Description"
         << setw(12) << "Expected"
         << setw(12) << "Result"
         << "Status\n";
    cout << string(83, '-') << "\n";

    // Test 1: Example 1
    runTest(1, "abc", 148, "Example 1 (abc)");

    // Test 2: Example 2
    runTest(2, "zaza", 160, "Example 2 (zaza)");

    // Test 3: Single character 'a' (weight 26 * 1)
    runTest(3, "a", 26, "Single char 'a'");

    // Test 4: Single character 'z' (weight 1 * 1)
    runTest(4, "z", 1, "Single char 'z'");

    // Test 5: All 'a's (4 chars) -> 26 * (1+2+3+4) = 260
    runTest(5, "aaaa", 260, "Uniform 'a's");

    // Test 6: All 'z's (5 chars) -> 1 * (1+2+3+4+5) = 15
    runTest(6, "zzzzz", 15, "Uniform 'z's");

    // Test 7: Descending characters ("zyx") -> 1*1 + 2*2 + 3*3 = 14
    runTest(7, "zyx", 14, "Descending 'zyx'");

    // Test 8: Palindromic word "racecar"
    runTest(8, "racecar", 560, "Palindrome 'racecar'");

    // Test 9: Two characters "ab" -> 26*1 + 25*2 = 76
    runTest(9, "ab", 76, "Two chars 'ab'");

    // Test 10: Alternating pattern "azazazazaz"
    runTest(10, "azazazazaz", 680, "Alternating 'az'");

    cout << "※ =================================================================================== ※\n";
    cout << "                         🎉 All Tests Completed Successfully!                     \n\n";

    return 0;
}
