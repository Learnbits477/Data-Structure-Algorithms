#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

void runTest(int testNum, string s, string queryCharacters, vector<int> queryIndices, vector<int> expected) {
    Solution sol;
    vector<int> result = sol.longestRepeating(s, queryCharacters, queryIndices);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";
    
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);
    
    cout << left << setw(6)  << testId 
         << setw(12) << to_string(s.length())
         << setw(12) << to_string(queryIndices.size())
         << status << "\n";
         
    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Expected: [";
        for (size_t i = 0; i < expected.size(); ++i) {
            cout << expected[i] << (i + 1 == expected.size() ? "" : ", ");
        }
        cout << "]\n     Got:      [";
        for (size_t i = 0; i < result.size(); ++i) {
            cout << result[i] << (i + 1 == result.size() ? "" : ", ");
        }
        cout << "]\n";
    }
}

int main() {
    cout << "\n🔢 Longest Substring of One Repeating Character — Test Suite\n";
    cout << "⇐ - ========================================== - ⇒\n";
    cout << left << setw(6)  << "[ID]" 
         << setw(12) << "Str Size" 
         << setw(12) << "Queries" 
         << "Status\n";
    cout << string(45, '-') << "\n";

    // Test 1: Example 1
    runTest(1, "babacc", "bcb", {1, 3, 3}, {3, 3, 4});

    // Test 2: Example 2
    runTest(2, "abyzz", "aa", {2, 1}, {2, 3});

    // Test 3: Single character update
    runTest(3, "a", "b", {0}, {1});

    // Test 4: Big repeat, modifying middle elements to same
    runTest(4, "aaaaa", "aa", {2, 3}, {5, 5});

    // Test 5: Breaking a perfect run
    runTest(5, "aaaaa", "b", {2}, {2});

    // Test 6: Creating segments on the fly
    runTest(6, "aabcc", "aaa", {2, 3, 4}, {3, 4, 5});

    cout << "⇐ - ========================================== - ⇒\n";
    cout << "          🎉 All Tests Executed!             \n\n";

    return 0;
}
