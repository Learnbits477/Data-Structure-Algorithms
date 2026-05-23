#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <sstream>
#include "Solution.cpp"

using namespace std;

// Helper function to build a tree from level-order input string (e.g., "10 -2 6 8 -4 7 5")
Node* buildTree(string str) {
    if (str.length() == 0 || str[0] == 'N')
        return nullptr;

    vector<string> ip;
    stringstream ss(str);
    string temp;
    while (ss >> temp)
        ip.push_back(temp);

    Node* root = new Node(stoi(ip[0]));
    queue<Node*> q;
    q.push(root);

    size_t i = 1;
    while (!q.empty() && i < ip.size()) {
        Node* currNode = q.front();
        q.pop();

        string currVal = ip[i];
        if (currVal != "N") {
            currNode->left = new Node(stoi(currVal));
            q.push(currNode->left);
        }
        i++;
        if (i >= ip.size()) break;

        currVal = ip[i];
        if (currVal != "N") {
            currNode->right = new Node(stoi(currVal));
            q.push(currNode->right);
        }
        i++;
    }
    return root;
}

// Helper function to get inorder traversal of the tree
void getInorder(Node* root, vector<int>& res) {
    if (!root) return;
    getInorder(root->left, res);
    res.push_back(root->data);
    getInorder(root->right, res);
}

// Helper function to print a vector
void printVector(const vector<int>& v) {
    cout << "[";
    for (size_t i = 0; i < v.size(); i++) {
        cout << v[i];
        if (i + 1 < v.size()) cout << ", ";
    }
    cout << "]";
}

// Helper function to print tree structure in a 2D rotated format
void printTree2D(Node* root, int space = 0, int height = 5) {
    if (root == nullptr) return;
    space += height;
    printTree2D(root->right, space);
    cout << "\n";
    for (int i = height; i < space; i++) cout << " ";
    cout << root->data << "\n";
    printTree2D(root->left, space);
}

// Helper function to recursively free memory of the tree
void freeTree(Node* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

// Test runner function
void runTest(int testId, string treeStr, const vector<int>& expectedInorder) {
    Node* root = buildTree(treeStr);
    
    cout << "--------------------------------------------------\n";
    cout << "🧪 Test Case " << testId << ":\n";
    cout << "   Input Tree Level-order String: \"" << treeStr << "\"\n";
    
    cout << "   Original Tree Visual representation (Rotated 90°):\n";
    printTree2D(root);
    cout << "   ---------------------------------------------\n";

    Solution solver;
    solver.toSumTree(root);
    
    vector<int> actualInorder;
    getInorder(root, actualInorder);
    
    cout << "   Transformed Tree Visual representation (Rotated 90°):\n";
    printTree2D(root);
    cout << "   ---------------------------------------------\n";

    cout << "   Expected Inorder: ";
    printVector(expectedInorder);
    cout << "\n";
    
    cout << "   Actual Inorder:   ";
    printVector(actualInorder);
    cout << "\n";
    
    if (actualInorder == expectedInorder) {
        cout << "   🟢 Result: ✅ PASSED\n";
    } else {
        cout << "   🔴 Result: ❌ FAILED\n";
    }
    
    freeTree(root);
}

int main() {
    cout << "\n🔢 [Day 116] Transform to Sum Tree — Test Suite 🚀\n";
    
    // Example 1: Standard Binary Tree with negative and positive values
    // Original Tree:
    //          10
    //        /    \
    //      -2      6
    //      / \    / \
    //     8  -4  7   5
    // Transformed Tree Inorder Expected: [0, 4, 0, 20, 0, 12, 0]
    runTest(1, "10 -2 6 8 -4 7 5", {0, 4, 0, 20, 0, 12, 0});
    
    // Example 2: Single Node Tree
    // Original Tree:
    //          10
    // Transformed Tree Inorder Expected: [0]
    runTest(2, "10", {0});
    
    // Example 3: Left-skewed tree
    // Original Tree:
    //          10
    //         /
    //        5
    //       /
    //      2
    // Transformed Tree Inorder Expected: [0, 2, 7]
    runTest(3, "10 5 N 2", {0, 2, 7});

    // Example 4: Symmetric tree with positive values
    // Original Tree:
    //          1
    //        /   \
    //       2     3
    // Transformed Tree Inorder Expected: [0, 0, 0, 5, 0, 0, 0]
    // Wait, let's trace:
    // root = 1, left = 2, right = 3
    // leaf 2 -> data becomes 0, returns 2
    // leaf 3 -> data becomes 0, returns 3
    // root 1 -> data becomes 2+3 = 5, returns 5+1 = 6.
    // Inorder of transformed tree: 2's left (nullptr -> nothing), 2 (data 0), 2's right (nullptr), 1 (data 5), 3's left, 3 (data 0), 3's right.
    // So inorder: [0, 5, 0].
    runTest(4, "1 2 3", {0, 5, 0});

    cout << "--------------------------------------------------\n";
    cout << "🏁 Test execution completed.\n\n";
    return 0;
}
