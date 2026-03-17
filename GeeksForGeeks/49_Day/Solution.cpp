#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

// Definition for a binary tree node.
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
    int minTime(Node* root, int target) {
        if (!root) return 0;
        
        unordered_map<Node*, Node*> parentMap;
        Node* targetNode = nullptr;
        
        queue<Node*> q;
        q.push(root);
        
        // Step 1: Map parents and find the target node
        while (!q.empty()) {
            Node* current = q.front();
            q.pop();
            
            if (current->data == target) {
                targetNode = current;
            }
            
            if (current->left) {
                parentMap[current->left] = current;
                q.push(current->left);
            }
            if (current->right) {
                parentMap[current->right] = current;
                q.push(current->right);
            }
        }
        
        // Target not found in the tree
        if (!targetNode) return 0;
        
        // Step 2: BFS to burn the tree
        unordered_map<Node*, bool> visited;
        q.push(targetNode);
        visited[targetNode] = true;
        
        int time = 0;
        
        while (!q.empty()) {
            int size = q.size();
            bool anyNodeAdded = false;
            
            // For all nodes burning at the current time step
            for (int i = 0; i < size; i++) {
                Node* current = q.front();
                q.pop();
                
                // Spread fire to left child
                if (current->left && !visited[current->left]) {
                    q.push(current->left);
                    visited[current->left] = true;
                    anyNodeAdded = true;
                }
                
                // Spread fire to right child
                if (current->right && !visited[current->right]) {
                    q.push(current->right);
                    visited[current->right] = true;
                    anyNodeAdded = true;
                }
                
                // Spread fire to parent node
                if (parentMap[current] && !visited[parentMap[current]]) {
                    q.push(parentMap[current]);
                    visited[parentMap[current]] = true;
                    anyNodeAdded = true;
                }
            }
            
            // If fire successfully spread to any new node, increment the time
            if (anyNodeAdded) {
                time++;
            }
        }
        
        return time;
    }
};

int main() {
    // Example 1: root = [1, 2, 3, 4, 5, 6, 7], target = 2
    /*
             1
           /   \
          2     3
         / \   / \
        4   5 6   7
    */
    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->left = new Node(4);
    root1->left->right = new Node(5);
    root1->right->left = new Node(6);
    root1->right->right = new Node(7);
    
    Solution sol;
    int target1 = 2;
    int result1 = sol.minTime(root1, target1);
    
    cout << "Example 1 Output: " << result1 << " (Expected: 3)" << endl;
    
    return 0;
}
