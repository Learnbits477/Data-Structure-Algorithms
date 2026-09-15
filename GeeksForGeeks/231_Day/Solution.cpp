#include <bits/stdc++.h>
using namespace std;

/*
Structure of the node of the tree is as
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

#ifndef NODE_STRUCT
#define NODE_STRUCT
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
#endif

class Solution {
public:
    int getCount(Node *root, int k) {
        if (!root) return 0;

        int count = 0;
        queue<pair<Node*, int>> q;
        q.push({root, 1});

        while (!q.empty()) {
            pair<Node*, int> curr = q.front();
            q.pop();

            Node* node = curr.first;
            int level = curr.second;

            // Check if the current node is a leaf node
            if (!node->left && !node->right) {
                if (k >= level) {
                    k -= level;
                    count++;
                } else {
                    // Since BFS processes nodes level-by-level, all subsequent leaves
                    // will have depth >= current level. Hence we can break early.
                    break;
                }
            }

            // Push left and right children into BFS queue
            if (node->left) {
                q.push({node->left, level + 1});
            }
            if (node->right) {
                q.push({node->right, level + 1});
            }
        }

        return count;
    }

    // Alias method
    int leafUnderBudget(Node *root, int k) {
        return getCount(root, k);
    }
};
