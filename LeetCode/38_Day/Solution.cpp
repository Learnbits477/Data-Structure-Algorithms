#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool checkOnesSegment(string s) {
        return s.find("01") == string::npos;
    }
};

int main() {
    Solution solution;
    
    // Example 1
    string s1 = "1001";
    cout << "Input: s = \"" << s1 << "\"" << endl;
    cout << "Output: " << (solution.checkOnesSegment(s1) ? "true" : "false") << endl;
    cout << "Expected: false" << endl << endl;

    // Example 2
    string s2 = "110";
    cout << "Input: s = \"" << s2 << "\"" << endl;
    cout << "Output: " << (solution.checkOnesSegment(s2) ? "true" : "false") << endl;
    cout << "Expected: true" << endl << endl;
    
    // Additional Test Case
    string s3 = "1";
    cout << "Input: s = \"" << s3 << "\"" << endl;
    cout << "Output: " << (solution.checkOnesSegment(s3) ? "true" : "false") << endl;
    cout << "Expected: true" << endl << endl;

    return 0;
}
