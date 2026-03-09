#include <iostream>
#include <vector>

using namespace std;

class Solution {
    const int MOD = 1e9 + 7;
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        // dp[i][j][0] = valid arrays with i zeros, j ones, ending in 0
        // dp[i][j][1] = valid arrays with i zeros, j ones, ending in 1
        vector<vector<vector<long long>>> dp(zero + 1, vector<vector<long long>>(one + 1, vector<long long>(2, 0)));
        
        for (int i = 0; i <= zero; i++) {
            for (int j = 0; j <= one; j++) {
                if (i == 0 && j == 0) continue;
                
                // Base cases when there are only 1s
                if (i == 0) {
                    if (j <= limit) dp[i][j][1] = 1;
                    continue;
                }
                
                // Base cases when there are only 0s
                if (j == 0) {
                    if (i <= limit) dp[i][j][0] = 1;
                    continue;
                }
                
                // Ends in 0
                dp[i][j][0] = (dp[i - 1][j][0] + dp[i - 1][j][1]) % MOD;
                if (i > limit) {
                    dp[i][j][0] = (dp[i][j][0] - dp[i - 1 - limit][j][1] + MOD) % MOD;
                }
                
                // Ends in 1
                dp[i][j][1] = (dp[i][j - 1][0] + dp[i][j - 1][1]) % MOD;
                if (j > limit) {
                    dp[i][j][1] = (dp[i][j][1] - dp[i][j - 1 - limit][0] + MOD) % MOD;
                }
            }
        }
        
        return (dp[zero][one][0] + dp[zero][one][1]) % MOD;
    }
};

int main() {
    Solution solution;
    
    // Example 1
    int zero1 = 1, one1 = 1, limit1 = 2;
    cout << "Example 1 Output: " << solution.numberOfStableArrays(zero1, one1, limit1) << endl;
    
    // Example 2
    int zero2 = 1, one2 = 2, limit2 = 1;
    cout << "Example 2 Output: " << solution.numberOfStableArrays(zero2, one2, limit2) << endl;
    
    // Example 3
    int zero3 = 3, one3 = 3, limit3 = 2;
    cout << "Example 3 Output: " << solution.numberOfStableArrays(zero3, one3, limit3) << endl;
    
    return 0;
}
