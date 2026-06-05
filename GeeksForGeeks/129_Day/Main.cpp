#include <iostream>
#include <string>
#include "Solution.cpp"

using namespace std;

void runTest(string s, int k, const string& expected) {
    Solution solution;
    string result = solution.lexicographicallySmallest(s, k);
    
    cout << "Input: s = \"" << s << "\", k = " << k << "\n";
    cout << "Expected: \"" << expected << "\"\n";
    cout << "Output:   \"" << result << "\"\n";
    
    if (result == expected) {
        cout << "✅ PASSED\n\n";
    } else {
        cout << "❌ FAILED\n\n";
    }
}

int main() {
    cout << "\n🔢 Lexicographically smallest after removing k — Test Suite\n";
    
    // Example 1
    runTest("fooland", 2, "and");
    
    // Example 2
    runTest("code", 4, "cd");
    
    // Edge case - Not enough elements possible to keep
    runTest("aba", 2, "-1"); 
    
    return 0;
}
