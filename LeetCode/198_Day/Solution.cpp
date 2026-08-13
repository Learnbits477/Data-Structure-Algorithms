#include <bits/stdc++.h>

using namespace std;

// Step 1: Define the Node Structure
struct Node {
    int max_len;
    int pref_len;
    char pref_char;
    int suff_len;
    char suff_char;
    int size;
};

// Step 2: Implement the Node Merging Function
Node merge(const Node& left, const Node& right) {
    Node parent;
    parent.size = left.size + right.size;
    
    // Prefix character inherits from left
    parent.pref_char = left.pref_char;
    if (left.pref_len == left.size && left.pref_char == right.pref_char) {
        parent.pref_len = left.size + right.pref_len;
    } else {
        parent.pref_len = left.pref_len;
    }
    
    // Suffix character inherits from right
    parent.suff_char = right.suff_char;
    if (right.suff_len == right.size && right.suff_char == left.suff_char) {
        parent.suff_len = right.size + left.suff_len;
    } else {
        parent.suff_len = right.suff_len;
    }
    
    // Max length is the best of left, right, and boundary combination
    parent.max_len = max(left.max_len, right.max_len);
    if (left.suff_char == right.pref_char) {
        parent.max_len = max(parent.max_len, left.suff_len + right.pref_len);
    }
    
    return parent;
}

class SegmentTree {
private:
    int n;
    vector<Node> tree;

    // Step 3: Build the Segment Tree
    void build(int node, int start, int end, const string& s) {
        if (start == end) {
            tree[node] = {1, 1, s[start], 1, s[start], 1};
            return;
        }
        int mid = start + (end - start) / 2;
        build(2 * node, start, mid, s);
        build(2 * node + 1, mid + 1, end, s);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    // Step 4: Perform Point Updates
    void update(int node, int start, int end, int idx, char val) {
        if (start == end) {
            tree[node] = {1, 1, val, 1, val, 1};
            return;
        }
        int mid = start + (end - start) / 2;
        if (idx <= mid) {
            update(2 * node, start, mid, idx, val);
        } else {
            update(2 * node + 1, mid + 1, end, idx, val);
        }
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

public:
    SegmentTree(const string& s) {
        n = s.length();
        tree.resize(4 * n);
        build(1, 0, n - 1, s);
    }

    void update(int idx, char val) {
        update(1, 0, n - 1, idx, val);
    }

    // Step 5: Retrieve Query Results
    int get_max_len() const {
        return tree[1].max_len;
    }
};

class Solution {
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int k = queryIndices.size();
        SegmentTree st(s);
        vector<int> ans(k);
        for (int i = 0; i < k; ++i) {
            st.update(queryIndices[i], queryCharacters[i]);
            ans[i] = st.get_max_len();
        }
        return ans;
    }
};
