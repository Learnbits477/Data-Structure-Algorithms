/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int sumRootToLeaf(TreeNode* root) {
        function<int(TreeNode*, int)> dfs = [&](TreeNode* node, int current) -> int {
            if (!node) return 0;
            current = (current << 1) | node->val;
            if (!node->left && !node->right) return current;
            return dfs(node->left, current) + dfs(node->right, current);
        };
        return dfs(root, 0);
    }
};

int main() {
    Solution sol;

    // [1,0,1,0,1,0,1] => 22
    TreeNode* r1 = new TreeNode(1,
        new TreeNode(0, new TreeNode(0), new TreeNode(1)),
        new TreeNode(1, new TreeNode(0), new TreeNode(1)));
    cout << "Example 1: " << sol.sumRootToLeaf(r1) << " (Expected: 22)" << endl;

    // [0] => 0
    TreeNode* r2 = new TreeNode(0);
    cout << "Example 2: " << sol.sumRootToLeaf(r2) << " (Expected: 0)" << endl;

    // [1,1,1] => 7
    TreeNode* r3 = new TreeNode(1, new TreeNode(1, new TreeNode(1), nullptr), nullptr);
    cout << "Example 3: " << sol.sumRootToLeaf(r3) << " (Expected: 7)" << endl;

    return 0;
}

