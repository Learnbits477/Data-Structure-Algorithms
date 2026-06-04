#include <iostream>
#include <string>
#include "Solution.cpp"

using namespace std;

void runTest(string s, int expected, int testCase) {
    Solution sol;
    int result = sol.maxSubstring(s);
    
    cout << "Test Case " << testCase << ":\n";
    cout << "Input: s = \"" << s << "\"\n";
    cout << "Expected: " << expected << "\n";
    cout << "Result: " << result << "\n";
    
    if (result == expected) {
        cout << "✅ PASSED\n";
    } else {
        cout << "❌ FAILED\n";
    }
    cout << "----------------------------------------\n";
}

int main() {
    cout << "\n🔢 Substring with Max Zero-One Diff — Test Suite\n\n";

    runTest("11000010001", 6, 1);
    runTest("111111", -1, 2);

    return 0;
}
