#include <iostream>

using namespace std;

class Solution {
public:
    bool hasAlternatingBits(int n) {
        long x = n ^ (n >> 1);
        return (x & (x + 1)) == 0;
    }
};

int main() {
    Solution sol;
    
    // Example 1
    int n1 = 5;
    cout << "Input: n = " << n1 << endl;
    cout << "Output: " << (sol.hasAlternatingBits(n1) ? "true" : "false") << endl; // Expected: true

    // Example 2
    int n2 = 7;
    cout << "Input: n = " << n2 << endl;
    cout << "Output: " << (sol.hasAlternatingBits(n2) ? "true" : "false") << endl; // Expected: false

    // Example 3
    int n3 = 11;
    cout << "Input: n = " << n3 << endl;
    cout << "Output: " << (sol.hasAlternatingBits(n3) ? "true" : "false") << endl; // Expected: false

    return 0;
}
