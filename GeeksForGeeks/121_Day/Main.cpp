#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <sstream>
#include "Solution.cpp"

using namespace std;

// Utility function to build binary tree from level order representation string
Node* buildTree(string str) {
    if (str.length() == 0 || str[0] == 'N') {
        return nullptr;
    }

    stringstream ss(str);
    string token;
    getline(ss, token, ' ');
    Node* root = new Node(stoi(token));
    queue<Node*> queue;
    queue.push(root);

    while (!queue.empty()) {
        Node* currNode = queue.front();
        queue.pop();

        if (!getline(ss, token, ' '))
            break;
        if (token != "N") {
            currNode->left = new Node(stoi(token));
            queue.push(currNode->left);
        }

        if (!getline(ss, token, ' '))
            break;
        if (token != "N") {
            currNode->right = new Node(stoi(token));
            queue.push(currNode->right);
        }
    }

    return root;
}

// Utility function to free allocated memory for tree nodes to prevent leaks
void freeTree(Node* root) {
    if (root == nullptr) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

// Test runner function
void runTest(int testId, string treeStr, vector<int> expected) {
    cout << "--------------------------------------------------\n";
    cout << "🧪 Test Case " << testId << ":\n";
    cout << "   Tree Input:  \"" << treeStr << "\"\n";

    Node* root = buildTree(treeStr);
    Solution solver;
    vector<int> actual = solver.verticalSum(root);

    cout << "   Expected:    [ ";
    for (int x : expected) cout << x << " ";
    cout << "]\n";

    cout << "   Actual:      [ ";
    for (int x : actual) cout << x << " ";
    cout << "]\n";

    if (actual == expected) {
        cout << "   🟢 Result: ✅ PASSED\n";
    } else {
        cout << "   🔴 Result: ❌ FAILED\n";
    }
    
    freeTree(root);
}

int main() {
    cout << "\n🔢 [Day 121] Vertical Sum — Test Suite 🚀\n";

    // Example 1: Standard balanced tree
    runTest(1, "1 2 3 4 5 6 7", {4, 2, 12, 3, 7});

    // Example 2: Left-skewed tree
    runTest(2, "1 2 N 3 N 4 N 6 N 7", {7, 6, 4, 3, 2, 1});

    // Example 3: Single node tree
    runTest(3, "5", {5});

    // Example 4: Right-skewed tree
    runTest(4, "1 N 2 N 3 N 4 N 5", {1, 2, 3, 4, 5});

    // Example 5: Empty tree
    runTest(5, "N", {});

    // Example 6: Symmetric tree with overlapping coordinates
    runTest(6, "10 20 20 30 40 40 30", {30, 20, 90, 20, 30});

    cout << "--------------------------------------------------\n";
    cout << "🏁 Test execution completed.\n\n";
    return 0;
}
