#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int dfs(int u, int n, const vector<int>& arr, vector<int>& state) {
        // Step: 01 - Base boundary check for escaping array limits
        if (u < 0 || u >= n) {
            return 2;
        }

        // Step: 02 - Return already computed terminal memoized states
        if (state[u] == 2 || state[u] == 3) {
            return state[u];
        }

        // Step: 03 - Detect back-edge indicating active cycle
        if (state[u] == 1) {
            return 3;
        }

        // Step: 04 - Detect zero-jump dead end self-loop
        if (arr[u] == 0) {
            state[u] = 3;
            return 3;
        }

        // Step: 05 - Mark current vertex as visiting in active recursion path
        state[u] = 1;

        // Step: 06 - Recursively traverse to next jump destination
        long long nextPos = (long long)u + arr[u];
        int res = (nextPos < 0 || nextPos >= n) ? 2 : dfs((int)nextPos, n, arr, state);

        // Step: 07 - Memoize and propagate classification
        state[u] = (res == 2) ? 2 : 3;
        return state[u];
    }

public:
    int goodStones(int n, vector<int>& arr) {
        // Step: 01 - Allocate state table initialized to unvisited
        vector<int> state(n, 0);

        // Step: 02 - Run DFS cycle-memoization from all unvisited nodes
        for (int i = 0; i < n; i++) {
            if (state[i] == 0) {
                dfs(i, n, arr, state);
            }
        }

        // Step: 03 - Count indices marked with good terminal state
        int goodCount = 0;
        for (int i = 0; i < n; i++) {
            if (state[i] == 2) {
                goodCount++;
            }
        }

        // Step: 04 - Return total count of good stones
        return goodCount;
    }

    int goodIndices(vector<int>& arr) {
        // Step: 01 - Delegate to primary solver using vector size
        return goodStones((int)arr.size(), arr);
    }

    int goodIndices(int n, vector<int>& arr) {
        // Step: 01 - Delegate to primary solver with explicit size
        return goodStones(n, arr);
    }

    int goodStones(vector<int>& arr) {
        // Step: 01 - Delegate to primary solver using vector size
        return goodStones((int)arr.size(), arr);
    }

    int countGoodIndices(vector<int>& arr) {
        // Step: 01 - Provide alias method for alternate problem titles
        return goodStones((int)arr.size(), arr);
    }

    int goodStonesIterative(int n, vector<int>& arr) {
        // Step: 01 - Allocate state array for iterative path simulation
        vector<int> state(n, 0);

        // Step: 02 - Simulate jump paths without call stack recursion
        for (int i = 0; i < n; i++) {
            if (state[i] != 0) continue;

            vector<int> path;
            long long curr = i;

            while (curr >= 0 && curr < n && state[(int)curr] == 0) {
                state[(int)curr] = 1;
                path.push_back((int)curr);
                if (arr[(int)curr] == 0) break;
                curr += arr[(int)curr];
            }

            int finalState = 3;
            if (curr < 0 || curr >= n || state[(int)curr] == 2) {
                finalState = 2;
            }

            for (int node : path) {
                state[node] = finalState;
            }
        }

        // Step: 03 - Count all nodes with good state
        int count = 0;
        for (int s : state) {
            if (s == 2) count++;
        }

        // Step: 04 - Return count from iterative evaluation
        return count;
    }

    int goodStonesBFS(int n, vector<int>& arr) {
        // Step: 01 - Build reverse graph adjacency list
        vector<vector<int>> revAdj(n);
        queue<int> q;
        vector<bool> escapes(n, false);

        // Step: 02 - Identify all immediate escape transitions
        for (int i = 0; i < n; i++) {
            long long nxt = (long long)i + arr[i];
            if (nxt < 0 || nxt >= n) {
                escapes[i] = true;
                q.push(i);
            } else if (arr[i] != 0) {
                revAdj[(int)nxt].push_back(i);
            }
        }

        // Step: 03 - Propagate backwards through reverse graph
        int count = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            count++;

            for (int prev : revAdj[u]) {
                if (!escapes[prev]) {
                    escapes[prev] = true;
                    q.push(prev);
                }
            }
        }

        // Step: 04 - Return total count of reachable good nodes
        return count;
    }
};
