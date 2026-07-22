#include <bits/stdc++.h>
using namespace std;

class Solution {
    struct Block {
        int start, end;
        int L, R;
        int static_gain;
    };
    
    // Portable log2 floor function
    int log2_floor(int n) {
        int ans = 0;
        while (n >>= 1) ans++;
        return ans;
    }
    
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int n = s.length();
        int total_ones = 0;
        for (char c : s) {
            if (c == '1') total_ones++;
        }
        
        // Group s into blocks
        vector<pair<char, pair<int, int>>> blocks;
        int i = 0;
        while (i < n) {
            char val = s[i];
            int start = i;
            while (i < n && s[i] == val) {
                i++;
            }
            blocks.push_back({val, {start, i - 1}});
        }
        
        // Identify '1' blocks surrounded by '0's
        vector<Block> candidates;
        int m = blocks.size();
        for (int j = 1; j < m - 1; ++j) {
            if (blocks[j].first == '1' && blocks[j - 1].first == '0' && blocks[j + 1].first == '0') {
                Block b;
                b.start = blocks[j].second.first;
                b.end = blocks[j].second.second;
                b.L = blocks[j - 1].second.first;
                b.R = blocks[j + 1].second.second;
                b.static_gain = b.R - b.L - (b.end - b.start);
                candidates.push_back(b);
            }
        }
        
        int num_cands = candidates.size();
        if (num_cands == 0) {
            vector<int> ans(queries.size(), total_ones);
            return ans;
        }
        
        // Build Sparse Table for static_gain range max query
        int max_log = log2_floor(num_cands) + 1;
        vector<vector<int>> st(num_cands, vector<int>(max_log));
        for (int j = 0; j < num_cands; ++j) {
            st[j][0] = candidates[j].static_gain;
        }
        for (int k = 1; k < max_log; ++k) {
            for (int j = 0; j + (1 << k) <= num_cands; ++j) {
                st[j][k] = max(st[j][k - 1], st[j + (1 << (k - 1))][k - 1]);
            }
        }
        
        auto query_st = [&](int l, int r) {
            if (l > r) return 0;
            int len = r - l + 1;
            int k = log2_floor(len);
            return max(st[l][k], st[r - (1 << k) + 1][k]);
        };
        
        // Arrays for binary searching
        vector<int> start_minus_one(num_cands);
        vector<int> end_plus_one(num_cands);
        for (int j = 0; j < num_cands; ++j) {
            start_minus_one[j] = candidates[j].start - 1;
            end_plus_one[j] = candidates[j].end + 1;
        }
        
        vector<int> ans;
        ans.reserve(queries.size());
        
        for (const auto& q : queries) {
            int li = q[0], ri = q[1];
            
            // Find j_min: smallest j with start_j - 1 >= li
            int j_min = lower_bound(start_minus_one.begin(), start_minus_one.end(), li) - start_minus_one.begin();
            // Find j_max: largest j with end_j + 1 <= ri
            int j_max = upper_bound(end_plus_one.begin(), end_plus_one.end(), ri) - end_plus_one.begin() - 1;
            
            if (j_min > j_max) {
                ans.push_back(total_ones);
            } else if (j_min == j_max) {
                int gain = min(ri, candidates[j_min].R) - max(li, candidates[j_min].L) - (candidates[j_min].end - candidates[j_min].start);
                ans.push_back(total_ones + max(0, gain));
            } else {
                // j_min < j_max
                int g1 = candidates[j_min].R - max(li, candidates[j_min].L) - (candidates[j_min].end - candidates[j_min].start);
                int g2 = min(ri, candidates[j_max].R) - candidates[j_max].L - (candidates[j_max].end - candidates[j_max].start);
                int g3 = query_st(j_min + 1, j_max - 1);
                int max_gain = max({0, g1, g2, g3});
                ans.push_back(total_ones + max_gain);
            }
        }
        
        return ans;
    }

    // Alias for compatibility
    vector<int> maxActiveSections(string s, vector<vector<int>>& queries) {
        return maxActiveSectionsAfterTrade(s, queries);
    }
};
