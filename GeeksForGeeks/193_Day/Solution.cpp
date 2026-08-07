#include <vector>
#include <numeric>

using namespace std;

class Solution {
private:
    struct DSU {
        vector<int> parent;
        vector<int> rank;
        int numComponents;

        DSU(int n) {
            parent.resize(n);
            iota(parent.begin(), parent.end(), 0);
            rank.assign(n, 0);
            numComponents = n;
        }

        int findParent(int i) {
            if (parent[i] == i)
                return i;
            return parent[i] = findParent(parent[i]); // Path compression
        }

        bool unionSets(int i, int j) {
            int root_i = findParent(i);
            int root_j = findParent(j);

            if (root_i != root_j) {
                if (rank[root_i] < rank[root_j]) {
                    parent[root_i] = root_j;
                } else if (rank[root_i] > rank[root_j]) {
                    parent[root_j] = root_i;
                } else {
                    parent[root_j] = root_i;
                    rank[root_i]++;
                }
                numComponents--;
                return true;
            }
            return false;
        }
    };

public:
    int solve(int n, vector<vector<int>>& edges) {
        int m = edges.size();
        // A connected graph with n nodes requires at least n - 1 edges
        if (m < n - 1) {
            return -1;
        }

        DSU dsu(n);
        for (const auto& edge : edges) {
            dsu.unionSets(edge[0], edge[1]);
        }

        // The number of operations required to connect all components is (number of components - 1)
        return dsu.numComponents - 1;
    }

    int Solve(int n, vector<vector<int>>& adj) {
        return solve(n, adj);
    }

    int minEdgesReq(int n, vector<vector<int>>& adj) {
        return solve(n, adj);
    }
};
