#include <iostream>
#include <string>
#include "Solution.cpp"

void runTest(int id, string s, bool expected) {
    Solution sol;
    bool result = sol.canFormPalindrome(s);
    if (result == expected) 
        cout << "Test " << id << ": PASS\n";
    else 
        cout << "Test " << id << ": FAIL (Expected " << expected << ", Got " << result << ")\n";
}

int main() {
    runTest(1, "baba",          true);
    runTest(2, "geeksogeeks",   true);
    runTest(3, "geeksforgeeks", false);
    runTest(4, "a",             true);
    runTest(5, "aa",            true);
    runTest(6, "ab",            false);
    runTest(7, "aab",           true);
    runTest(8, "aaaa",          true);
    return 0;
}
