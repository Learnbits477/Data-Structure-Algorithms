#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        // Step 1 — Sort the Intervals
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0]) {
                return a[1] > b[1]; // Descending end points
            }
            return a[0] < b[0]; // Ascending start points
        });
        
        // Step 2 — Initialize Counters and Trackers
        int maxEnd = 0;
        int remainingCount = 0;
        
        // Step 3 — Iterate and Filter Covered Intervals
        for (const auto& curr : intervals) {
            if (curr[1] > maxEnd) {
                remainingCount++;
                maxEnd = curr[1];
            }
        }
        
        // Step 4 — Return the Count
        return remainingCount;
    }
};
