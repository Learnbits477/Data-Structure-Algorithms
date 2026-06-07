#include <iostream>
#include <string>
#include "Solution.cpp"

using namespace std;

void runTest(int level, int pos, string expected) {
    Solution sol;
    string result = sol.profession(level, pos);
    
    cout << "Input: level = " << level << ", pos = " << pos << "\n";
    cout << "Expected: " << expected << " | Output: " << result << "\n";
    
    if (result == expected) {
        cout << "✅ PASSED\n\n";
    } else {
        cout << "❌ FAILED\n\n";
    }
}

int main() {
    cout << "\n🔢 Finding Profession — Test Suite\n";
    cout << "-------------------------------------\n" << endl;
    
    // GFG Example 1
    runTest(4, 2, "Doctor");
    
    // GFG Example 2
    runTest(3, 4, "Engineer");
    
    // Additional Edge Cases
    runTest(1, 1, "Engineer"); // Root (Level 1, pos 1)
    runTest(2, 1, "Engineer"); // Left child of root
    runTest(2, 2, "Doctor");   // Right child of root
    runTest(3, 2, "Doctor");   // Right child of Left child
    runTest(3, 3, "Doctor");   // Left child of Right child
    runTest(4, 8, "Doctor");   // Rightmost child at Level 4
    
    return 0;
}
