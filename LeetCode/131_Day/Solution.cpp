#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        // Step 1: Track Nodes and Children
        unordered_map<int, TreeNode*> nodeMap;
        unordered_set<int> children;
        
        // Step 2: Build the Tree
        for (const auto& desc : descriptions) {
            int parentVal = desc[0];
            int childVal = desc[1];
            int isLeft = desc[2];
            
            // Get or create parent node
            if (nodeMap.find(parentVal) == nodeMap.end()) {
                nodeMap[parentVal] = new TreeNode(parentVal);
            }
            TreeNode* parentNode = nodeMap[parentVal];
            
            // Get or create child node
            if (nodeMap.find(childVal) == nodeMap.end()) {
                nodeMap[childVal] = new TreeNode(childVal);
            }
            TreeNode* childNode = nodeMap[childVal];
            
            // Link parent and child
            if (isLeft == 1) {
                parentNode->left = childNode;
            } else {
                parentNode->right = childNode;
            }
            
            // Record child
            children.insert(childVal);
        }
        
        // Step 3: Identify the Root
        for (const auto& pair : nodeMap) {
            int val = pair.first;
            if (children.find(val) == children.end()) {
                return pair.second; // Root node has no parent
            }
        }
        
        return nullptr;
    }
};
