#include <vector>
#include <unordered_set>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<long long> obsSet;
        for (const auto& obs : obstacles) {
            long long x = obs[0] + 30000;
            long long y = obs[1] + 30000;
            obsSet.insert(x * 100000LL + y);
        }

        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        
        int x = 0, y = 0, di = 0;
        int maxDistSq = 0;

        for (int cmd : commands) {
            if (cmd == -2) {
                di = (di + 3) % 4; // Turn left
            } else if (cmd == -1) {
                di = (di + 1) % 4; // Turn right
            } else {
                for (int k = 0; k < cmd; ++k) {
                    int nx = x + dx[di];
                    int ny = y + dy[di];
                    
                    long long nHash = (nx + 30000) * 100000LL + (ny + 30000);
                    if (obsSet.count(nHash)) {
                        break; // Obstacle encountered
                    }
                    x = nx;
                    y = ny;
                    maxDistSq = max(maxDistSq, x * x + y * y);
                }
            }
        }
        return maxDistSq;
    }
};

int main() {
    Solution sol;
    
    // Example 1
    vector<int> commands1 = {4, -1, 3};
    vector<vector<int>> obstacles1 = {};
    cout << "Example 1 Output: " << sol.robotSim(commands1, obstacles1) << " (Expected: 25)" << endl;

    // Example 2
    vector<int> commands2 = {4, -1, 4, -2, 4};
    vector<vector<int>> obstacles2 = {{2, 4}};
    cout << "Example 2 Output: " << sol.robotSim(commands2, obstacles2) << " (Expected: 65)" << endl;
    
    // Example 3
    vector<int> commands3 = {6, -1, -1, 6};
    vector<vector<int>> obstacles3 = {{0, 0}};
    cout << "Example 3 Output: " << sol.robotSim(commands3, obstacles3) << " (Expected: 36)" << endl;

    return 0;
}
