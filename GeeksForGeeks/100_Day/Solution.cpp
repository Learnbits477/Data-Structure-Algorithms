#include <iostream>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct Node {
 *     int data;
 *     Node *left;
 *     Node *right;
 *     Node(int x) {
 *         data = x;
 *         left = right = NULL;
 *     }
 * };
 */

struct Node {
    int data;
    Node *left;
    Node *right;
    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

class Solution {
  public:
    bool isIdentical(Node* r1, Node* r2) {
        // If both are NULL, they are identical
        if (!r1 && !r2) return true;
        
        // If one is NULL and other isn't, they aren't identical
        if (!r1 || !r2) return false;
        
        // Check current node data and recurse for left and right subtrees
        return (r1->data == r2->data) && 
               isIdentical(r1->left, r2->left) && 
               isIdentical(r1->right, r2->right);
    }


    bool isSubTree(Node* T, Node* S) {
        // If S is NULL, it's always a subtree
        if (!S) return true;
        
        // If T is NULL but S isn't, S cannot be a subtree
        if (!T) return false;
        
        // If current subtree rooted at T is identical to S, return true
        if (isIdentical(T, S)) return true;
        
        // Otherwise, search for S in the left or right subtrees of T
        return isSubTree(T->left, S) || isSubTree(T->right, S);
    }
};
