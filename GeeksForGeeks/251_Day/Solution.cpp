#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> socialNetwork(vector<int> &arr) {
        // Step: 01 - Compute total users count and allocate result container
        int n = arr.size() + 1;
        vector<vector<int>> ans;

        // Step: 02 - Iterate through each user from 2 to n
        for (int i = 2; i <= n; ++i) {
            vector<int> dist(n + 1, 0);
            int curr = i;
            int distance = 0;

            // Step: 03 - Trace chain of friends until reaching user 1
            while (curr != 1) {
                curr = arr[curr - 2];
                distance++;
                dist[curr] = distance;
            }

            // Step: 04 - Collect reachable users in strictly increasing order of j
            for (int j = 1; j < i; ++j) {
                if (dist[j] > 0) {
                    ans.push_back({i, j, dist[j]});
                }
            }
        }

        // Step: 05 - Return accumulated reachable pairs
        return ans;
    }

    vector<vector<int>> socialNetworkDP(vector<int> &arr) {
        // Step: 01 - Determine total users and initialize DP distance table
        int n = arr.size() + 1;
        vector<vector<int>> dist(n + 1, vector<int>(n + 1, 0));
        vector<vector<int>> ans;

        // Step: 02 - Propagate distances from direct friend and existing connections
        for (int i = 2; i <= n; ++i) {
            int friendNode = arr[i - 2];
            dist[i][friendNode] = 1;

            for (int j = 1; j < friendNode; ++j) {
                if (dist[friendNode][j] > 0) {
                    dist[i][j] = dist[friendNode][j] + 1;
                }
            }

            // Step: 03 - Append all valid reachable connections in ascending order
            for (int j = 1; j < i; ++j) {
                if (dist[i][j] > 0) {
                    ans.push_back({i, j, dist[i][j]});
                }
            }
        }

        // Step: 04 - Return compiled DP result
        return ans;
    }
};
