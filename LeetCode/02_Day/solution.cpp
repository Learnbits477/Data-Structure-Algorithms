#include <vector>
#include <string>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        const long long INF = LLONG_MAX;
        vector<vector<long long>> minCost(26, vector<long long>(26, INF));

        // Initialize diagonal with 0
        for (int i = 0; i < 26; ++i) {
            minCost[i][i] = 0;
        }

        // Fill initial costs
        for (size_t i = 0; i < original.size(); ++i) {
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            minCost[u][v] = min(minCost[u][v], (long long)cost[i]);
        }

        // Floyd-Warshall Algorithm
        for (int k = 0; k < 26; ++k) {
            for (int i = 0; i < 26; ++i) {
                for (int j = 0; j < 26; ++j) {
                    if (minCost[i][k] != INF && minCost[k][j] != INF) {
                        minCost[i][j] = min(minCost[i][j], minCost[i][k] + minCost[k][j]);
                    }
                }
            }
        }

        long long totalCost = 0;
        for (size_t i = 0; i < source.length(); ++i) {
            if (source[i] == target[i]) continue;
            
            int u = source[i] - 'a';
            int v = target[i] - 'a';
            
            if (minCost[u][v] == INF) {
                return -1;
            }
            totalCost += minCost[u][v];
        }

        return totalCost;
    }
};