#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <cassert>

using namespace std;

class Solution {
    const long long INF = 1e18;

public:
    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
        int n = source.length();
        
        // Map to store graph for each length
        // length -> { strict -> ID }
        // We actually need a way to map string -> ID for each length group
        unordered_map<int, unordered_map<string, int>> lengthGroups;
        unordered_map<int, vector<vector<long long>>> lengthCosts;
        unordered_map<int, int> lengthCounts; // store Next ID for each length
        
        // 1. Group unique strings by length and assign IDs
        int m = original.size();
        for (int i = 0; i < m; ++i) {
            int len = original[i].length();
            if (lengthGroups.find(len) == lengthGroups.end()) {
                lengthGroups[len] = unordered_map<string, int>();
                lengthCounts[len] = 0;
            }
            if (lengthGroups[len].find(original[i]) == lengthGroups[len].end()) {
                lengthGroups[len][original[i]] = lengthCounts[len]++;
            }
            if (lengthGroups[len].find(changed[i]) == lengthGroups[len].end()) {
                lengthGroups[len][changed[i]] = lengthCounts[len]++;
            }
        }
        
        // 2. Build Graphs and Compute Floyd-Warshall for each length
        for (auto& entry : lengthGroups) {
            int len = entry.first;
            int count = lengthCounts[len];
            
            // Initialize adjacency matrix with INF
            lengthCosts[len] = vector<vector<long long>>(count, vector<long long>(count, INF));
            for (int i = 0; i < count; ++i) lengthCosts[len][i][i] = 0;
        }
        
        // Populate initial costs
        for (int i = 0; i < m; ++i) {
            int len = original[i].length();
            int u = lengthGroups[len][original[i]];
            int v = lengthGroups[len][changed[i]];
            long long c = cost[i];
            lengthCosts[len][u][v] = min(lengthCosts[len][u][v], c);
        }
        
        // Run Floyd-Warshall
        for (auto& entry : lengthCosts) {
            int len = entry.first;
            vector<vector<long long>>& dist = entry.second;
            int count = lengthCounts[len];
            
            for (int k = 0; k < count; ++k) {
                for (int i = 0; i < count; ++i) {
                    if (dist[i][k] == INF) continue;
                    for (int j = 0; j < count; ++j) {
                        if (dist[k][j] == INF) continue;
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }
        
        // 3. Dynamic Programming
        vector<long long> dp(n + 1, INF);
        dp[0] = 0;
        
        // Collect all distinct lengths we need to check
        vector<int> distinctLengths;
        for(auto const& entry : lengthGroups) {
            distinctLengths.push_back(entry.first);
        }
        
        for (int i = 1; i <= n; ++i) {
            // Option 1: Character match (cost 0)
            if (source[i-1] == target[i-1]) {
                if (dp[i-1] != INF) {
                     dp[i] = min(dp[i], dp[i-1]);
                }
            }
            
            // Option 2: Substring transformation
            for (int len : distinctLengths) {
                if (i >= len) {
                    if (dp[i-len] == INF) continue;
                    
                    // Optimization: avoid substring extraction if we can't possibly match
                    // Using hashing or tries could be faster but constraints source.len <= 1000 allow substring.
                    string sub_s = source.substr(i - len, len);
                    string sub_t = target.substr(i - len, len);
                    
                    // Look up IDs
                    auto& group = lengthGroups[len];
                    if (group.count(sub_s) && group.count(sub_t)) {
                        int u = group[sub_s];
                        int v = group[sub_t];
                        long long transformCost = lengthCosts[len][u][v];
                        if (transformCost != INF) {
                            dp[i] = min(dp[i], dp[i-len] + transformCost);
                        }
                    }
                }
            }
        }
        
        return (dp[n] == INF) ? -1 : dp[n];
    }
};

void runTest(string source, string target, vector<string> original, vector<string> changed, vector<int> cost, long long expected) {
    Solution sol;
    long long result = sol.minimumCost(source, target, original, changed, cost);
    cout << "Test Case: " << (result == expected ? "PASSED" : "FAILED") << endl;
    cout << "Expected: " << expected << ", Got: " << result << endl;
    if (result != expected) {
        cout << "Source: " << source << ", Target: " << target << endl;
    }
    cout << "-----------------------------------" << endl;
}

int main() {
    // Example 1
    runTest("abcd", "acbe", 
            {"a","b","c","c","e","d"}, 
            {"b","c","b","e","b","e"}, 
            {2,5,5,1,2,20}, 
            28);

    // Example 2
    runTest("abcdefgh", "acdeeghh", 
            {"bcd","fgh","thh"}, 
            {"cde","thh","ghh"}, 
            {1,3,5}, 
            9);

    // Example 3
    runTest("abcdefgh", "addddddd", 
            {"bcd","defgh"}, 
            {"ddd","ddddd"}, 
            {100,1578}, 
            -1);
            
    return 0;
}
