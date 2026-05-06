#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Structure of the node of the binary tree
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Include the solution from Solution.cpp logic
#include "Solution.cpp"

// Helper function to build a tree from level order input
Node* buildTree(vector<int>& nodes) {
    if (nodes.empty() || nodes[0] == -1) return NULL;

    Node* root = new Node(nodes[0]);
    queue<Node*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < nodes.size()) {
        Node* curr = q.front();
        q.pop();

        // Left child
        if (i < nodes.size() && nodes[i] != -1) {
            curr->left = new Node(nodes[i]);
            q.push(curr->left);
        }
        i++;

        // Right child
        if (i < nodes.size() && nodes[i] != -1) {
            curr->right = new Node(nodes[i]);
            q.push(curr->right);
        }
        i++;
    }
    return root;
}

int main() {
    Solution sol;

    // Test Case 1
    //      1
    //    /   \
    //   2     3
    vector<int> nodes1 = {1, 2, 3};
    Node* root1 = buildTree(nodes1);
    cout << "Test Case 1 Size: " << sol.getSize(root1) << " (Expected: 3)" << endl;

    // Test Case 2
    //      10
    //    /    \
    //   20    30
    //  /  \
    // 40   60
    vector<int> nodes2 = {10, 20, 30, 40, 60};
    Node* root2 = buildTree(nodes2);
    cout << "Test Case 2 Size: " << sol.getSize(root2) << " (Expected: 5)" << endl;

    return 0;
}
