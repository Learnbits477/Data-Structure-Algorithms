#include <iostream>
#include <string>
#include "Solution.cpp"

using namespace std;

int main() {
    Solution sol;
    
    // Example 1
    string s1 = "aabc";
    cout << "Input: " << s1 << endl;
    cout << "Output: " << sol.firstNonRepeating(s1) << endl;
    cout << "Expected: a#bb" << endl << endl;
    
    // Example 2
    string s2 = "bb";
    cout << "Input: " << s2 << endl;
    cout << "Output: " << sol.firstNonRepeating(s2) << endl;
    cout << "Expected: b#" << endl;
    
    return 0;
}
