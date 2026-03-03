#include <iostream>

using namespace std;

class Solution {
public:
    char findKthBit(int n, int k) {
        if (n == 1) return '0';
        
        int length = (1 << n) - 1;
        int mid = length / 2 + 1; // Middle element is exactly (1 << (n - 1))
        
        if (k == mid) {
            return '1';
        } else if (k < mid) {
            return findKthBit(n - 1, k);
        } else {
            char correspondingBit = findKthBit(n - 1, length - k + 1);
            return (correspondingBit == '0') ? '1' : '0';
        }
    }
};

int main() {
    Solution sol;
    int n, k;
    
    // Example 1
    n = 3, k = 1;
    cout << "Input: n = " << n << ", k = " << k << endl;
    cout << "Output: " << sol.findKthBit(n, k) << endl;
    
    // Example 2
    n = 4, k = 11;
    cout << "Input: n = " << n << ", k = " << k << endl;
    cout << "Output: " << sol.findKthBit(n, k) << endl;
    
    return 0;
}
