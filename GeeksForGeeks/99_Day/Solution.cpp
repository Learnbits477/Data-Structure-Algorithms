#include <iostream>

class Solution {
  public:
    int getSize(struct Node* node) {
        // Base case: if the tree is empty, size is 0
        if (node == NULL) {
            return 0;
        }
        
        // Recursive step: 1 (current node) + size of left subtree + size of right subtree
        return 1 + getSize(node->left) + getSize(node->right);
    }
};
