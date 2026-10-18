#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumStep(int n) {
        int steps = 0;

        // Step: 01 - Traverse backwards from target n to origin 1
        while (n > 1) {
            // Step: 02 - If divisible by 3, dividing is strictly optimal
            if (n % 3 == 0) {
                n /= 3;
            } else {
                // Step: 03 - Otherwise, decrement by 1 to reach a multiple of 3
                n -= 1;
            }
            steps++;
        }

        // Step: 04 - Return the total minimal steps required
        return steps;
    }

    int minimumStepChunked(int n) {
        int steps = 0;

        // Step: 01 - Process steps in modulo 3 chunks for direct jumps
        while (n > 1) {
            if (n < 3) {
                steps += (n - 1);
                break;
            }

            if (n % 3 == 0) {
                n /= 3;
                steps++;
            } else {
                int rem = n % 3;
                steps += rem;
                n -= rem;
            }
        }

        // Step: 02 - Return aggregated steps
        return steps;
    }

    int minimumStepBFS(int n) {
        // Step: 01 - Standard forward BFS for verification on small n
        if (n <= 1) {
            return 0;
        }

        queue<pair<int, int>> q;
        unordered_set<int> visited;

        q.push({1, 0});
        visited.insert(1);

        while (!q.empty()) {
            pair<int, int> curr = q.front();
            q.pop();

            int val = curr.first;
            int dist = curr.second;

            if (val == n) {
                return dist;
            }

            // Step: 02 - Try transition 1: val * 3
            if (val <= n / 3 + 1) {
                int nextVal = val * 3;
                if (nextVal <= n && visited.find(nextVal) == visited.end()) {
                    if (nextVal == n) return dist + 1;
                    visited.insert(nextVal);
                    q.push({nextVal, dist + 1});
                }
            }

            // Step: 03 - Try transition 2: val + 1
            int nextVal = val + 1;
            if (nextVal <= n && visited.find(nextVal) == visited.end()) {
                if (nextVal == n) return dist + 1;
                visited.insert(nextVal);
                q.push({nextVal, dist + 1});
            }
        }

        return -1;
    }
};
