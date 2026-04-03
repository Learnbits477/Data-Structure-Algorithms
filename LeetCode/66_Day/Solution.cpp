#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        int n = robots.size();
        
        vector<pair<int, int>> robot_data(n);
        for(int i = 0; i < n; i++) {
            robot_data[i] = {robots[i], distance[i]};
        }
        sort(robot_data.begin(), robot_data.end());
        
        vector<int> P(n);
        vector<int> D(n);
        for(int i = 0; i < n; i++) {
            P[i] = robot_data[i].first;
            D[i] = robot_data[i].second;
        }
        
        sort(walls.begin(), walls.end()); 
        int unconditional_walls = 0;
        vector<int> W;
        
        for(int w : walls) {
            if (binary_search(P.begin(), P.end(), w)) {
                unconditional_walls++;
            } else {
                W.push_back(w);
            }
        }
        
        int dp_L = 0; 
        int dp_R = 0; 
        
        int w_idx = 0; 
        
        for (int i = 0; i <= n; i++) {
            int w_start = w_idx;
            int limit = (i < n) ? P[i] : 2000000000; 
            
            while (w_idx < W.size() && W[w_idx] < limit) {
                w_idx++;
            }
            int w_end = w_idx;
            int S = w_end - w_start; 
            
            if (i == 0) {
                int p1 = P[0];
                int d1 = D[0];
                
                auto it = lower_bound(W.begin() + w_start, W.begin() + w_end, p1 - d1);
                int L_count_1 = (W.begin() + w_end) - it; 
                
                dp_L = L_count_1;
                dp_R = 0; 
            } else if (i < n) {
                int p_prev = P[i-1], d_prev = D[i-1];
                int p_curr = P[i], d_curr = D[i];
                
                auto itR = upper_bound(W.begin() + w_start, W.begin() + w_end, p_prev + d_prev);
                int R_count_prev = itR - (W.begin() + w_start);
                
                auto itL = lower_bound(W.begin() + w_start, W.begin() + w_end, p_curr - d_curr);
                int L_count_curr = (W.begin() + w_end) - itL;
                
                int Both_count = min(S, R_count_prev + L_count_curr);
                
                int new_dp_L = max(dp_L + L_count_curr, dp_R + Both_count);
                int new_dp_R = max(dp_L + 0, dp_R + R_count_prev);
                
                dp_L = new_dp_L;
                dp_R = new_dp_R;
            } else {
                int p_last = P[n-1], d_last = D[n-1];
                
                auto itR = upper_bound(W.begin() + w_start, W.begin() + w_end, p_last + d_last);
                int R_count_last = itR - (W.begin() + w_start);
                
                int final_best = max(dp_L, dp_R + R_count_last);
                return final_best + unconditional_walls;
            }
        }
        
        return unconditional_walls;
    }
};

int main() {
    Solution sol;
    
    // Example 1
    vector<int> robots1 = {4};
    vector<int> distance1 = {3};
    vector<int> walls1 = {1, 10};
    cout << "Example 1 Output: " << sol.maxWalls(robots1, distance1, walls1) << " (Expected: 1)" << endl;

    // Example 2
    vector<int> robots2 = {10, 2};
    vector<int> distance2 = {5, 1};
    vector<int> walls2 = {5, 2, 7};
    cout << "Example 2 Output: " << sol.maxWalls(robots2, distance2, walls2) << " (Expected: 3)" << endl;

    // Example 3
    vector<int> robots3 = {1, 2};
    vector<int> distance3 = {100, 1};
    vector<int> walls3 = {10};
    cout << "Example 3 Output: " << sol.maxWalls(robots3, distance3, walls3) << " (Expected: 0)" << endl;
    
    return 0;
}
