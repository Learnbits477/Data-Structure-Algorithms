#include <vector>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        int dp1 = 0; // dp[i+1]
        int dp2 = 0; // dp[i+2]
        int dp3 = 0; // dp[i+3]
        
        for (int i = n - 1; i >= 0; --i) {
            int current_sum = 0;
            int max_val = INT_MIN;
            
            // Take 1 stone
            current_sum += stoneValue[i];
            max_val = max(max_val, current_sum - dp1);
            
            // Take 2 stones (if available)
            if (i + 1 < n) {
                current_sum += stoneValue[i + 1];
                max_val = max(max_val, current_sum - dp2);
            }
            
            // Take 3 stones (if available)
            if (i + 2 < n) {
                current_sum += stoneValue[i + 2];
                max_val = max(max_val, current_sum - dp3);
            }
            
            // Shift values for the next iteration
            dp3 = dp2;
            dp2 = dp1;
            dp1 = max_val;
        }
        
        if (dp1 > 0) return "Alice";
        if (dp1 < 0) return "Bob";
        return "Tie";
    }
};
