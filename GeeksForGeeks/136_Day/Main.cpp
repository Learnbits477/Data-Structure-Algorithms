#include <iostream>
#include <vector>
#include <string>
#include "Solution.cpp"

using namespace std;

// Function to run a single test case and output the result
void runTest(int testNum, string s, int k, int expected) {
    Solution sol;
    bool result = sol.kSubstr(s, k);
    
    cout << "Test Case " << testNum << ":\n";
    cout << "  Input:    s = \"" << s << "\", k = " << k << "\n";
    cout << "  Expected: " << (expected ? "true (1)" : "false (0)") << "\n";
    cout << "  Output:   " << (result ? "true (1)" : "false (0)") << "\n";
    
    if (result == expected) {
        cout << "  Status:   ✅ PASSED\n\n";
    } else {
        cout << "  Status:   ❌ FAILED\n\n";
    }
}

int main() {
    cout << "\n🔢 Check Repeated Substring with K Replacements — Test Suite\n";
    cout << "========================================================\n" << endl;
    
    // GFG Example 1
    runTest(1, "abcbedabcabc", 3, 1);
    
    // GFG Example 2
    runTest(2, "bdac", 2, 1);
    
    // GFG Example 3
    runTest(3, "abcdabcd", 2, 0);
    
    // Additional Edge Cases
    runTest(4, "abcdef", 3, 1);     // 2 chunks: abc, def. One replacement can make them same.
    runTest(5, "aaaaaa", 2, 1);     // 3 chunks: aa, aa, aa. Already same.
    runTest(6, "abaabaaba", 3, 1);  // 3 chunks: aba, aba, aba. Already same.
    runTest(7, "abacaba", 3, 0);    // Length 7 not divisible by 3.
    
    return 0;
}
