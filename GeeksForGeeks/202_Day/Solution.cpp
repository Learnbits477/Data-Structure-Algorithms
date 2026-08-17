#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minThrows(int n, vector<int> &lad, vector<int> &sn) {
        // Step 1: Initialize the Board mapping
        int target = n * n;
        
        unordered_map<int, int> board;
        
        for (int i = 0; i < (int)lad.size(); i += 2) {
            board[lad[i]] = lad[i + 1];
        }
        for (int i = 0; i < (int)sn.size(); i += 2) {
            board[sn[i]] = sn[i + 1];
        }
        
        // Step 2: Setup BFS queue and visited tracking
        queue<pair<int, int>> q;
        q.push(make_pair(1, 0));
        
        vector<bool> visited(target + 1, false);
        visited[1] = true;
        
        // Step 3: Traverse Using BFS
        while (!q.empty()) {
            auto curr_pair = q.front();
            int curr = curr_pair.first;
            int throws = curr_pair.second;
            q.pop();
            
            // If target is reached
            if (curr == target) {
                return throws;
            }
            
            // Step 4: Determine Next Moves (Roll dice 1 to 6)
            for (int dice = 1; dice <= 6; ++dice) {
                int next_cell = curr + dice;
                
                if (next_cell > target) continue;
                
                // Check for ladder or snake
                auto it = board.find(next_cell);
                if (it != board.end()) {
                    next_cell = it->second;
                }
                
                // Step 5: Update Queue if not visited
                if (!visited[next_cell]) {
                    visited[next_cell] = true;
                    q.push(make_pair(next_cell, throws + 1));
                }
            }
        }
        
        return -1;
    }
};
