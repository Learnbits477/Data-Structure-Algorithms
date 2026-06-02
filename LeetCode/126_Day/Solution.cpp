#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        // Step 1: Initialize Minimum Finish Time
        int minFinishTime = INT_MAX;
        int n = landStartTime.size();
        int m = waterStartTime.size();
        
        // Step 2: Iterate Land Rides
        for (int i = 0; i < n; ++i) {
            // Step 3: Iterate Water Rides
            for (int j = 0; j < m; ++j) {
                // Step 4: Calculate Land First Ordering
                int finishLand = landStartTime[i] + landDuration[i];
                int startWater = max(finishLand, waterStartTime[j]);
                int timeLandFirst = startWater + waterDuration[j];
                
                // Step 5: Calculate Water First Ordering
                int finishWater = waterStartTime[j] + waterDuration[j];
                int startLand = max(finishWater, landStartTime[i]);
                int timeWaterFirst = startLand + landDuration[i];
                
                // Step 6: Update Minimum
                minFinishTime = min({minFinishTime, timeLandFirst, timeWaterFirst});
            }
        }
        
        // Step 7: Return Result
        return minFinishTime;
    }
};
