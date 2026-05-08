#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minJumps(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;

        int max_val = 0;
        for (int x : nums) max_val = max(max_val, x);

        // Sieve and SPF
        vector<int> spf(max_val + 1, 0);
        vector<bool> is_prime(max_val + 1, true);
        is_prime[0] = is_prime[1] = false;

        for (int i = 2; i <= max_val; ++i) {
            if (is_prime[i]) {
                spf[i] = i;
                if (1LL * i * i <= max_val) {
                    for (int j = i * i; j <= max_val; j += i) {
                        if (is_prime[j]) {
                            is_prime[j] = false;
                            spf[j] = i;
                        }
                    }
                }
            }
        }

        // Map each prime to indices of nums it divides
        vector<vector<int>> prime_to_indices(max_val + 1);
        for (int i = 0; i < n; ++i) {
            int val = nums[i];
            while (val > 1) {
                int p = spf[val];
                prime_to_indices[p].push_back(i);
                while (val % p == 0) val /= p;
            }
        }

        // BFS
        queue<int> q;
        vector<int> dist(n, -1);
        vector<bool> visited_prime(max_val + 1, false);

        q.push(0);
        dist[0] = 0;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            if (curr == n - 1) return dist[curr];

            // 1. Adjacent Steps
            for (int next_idx : {curr - 1, curr + 1}) {
                if (next_idx >= 0 && next_idx < n && dist[next_idx] == -1) {
                    dist[next_idx] = dist[curr] + 1;
                    q.push(next_idx);
                }
            }

            // 2. Prime Teleportation
            int val = nums[curr];
            if (val <= max_val && is_prime[val]) {
                int p = val;
                if (!visited_prime[p]) {
                    visited_prime[p] = true;
                    for (int target_idx : prime_to_indices[p]) {
                        if (dist[target_idx] == -1) {
                            dist[target_idx] = dist[curr] + 1;
                            q.push(target_idx);
                        }
                    }
                }
            }
        }

        return -1; // Should not be reached based on problem constraints
    }
};
