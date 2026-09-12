#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        // Step 1: Augment each interval with its original index (l, r, weight, id)
        vector<tuple<int, int, int, int>> arr;
        for (int i = 0; i < n; i++) {
            int l = intervals[i][0], r = intervals[i][1],
                weight = intervals[i][2];
            arr.emplace_back(l, r, weight, i);
        }

        // Step 2: Sort intervals by right endpoint in ascending order
        sort(arr.begin(), arr.end(),
             [](auto&& a, auto&& b) { return get<1>(a) < get<1>(b); });

        // Step 3: Initialize DP tables for max weight sums and chosen index sets
        // dp[i][j] stores the max score choosing at most j intervals from the first i intervals
        // indices[i][j] stores the corresponding lexicographically smallest sorted index array
        vector<vector<long long>> dp(n + 1, vector<long long>(5));
        vector<vector<vector<int>>> indices(n + 1, vector<vector<int>>(5));

        // Step 4: Iterate through all intervals and compute DP transitions
        for (int i = 0; i < n; i++) {
            int l = get<0>(arr[i]);
            int r = get<1>(arr[i]);
            int weight = get<2>(arr[i]);
            int idx = get<3>(arr[i]);

            // Step 4.1: Use binary search to find the latest non-overlapping interval predecessor
            int k = lower_bound(arr.begin(), arr.begin() + i, l,
                                [](const tuple<int, int, int, int>& t,
                                   int val) { return get<1>(t) < val; }) -
                    arr.begin();

            // Step 5: Transition DP states for choosing at most j intervals (1 <= j <= 4)
            for (int j = 1; j < 5; j++) {
                long long s1 = dp[i][j];
                long long s2 = dp[k][j - 1] + weight;

                // Step 5.1: If excluding current interval gives strictly higher score
                if (s1 > s2) {
                    dp[i + 1][j] = dp[i][j];
                    indices[i + 1][j] = indices[i][j];
                    continue;
                }

                // Step 5.2: Form new candidate index array including current interval
                vector<int> newIndex = indices[k][j - 1];
                newIndex.push_back(idx);
                sort(newIndex.begin(), newIndex.end());

                // Step 5.3: Tie-breaking - if scores are equal, select lexicographically smaller index array
                if (s1 == s2 && indices[i][j] < newIndex) {
                    newIndex = indices[i][j];
                }

                dp[i + 1][j] = s2;
                indices[i + 1][j] = newIndex;
            }
        }

        // Step 6: Return the optimal lexicographically smallest index array for at most 4 intervals
        return indices[n][4];
    }

    // Aliases for compatibility
    vector<int> maxScore(vector<vector<int>>& intervals) {
        return maximumWeight(intervals);
    }

    vector<int> maximumScore(vector<vector<int>>& intervals) {
        return maximumWeight(intervals);
    }

    vector<int> maxScoreNonOverlappingIntervals(vector<vector<int>>& intervals) {
        return maximumWeight(intervals);
    }
};
