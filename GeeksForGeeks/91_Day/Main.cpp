#include <iostream>
#include <string>
#include <vector>

#include "Solution.cpp"

using namespace std;

int main() {
    Solution sol;
    
    // Example 1
    string s1 = "ABBA";
    int k1 = 2;
    cout << "Input: s = \"" << s1 << "\", k = " << k1 << endl;
    cout << "Output: " << sol.longestSubstr(s1, k1) << endl;
    cout << "Expected: 4\n\n";

    // Example 2
    string s2 = "ADBD";
    int k2 = 1;
    cout << "Input: s = \"" << s2 << "\", k = " << k2 << endl;
    cout << "Output: " << sol.longestSubstr(s2, k2) << endl;
    cout << "Expected: 3\n\n";
    
    return 0;
}
