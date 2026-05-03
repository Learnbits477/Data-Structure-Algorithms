#include <iostream>
#include <vector>
#include <string>
#include "Solution.cpp"

using namespace std;

void test(string s, string goal, bool expected) {
    Solution sol;
    bool result = sol.rotateString(s, goal);
    
    cout << "Input: s = \"" << s << "\", goal = \"" << goal << "\"" << endl;
    cout << "Output: " << (result ? "true" : "false") << endl;
    cout << "Expected: " << (expected ? "true" : "false") << endl;
    
    if (result == expected) {
        cout << "[PASS]" << endl;
    } else {
        cout << "[FAIL]" << endl;
    }
    cout << "-----------------------------------" << endl;
}

int main() {
    cout << "Running Tests for 796. Rotate String..." << endl << endl;

    // Test Case 1
    test("abcde", "cdeab", true);

    // Test Case 2
    test("abcde", "abced", false);

    // Test Case 3 (Empty strings - though constraints say length >= 1)
    test("a", "a", true);

    // Test Case 4 (Different lengths)
    test("abc", "abcd", false);

    // Test Case 5 (Single character rotation)
    test("abc", "bca", true);

    return 0;
}

/**
 * Related Files:
 * - Problem.md: [Problem.md](./Problem.md)
 * - Solution.cpp: [Solution.cpp](./Solution.cpp)
 * - Approach.md: [Approach.md](./Approach.md)
 */

/**
 * @file Main.cpp
 * @brief Driver code to verify the Solution.cpp
 * 
 * Links:
 * - [Problem.md](./Problem.md)
 * - [Solution.cpp](./Solution.cpp)
 * - [Approach.md](./Approach.md)
 */
