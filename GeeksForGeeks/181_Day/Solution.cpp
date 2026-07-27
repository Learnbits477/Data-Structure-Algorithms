#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
private:
    Node* constructTree(const vector<int>& pre, const vector<int>& preMirror, 
                        unordered_map<int, int>& mp, int& preIndex, int start, int end) {
        if (preIndex >= pre.size() || start > end) {
            return nullptr;
        }

        Node* root = new Node(pre[preIndex++]);

        if (start == end) {
            return root;
        }

        int idx = mp[pre[preIndex]];

        // Step 2: Recursive Tree Construction
        root->left = constructTree(pre, preMirror, mp, preIndex, idx, end);
        root->right = constructTree(pre, preMirror, mp, preIndex, start + 1, idx - 1);

        return root;
    }

public:
    Node* constructBinaryTree(vector<int>& pre, vector<int>& preMirror) {
        // Step 1: Precalculate Index Map
        unordered_map<int, int> mp;
        int n = pre.size();
        for (int i = 0; i < n; i++) {
            mp[preMirror[i]] = i;
        }

        int preIndex = 0;
        return constructTree(pre, preMirror, mp, preIndex, 0, n - 1);
    }
};
