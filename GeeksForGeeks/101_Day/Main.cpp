#include <iostream>
#include <vector>
#include <string>
#include "Solution.cpp"

using namespace std;

void printResult(const vector<string>& res) {
    cout << "[";
    for (size_t i = 0; i < res.size(); ++i) {
        cout << "\"" << res[i] << "\"";
        if (i < res.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
}

void runTest(string s, int testNum) {
    Solution sol;
    vector<string> result = sol.validParenthesis(s);
    cout << "Test Case " << testNum << ": s = \"" << s << "\"" << endl;
    cout << "Output: ";
    printResult(result);
    cout << "------------------------------------------" << endl;
}

int main() {
    cout << "--- Remove Invalid Parentheses ---" << endl << endl;

    // Test Case 1: Example 1 from problem
    runTest("()())()", 1);

    // Test Case 2: Example 2 (with characters)
    runTest("(a)())()", 2);

    // Test Case 3: Example 3 (all invalid)
    runTest(")(", 3);

    // Test Case 4: Complex case
    runTest("((())(", 4);

    // Test Case 6: GFG failing case with characters
    runTest("()(l()((", 6);

    return 0;
}
