#include <iostream>

using namespace std;

class Solution {
public:
    int concatenatedBinary(int n) {
        long long ans = 0;
        constexpr int MOD = 1e9 + 7;
        int len = 0;
        
        for (int i = 1; i <= n; i++) {
            if (!(i & (i - 1))) len++;  // power of 2 check
            ans = ((ans << len) + i) % MOD;
        }
        
        return (int)ans;
    }
};

int main() {
    Solution sol;
    
    // Instead of using 'cin' which requires you to type, 
    // let's just hardcode the input n right here:
    int n = 12; 
    
    cout << "For n = " << n << ":" << endl;
    cout << "Result: " << sol.concatenatedBinary(n) << endl;
    
    return 0;
}
