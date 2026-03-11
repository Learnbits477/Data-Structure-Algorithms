#include <iostream>
using namespace std;

class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0) {
            return 1;
        }
        
        int m = n;
        int mask = 0;
        
        while (m != 0) {
            mask = (mask << 1) | 1;
            m = m >> 1;
        }
        
        int ans = (~n) & mask;
        return ans;
    }
};

int main() {
    Solution solution;
    
    // Example 1
    int n1 = 5;
    cout << "Input: n = " << n1 << endl;
    cout << "Output: " << solution.bitwiseComplement(n1) << endl;
    
    // Example 2
    int n2 = 7;
    cout << "Input: n = " << n2 << endl;
    cout << "Output: " << solution.bitwiseComplement(n2) << endl;
    
    // Example 3
    int n3 = 10;
    cout << "Input: n = " << n3 << endl;
    cout << "Output: " << solution.bitwiseComplement(n3) << endl;
    
    return 0;
}
