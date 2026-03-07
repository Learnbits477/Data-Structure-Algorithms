#include <bits/stdc++.h>
#include<iostream>
using namespace std;

class Solution {
  public:
    long long noOfWays(int m, int n, int x) {
        // Space Optimization using two 1D arrays
        vector<long long> prev(x + 1, 0);
        
        // Base case: 1 way to make sum 0 with 0 dice
        prev[0] = 1;
        
        for (int i = 1; i <= n; i++) {
            vector<long long> curr(x + 1, 0);
            long long window_sum = 0;
            
            for (int j = 1; j <= x; j++) {
                // Add the (j-1)-th state from the previous dice roll
                window_sum += prev[j - 1]; 
                
                // If the window exceeds 'm', slide the window to remove the oldest valid state
                if (j - 1 - m >= 0) {
                    window_sum -= prev[j - 1 - m];
                }
                
                curr[j] = window_sum;
            }
            // Update prev to be curr for the next iteration
            prev = curr;
        }
        
        return prev[x];
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int m, n, x;
        
        cin >> m >> n >> x;

        Solution ob;
        cout << ob.noOfWays(m,n,x) << endl;
    }
    return 0;
}