#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        int ops = 0;
        
        for (int i = 0; i < n; i++) {
            char expectedChar = (i % 2 == 0) ? '0' : '1';
            if (s[i] != expectedChar) {
                ops++;
            }
        }
        
        return min(ops, n - ops);
    }
};

int main() {
    Solution sol;
    
    // Test Case 1
    string s1 = "0100";
    cout << "Input: s = \"0100\"" << endl;
    cout << "Output: " << sol.minOperations(s1) << endl;
    
    // Test Case 2
    string s2 = "10";
    cout << "\nInput: s = \"10\"" << endl;
    cout << "Output: " << sol.minOperations(s2) << endl;
    
    // Test Case 3
    string s3 = "1111";
    cout << "\nInput: s = \"1111\"" << endl;
    cout << "Output: " << sol.minOperations(s3) << endl;
    
    return 0;
}
