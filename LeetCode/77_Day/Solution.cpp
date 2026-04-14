#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
    long long solve(int robotIdx, int factoryIdx, const vector<int>& robot, const vector<int>& factorySlots, vector<vector<long long>>& memo) {
        if (robotIdx == robot.size()) return 0;
        if (factoryIdx == factorySlots.size()) return 1e16; // Safely larger than max possible limit

        if (memo[robotIdx][factoryIdx] != -1) {
            return memo[robotIdx][factoryIdx];
        }

        // Choice 1: Skip the current factory slot.
        long long skipFactory = solve(robotIdx, factoryIdx + 1, robot, factorySlots, memo);
        
        // Choice 2: Assign current robot to current factory slot.
        long long useFactory = abs((long long)robot[robotIdx] - factorySlots[factoryIdx]) + solve(robotIdx + 1, factoryIdx + 1, robot, factorySlots, memo);

        return memo[robotIdx][factoryIdx] = min(skipFactory, useFactory);
    }

public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        // Sort to ensure monotonic mappings
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        // Flatten factory slots
        vector<int> factorySlots;
        for (const auto& f : factory) {
            int pos = f[0];
            int limit = min(f[1], (int)robot.size()); // Optimization: factory slots won't exceed total robots
            for (int i = 0; i < limit; ++i) {
                factorySlots.push_back(pos);
            }
        }

        // DP cache
        vector<vector<long long>> memo(robot.size(), vector<long long>(factorySlots.size(), -1));

        return solve(0, 0, robot, factorySlots, memo);
    }
};
