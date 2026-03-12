#include <bits/stdc++.h>
using namespace std;

class Solution {
    struct DSU {
        vector<int> parent;
        int comps;
        DSU(int n) : comps(n) {
            parent.resize(n);
            iota(parent.begin(), parent.end(), 0);
        }
        int find(int i) {
            if (parent[i] == i)
                return i;
            return parent[i] = find(parent[i]);
        }
        bool unite(int i, int j) {
            int root_i = find(i);
            int root_j = find(j);
            if (root_i != root_j) {
                parent[root_i] = root_j;
                comps--;
                return true;
            }
            return false;
        }
    };

public:
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        DSU base_dsu(n);
        int min_must = INT_MAX;
        
        vector<vector<int>> optional_edges;
        for (const auto& e : edges) {
            int u = e[0], v = e[1], s = e[2], must = e[3];
            if (must == 1) {
                if (!base_dsu.unite(u, v)) {
                    // cycle in must edges means spanning tree is impossible
                    return -1;
                }
                min_must = min(min_must, s);
            } else {
                optional_edges.push_back({u, v, s});
            }
        }
        
        if (base_dsu.comps == 1) { // completely connected by mandatory edges
            return min_must;
        }
        
        // Initial check if we can even connect all nodes
        DSU all_dsu = base_dsu;
        long long max_s = 0;
        for (const auto& e : optional_edges) {
            all_dsu.unite(e[0], e[1]);
            max_s = max(max_s, (long long)e[2]);
        }
        
        if (all_dsu.comps > 1) { // unable to connect nodes even with all edges
            return -1;
        }
        
        long long low = 1;
        long long high = 2LL * max_s;
        if (min_must != INT_MAX) {
            high = min(high, (long long)min_must);
        }
        
        long long ans = -1;
        
        auto check = [&](long long x) {
            DSU dsu = base_dsu;
            int cost1_count = 0;
            
            // Pass 1: Cost 0 edges (strength >= x)
            for (const auto& e : optional_edges) {
                if (e[2] >= x) {
                    dsu.unite(e[0], e[1]);
                }
            }
            
            // Pass 2: Cost 1 edges (strength * 2 >= x && strength < x)
            for (const auto& e : optional_edges) {
                if (e[2] * 2LL >= x && e[2] < x) {
                    if (dsu.unite(e[0], e[1])) {
                        cost1_count++;
                    }
                }
            }
            
            return dsu.comps == 1 && cost1_count <= k;
        };
        
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (check(mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return ans;
    }
};

int main() {
    Solution sol;
    
    // Example 1
    int n1 = 3;
    vector<vector<int>> edges1 = {{0,1,2,1}, {1,2,3,0}};
    int k1 = 1;
    cout << "Example 1 Output: " << sol.maxStability(n1, edges1, k1) << " (Expected: 2)" << endl;
    
    // Example 2
    int n2 = 3;
    vector<vector<int>> edges2 = {{0,1,4,0}, {1,2,3,0}, {0,2,1,0}};
    int k2 = 2;
    cout << "Example 2 Output: " << sol.maxStability(n2, edges2, k2) << " (Expected: 6)" << endl;
    
    // Example 3
    int n3 = 3;
    vector<vector<int>> edges3 = {{0,1,1,1}, {1,2,1,1}, {2,0,1,1}};
    int k3 = 0;
    cout << "Example 3 Output: " << sol.maxStability(n3, edges3, k3) << " (Expected: -1)" << endl;
    
    return 0;
}
