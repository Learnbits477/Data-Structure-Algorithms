#include <bits/stdc++.h>
using namespace std;

// -----------------------------------------------------------
//  Solution — Top View of Binary Tree
//
//  Key Insight:
//  ─────────────────────────────────────────────────────────
//  The top view of a binary tree is conceptually equivalent 
//  to observing the topmost nodes mapped on a 1D horizontal 
//  axis. Using Breadth-First Search (BFS) combined with a 
//  hash map to track the horizontal distance (HD) ensures we 
//  capture the first (and therefore topmost) node at each 
//  horizontal position efficiently.
//
//  Algorithm:
//    Step 1 — Initialize a queue for BFS and a map for HD.
//    Step 2 — Push the root node with HD = 0 into the queue.
//    Step 3 — Process the queue level by level. If an HD is 
//             not in the map, add it.
//    Step 4 — Push left child with HD - 1, and right child 
//             with HD + 1 into the queue.
//    Step 5 — Extract the perfectly ordered values from the map.
//
//  Time  : O(N log N)
//  Space : O(N)
// -----------------------------------------------------------

// ── Tree Node definition ────────────────────────────────────
struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
public:
    vector<int> topView(Node *root) {
        vector<int> result;
        if (!root) return result;
        
        // Map to store the first node's data at each horizontal distance
        map<int, int> topNodeMap; 
        
        // Queue for BFS traversal storing pairs of {Node*, Horizontal Distance}
        queue<pair<Node*, int>> q; 
        
        // ── Step 1: Start BFS with the root node at HD 0 ──
        q.push({root, 0});
        
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            
            Node* curr = p.first;
            int hd = p.second;
            
            // ── Step 2: Track topmost node for current HD ──
            if (topNodeMap.find(hd) == topNodeMap.end()) {
                topNodeMap[hd] = curr->data;
            }
            
            // ── Step 3: Traverse children ──────────────────
            if (curr->left) {
                q.push({curr->left, hd - 1});
            }
            if (curr->right) {
                q.push({curr->right, hd + 1});
            }
        }
        
        // ── Step 4: Extract sorted map values ──────────────
        for (auto it : topNodeMap) {
            result.push_back(it.second);
        }
        
        return result;
    }
};
