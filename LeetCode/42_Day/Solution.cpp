#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        int MOD = 1e9 + 7;
        
        // Use fast 32-bit integer arithmetic with manual modulo
        auto add = [&](int a, int b) { 
            a += b; 
            return a >= MOD ? a - MOD : a; 
        };
        auto sub = [&](int a, int b) { 
            a -= b; 
            return a < 0 ? a + MOD : a; 
        };
        
        // dp0[i][j] = ways to sequence with i zeros, j ones, ending in 0
        // dp1[i][j] = ways to sequence with i zeros, j ones, ending in 1
        // We use 2D vectors directly to avoid the overhead of 3D vectors
        vector<vector<int>> dp0(zero + 1, vector<int>(one + 1, 0));
        vector<vector<int>> dp1(zero + 1, vector<int>(one + 1, 0));
        
        for (int i = 1; i <= min(zero, limit); ++i) dp0[i][0] = 1;
        for (int j = 1; j <= min(one, limit); ++j) dp1[0][j] = 1;
        
        for (int i = 1; i <= zero; ++i) {
            for (int j = 1; j <= one; ++j) {
                // Number of stable arrays ending with 0
                dp0[i][j] = add(dp0[i-1][j], dp1[i-1][j]);
                if (i > limit) {
                    dp0[i][j] = sub(dp0[i][j], dp1[i-1-limit][j]);
                }
                
                // Number of stable arrays ending with 1
                dp1[i][j] = add(dp0[i][j-1], dp1[i][j-1]);
                if (j > limit) {
                    dp1[i][j] = sub(dp1[i][j], dp0[i][j-1-limit]);
                }
            }
        }
        
        return add(dp0[zero][one], dp1[zero][one]);
    }
};

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (cin >> t) {
        while (t--) {
            int zero, one, limit;
            cin >> zero >> one >> limit;
            Solution ob;
            cout << ob.numberOfStableArrays(zero, one, limit) << "\n";
        }
    }
    return 0;
}
