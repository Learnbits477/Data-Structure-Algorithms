#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

class Solution {
  public:
    int solve(int n, int m, vector<vector<int>>& grid) {
        int dp[71][71];
        int next_dp[71][71];
        
        for(int i=0; i<71; i++) {
            for(int j=0; j<71; j++) dp[i][j] = -1;
        }

        dp[0][m - 1] = grid[0][0] + grid[0][m - 1];

        for (int i = 0; i < n - 1; ++i) {
            for(int j=0; j<71; j++) {
                for(int k=0; k<71; k++) next_dp[j][k] = -1;
            }
            
            for (int j1 = 0; j1 < m; ++j1) {
                for (int j2 = 0; j2 < m; ++j2) {
                    if (dp[j1][j2] == -1) continue;

                    for (int dj1 = -1; dj1 <= 1; ++dj1) {
                        for (int dj2 = -1; dj2 <= 1; ++dj2) {
                            int nj1 = j1 + dj1;
                            int nj2 = j2 + dj2;

                            if (nj1 >= 0 && nj1 < m && nj2 >= 0 && nj2 < m) {
                                int val = (nj1 == nj2) ? grid[i + 1][nj1] : (grid[i + 1][nj1] + grid[i + 1][nj2]);
                                if (dp[j1][j2] + val > next_dp[nj1][nj2]) {
                                    next_dp[nj1][nj2] = dp[j1][j2] + val;
                                }
                            }
                        }
                    }
                }
            }
            memcpy(dp, next_dp, sizeof(dp));
        }

        int ans = 0;
        for (int j1 = 0; j1 < m; ++j1) {
            for (int j2 = 0; j2 < m; ++j2) {
                ans = max(ans, dp[j1][j2]);
            }
        }
        return ans;
    }

    int maxChocolate(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 0) return 0;
        int m = grid[0].size();
        return solve(n, m, grid);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    if (!(cin >> n >> m)) return 0;
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    Solution obj;
    cout << obj.maxChocolate(grid) << endl;
    return 0;
}
