#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Definition for a binary tree node.
struct Node {
    int data;
    Node *left;
    Node *right;
    Node(int x) : data(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    void solve(Node* root, int k, int curr_sum, unordered_map<int, int>& prefix_sums, int& count) {
        if (!root) return;

        curr_sum += root->data;

        // If (curr_sum - k) exists in the map, it means there's a path ending at current node with sum k
        if (prefix_sums.find(curr_sum - k) != prefix_sums.end()) {
            count += prefix_sums[curr_sum - k];
        }

        // Add the current sum to the map
        prefix_sums[curr_sum]++;

        // Recurse for left and right children
        solve(root->left, k, curr_sum, prefix_sums, count);
        solve(root->right, k, curr_sum, prefix_sums, count);

        // Backtrack: remove the current sum passing through this node as we go up
        prefix_sums[curr_sum]--;
    }

public:
    int countAllPaths(Node *root, int k) {
        unordered_map<int, int> prefix_sums;
        // Base case: to handle paths that start from the root and map to exactly k
        prefix_sums[0] = 1;
        
        int count = 0;
        solve(root, k, 0, prefix_sums, count);
        
        return count;
    }
};

int main() {
    // Example 2
    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    
    Solution sol;
    cout << "Expected: 2, Output: " << sol.countAllPaths(root1, 3) << endl;

    return 0;
}
