#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minOperations(string s, int k) {
        int n = s.length();
        int initial_zeros = 0;
        for (char c : s) {
            if (c == '0') initial_zeros++;
        }
        
        if (initial_zeros == 0) return 0;
        
        // DSU to keep track of the next unvisited state for even and odd parity
        vector<int> nxt[2];
        nxt[0].resize(n + 3);
        nxt[1].resize(n + 3);
        for (int c = 0; c < 2; ++c) {
            for (int i = 0; i <= n + 2; ++i) {
                nxt[c][i] = i;
            }
        }
        
        // Find function with path compression
        auto find = [&](auto& self, int pt, int i) -> int {
            if (nxt[pt][i] == i) return i;
            return nxt[pt][i] = self(self, pt, nxt[pt][i]);
        };
        
        vector<int> dist(n + 1, -1);
        queue<int> q;
        
        dist[initial_zeros] = 0;
        q.push(initial_zeros);
        
        int pt_initial = initial_zeros % 2;
        nxt[pt_initial][initial_zeros] = find(find, pt_initial, initial_zeros + 2);
        
        while (!q.empty()) {
            int d = q.front();
            q.pop();
            
            // Bounds for the number of '0's we can flip to '1's
            int min_x = max(0, d + k - n);
            int max_x = min(d, k);
            
            // Resulting number of 0s range
            int min_next = d + k - 2 * max_x;
            int max_next = d + k - 2 * min_x;
            
            int pt = min_next % 2;
            
            // Iterate over all unvisited states in the reachable range
            for (int v = find(find, pt, min_next); v <= max_next; v = find(find, pt, v)) {
                dist[v] = dist[d] + 1;
                
                // If we reach 0 zeros, we can return the distance immediately
                if (v == 0) return dist[v];
                
                q.push(v);
                
                // Mark current state v as visited by pointing it to the next unvisited of same parity
                nxt[pt][v] = find(find, pt, v + 2);
            }
        }
        
        return -1; // Unable to reach a state with 0 zeros
    }
};

int main() {
    Solution sol;

    // Example 1
    string s1 = "110";
    int k1 = 1;
    cout << "Input 1: s = \"" << s1 << "\", k = " << k1 << endl;
    cout << "Output 1: " << sol.minOperations(s1, k1) << endl;

    // Example 2
    string s2 = "0101";
    int k2 = 3;
    cout << "Input 2: s = \"" << s2 << "\", k = " << k2 << endl;
    cout << "Output 2: " << sol.minOperations(s2, k2) << endl;

    // Example 3
    string s3 = "101";
    int k3 = 2;
    cout << "Input 3: s = \"" << s3 << "\", k = " << k3 << endl;
    cout << "Output 3: " << sol.minOperations(s3, k3) << endl;

    return 0;
}
