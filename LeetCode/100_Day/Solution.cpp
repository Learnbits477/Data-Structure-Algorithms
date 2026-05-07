#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class DSU {
    vector<int> parent;
    vector<int> max_val;
public:
    DSU(int n, const vector<int>& nums) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        max_val = nums;
    }

    int find(int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    }

    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            parent[root_i] = root_j;
            max_val[root_j] = max(max_val[root_j], max_val[root_i]);
        }
    }

    int get_max(int i) {
        return max_val[find(i)];
    }
};

class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return {};

        DSU dsu(n, nums);

        // suffix_min[i] stores the minimum element in nums[i...n-1]
        vector<int> suffix_min(n);
        suffix_min[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            suffix_min[i] = min(nums[i], suffix_min[i + 1]);
        }

        // prefix_max[i] stores the maximum element in nums[0...i]
        vector<int> prefix_max(n);
        prefix_max[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            prefix_max[i] = max(nums[i], prefix_max[i - 1]);
        }

        // An edge exists between a < b if nums[a] > nums[b].
        // This edge "bridges" all cuts from a to b-1.
        // A cut between i and i+1 is bridged if there exists some a <= i and b > i
        // such that nums[a] > nums[b], which is equivalent to prefix_max[i] > suffix_min[i+1].
        for (int i = 0; i < n - 1; ++i) {
            if (prefix_max[i] > suffix_min[i + 1]) {
                dsu.unite(i, i + 1);
            }
        }

        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            ans[i] = dsu.get_max(i);
        }
        return ans;
    }
};