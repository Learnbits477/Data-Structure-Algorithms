#include <iostream>
#include <string>
#include "Solution.cpp"

using namespace std;

int main() {
    Solution solution;
    
    // Example 1
    string s1 = "10212";
    cout << "Input: s = \"" << s1 << "\"" << endl;
    cout << "Output: " << solution.smallestSubstring(s1) << endl; 
    cout << "Expected: 3" << endl << endl;

    // Example 2
    string s2 = "12121";
    cout << "Input: s = \"" << s2 << "\"" << endl;
    cout << "Output: " << solution.smallestSubstring(s2) << endl; 
    cout << "Expected: -1" << endl << endl;
    
    // Additional Test Case
    string s3 = "012";
    cout << "Input: s = \"" << s3 << "\"" << endl;
    cout << "Output: " << solution.smallestSubstring(s3) << endl;
    cout << "Expected: 3" << endl << endl;

    return 0;
}

// Problem Link: ./Problem.md
// Approach Link: ./Approach.md
// Solution Link: ./Solution.cpp
