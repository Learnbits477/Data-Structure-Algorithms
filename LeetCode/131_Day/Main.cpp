#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include "Solution.cpp"

using namespace std;

// Helper function to serialize tree in level-order format (LeetCode style)
vector<string> serializeTree(TreeNode* root) {
    vector<string> result;
    if (!root) return result;
    
    queue<TreeNode*> q;
    q.push(root);
    
    while (!q.empty()) {
        TreeNode* curr = q.front();
        q.pop();
        
        if (curr) {
            result.push_back(to_string(curr->val));
            q.push(curr->left);
            q.push(curr->right);
        } else {
            result.push_back("null");
        }
    }
    
    // Remove trailing "null" elements
    while (!result.empty() && result.back() == "null") {
        result.pop_back();
    }
    
    return result;
}

// Helper function to print a vector of strings
void printVector(const vector<string>& vec) {
    cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << vec[i];
        if (i < vec.size() - 1) cout << ", ";
    }
    cout << "]";
}

// Recursive helper to clean up tree nodes
void freeTree(TreeNode* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

void runTest(vector<vector<int>> descriptions, vector<string> expected) {
    Solution sol;
    TreeNode* root = sol.createBinaryTree(descriptions);
    vector<string> result = serializeTree(root);
    
    cout << "Expected: ";
    printVector(expected);
    cout << " | Output: ";
    printVector(result);
    cout << "\n";
    
    if (result == expected) {
        cout << "✅ PASSED\n\n";
    } else {
        cout << "❌ FAILED\n\n";
    }
    
    freeTree(root);
}

int main() {
    cout << "\n🔢 Create Binary Tree From Descriptions — Test Suite\n";
    cout << "--------------------------------------------------------\n" << endl;
    
    // Example 1
    cout << "Test Case 1:\n";
    runTest({{20,15,1},{20,17,0},{50,20,1},{50,80,0},{80,19,1}}, 
            {"50", "20", "80", "15", "17", "19"});
            
    // Example 2
    cout << "Test Case 2:\n";
    runTest({{1,2,1},{2,3,0},{3,4,1}}, 
            {"1", "2", "null", "null", "3", "4"});
            
    // Additional Edge Case: Smallest tree with 1 edge
    cout << "Test Case 3 (Single Edge):\n";
    runTest({{10,20,1}}, 
            {"10", "20"});
            
    return 0;
}
