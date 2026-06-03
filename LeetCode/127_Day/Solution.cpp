#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size();
        int m = waterStartTime.size();
        
        // Step 1: Find Minimum Land End Time
        int minLandEnd = INT_MAX;
        for (int i = 0; i < n; ++i) {
            minLandEnd = min(minLandEnd, landStartTime[i] + landDuration[i]);
        }
        
        // Step 2: Find Minimum Water End Time
        int minWaterEnd = INT_MAX;
        for (int j = 0; j < m; ++j) {
            minWaterEnd = min(minWaterEnd, waterStartTime[j] + waterDuration[j]);
        }
        
        // Step 3: Evaluate Land-then-Water Strategy
        int bestLW = INT_MAX;
        for (int j = 0; j < m; ++j) {
            int waterEnd = waterStartTime[j] + waterDuration[j];
            int finishTime = max(minLandEnd + waterDuration[j], waterEnd);
            bestLW = min(bestLW, finishTime);
        }
        
        // Step 4: Evaluate Water-then-Land Strategy
        int bestWL = INT_MAX;
        for (int i = 0; i < n; ++i) {
            int landEnd = landStartTime[i] + landDuration[i];
            int finishTime = max(minWaterEnd + landDuration[i], landEnd);
            bestWL = min(bestWL, finishTime);
        }
        
        // Step 5: Return Optimal Strategy
        return min(bestLW, bestWL);
    }
};
