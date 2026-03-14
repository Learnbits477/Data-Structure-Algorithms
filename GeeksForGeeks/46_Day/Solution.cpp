#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

// Tree Node
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
    // Function to return a list of nodes visible from the top view 
    // from left to right in Binary Tree.
    vector<int> topView(Node *root) {
        vector<int> result;
        if (!root) return result;
        
        map<int, int> topNodeMap; // horizontal distance -> node data
        queue<pair<Node*, int>> q; // node, horizontal distance
        
        q.push({root, 0});
        
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            
            Node* curr = p.first;
            int hd = p.second;
            
            // If the horizontal distance is not present in map, 
            // it means it's the first node seen at this HD (topmost)
            if (topNodeMap.find(hd) == topNodeMap.end()) {
                topNodeMap[hd] = curr->data;
            }
            
            if (curr->left) {
                q.push({curr->left, hd - 1});
            }
            if (curr->right) {
                q.push({curr->right, hd + 1});
            }
        }
        
        for (auto it : topNodeMap) {
            result.push_back(it.second);
        }
        
        return result;
    }
};

// Helper function to insert nodes in level order structure
Node* buildTree(const vector<int>& nums) {
    if (nums.empty() || nums[0] == -1) return nullptr;
    
    Node* root = new Node(nums[0]);
    queue<Node*> q;
    q.push(root);
    
    int i = 1;
    while (!q.empty() && i < nums.size()) {
        Node* curr = q.front();
        q.pop();
        
        if (nums[i] != -1) {
            curr->left = new Node(nums[i]);
            q.push(curr->left);
        }
        i++;
        
        if (i < nums.size() && nums[i] != -1) {
            curr->right = new Node(nums[i]);
            q.push(curr->right);
        }
        i++;
    }
    return root;
}

void printVector(const vector<int>& v) {
    cout << "[";
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << (i == v.size() - 1 ? "" : ", ");
    }
    cout << "]" << endl;
}

int main() {
    Solution sol;
    
    // Example 1
    // Input: root = [1, 2, 3]
    vector<int> vec1 = {1, 2, 3};
    Node* root1 = buildTree(vec1);
    cout << "Expected Output: [2, 1, 3]" << endl;
    cout << "Actual Output: ";
    printVector(sol.topView(root1));
    cout << endl;
    
    // Example 2
    // Input: root = [10, 20, 30, 40, 60, 90, 100]
    vector<int> vec2 = {10, 20, 30, 40, 60, 90, 100};
    Node* root2 = buildTree(vec2);
    cout << "Expected Output: [40, 20, 10, 30, 100]" << endl;
    cout << "Actual Output: ";
    printVector(sol.topView(root2));
    cout << endl;
    
    return 0;
}
