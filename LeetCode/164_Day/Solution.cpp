#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        // Step 1: Sorting and Index Mapping
        vector<pair<int, int>> sortedNumAndIndexes(n);
        for (int i = 0; i < n; ++i) {
            sortedNumAndIndexes[i] = {nums[i], i};
        }
        sort(sortedNumAndIndexes.begin(), sortedNumAndIndexes.end());

        vector<int> sortedNums(n), indexMap(n);
        for (int i = 0; i < n; ++i) {
            sortedNums[i] = sortedNumAndIndexes[i].first;
            indexMap[sortedNumAndIndexes[i].second] = i;
        }

        // Step 2: Precomputing Component Labels
        vector<int> comp(n, 0);
        int curr_comp = 0;
        for (int i = 1; i < n; ++i) {
            if (sortedNums[i] - sortedNums[i - 1] > maxDiff) {
                curr_comp++;
            }
            comp[i] = curr_comp;
        }

        // Step 3: Precomputing Binary Lifting Jump Table
        vector<vector<int>> jump(n, vector<int>(18));
        int right = 0;
        for (int i = 0; i < n; ++i) {
            while (right + 1 < n && sortedNums[right + 1] - sortedNums[i] <= maxDiff) {
                ++right;
            }
            jump[i][0] = right;
        }
        
        for (int level = 1; level < 18; ++level) {
            for (int i = 0; i < n; ++i) {
                jump[i][level] = jump[jump[i][level - 1]][level - 1];
            }
        }

        // Step 4: Answering Queries with Binary Lifting
        vector<int> ans;
        ans.reserve(queries.size());
        for (const auto& q : queries) {
            int u = indexMap[q[0]];
            int v = indexMap[q[1]];
            if (u == v) {
                ans.push_back(0);
                continue;
            }
            if (u > v) swap(u, v);
            
            if (comp[u] != comp[v]) {
                ans.push_back(-1);
                continue;
            }
            
            int curr = u;
            int steps = 0;
            for (int level = 17; level >= 0; --level) {
                if (jump[curr][level] < v) {
                    curr = jump[curr][level];
                    steps += (1 << level);
                }
            }
            ans.push_back(steps + 1);
        }

        return ans;
    }
};
