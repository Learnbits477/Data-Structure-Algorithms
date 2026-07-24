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
    void dfs(Node* root, int currentLength, int expectedValue, int& maxLength) {
        if (!root) return;
        
        if (root->data == expectedValue) {
            currentLength++;
        } else {
            currentLength = 1;
        }
        
        maxLength = max(maxLength, currentLength);
        
        dfs(root->left, currentLength, root->data + 1, maxLength);
        dfs(root->right, currentLength, root->data + 1, maxLength);
    }
    
public:
    int longestConsecutive(Node* root) {
        if (!root) return -1;
        int maxLength = 0;
        dfs(root, 0, root->data, maxLength);
        return maxLength > 1 ? maxLength : -1;
    }
};
