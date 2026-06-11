#include <iostream>
#include <vector>
#include <string>
#include "Solution.cpp"

using namespace std;

// Function to run a single test case and output the result
void runTest(int testNum, string s, int expected) {
    Solution sol;
    int result = sol.findIndex(s);
    
    cout << "Test Case " << testNum << ":\n";
    cout << "  Input:    s = \"" << s << "\"\n";
    cout << "  Expected: " << expected << "\n";
    cout << "  Output:   " << result << "\n";
    
    if (result == expected) {
        cout << "  Status:   ✅ PASSED\n\n";
    } else {
        cout << "  Status:   ❌ FAILED\n\n";
    }
}

int main() {
    cout << "\n🔢 Equal Point in Brackets — Test Suite\n";
    cout << "========================================================\n" << endl;
    
    // GFG Example 1
    runTest(1, "(())))(", 4);
    
    // GFG Example 2
    runTest(2, "))", 2);
    
    // Additional Edge Cases
    runTest(3, "(", 0);        // Only one opening bracket
    runTest(4, ")", 1);        // Only one closing bracket
    runTest(5, "()", 1);       // One opening, one closing
    runTest(6, ")(", 1);       // One closing, one opening
    runTest(7, "(((", 0);      // All opening brackets
    runTest(8, ")))", 3);      // All closing brackets
    
    return 0;
}
