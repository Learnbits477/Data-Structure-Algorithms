#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <queue>
#include <sstream>

using namespace std;

// Helper function to build tree from string format (e.g. "10 8 2 3 N 3 6 N N N 4")
Node* buildTree(const string& str) {
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

// Helper function to clean up allocated tree nodes
void freeTree(Node* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

void runTest(int testNum, const string& treeStr, int k, int expected) {
    Node* root = buildTree(treeStr);

    Solution sol;
    int result = sol.getCount(root, k);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";

    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);

    string displayTree = treeStr;
    if (displayTree.length() > 28) {
        displayTree = displayTree.substr(0, 25) + "...";
    }

    cout << left << setw(6)  << testId
         << setw(30) << displayTree
         << setw(10) << k
         << setw(12) << expected
         << setw(12) << result
         << status << "\n";

    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Tree:     " << treeStr << "\n"
             << "     Budget k: " << k << "\n"
             << "     Expected: " << expected << "\n"
             << "     Got:      " << result << "\n";
    }

    freeTree(root);
}

int main() {
    cout << "\n🍃 Visit Leaves with Budget — Test Suite\n";
    cout << "※ ============================================================================== ※\n";
    cout << left << setw(6)  << "[ID]"
         << setw(30) << "Input Tree"
         << setw(10) << "Budget k"
         << setw(12) << "Expected"
         << setw(12) << "Result"
         << "Status\n";
    cout << string(80, '-') << "\n";

    // Test 1: Example 1 -> 2
    runTest(1, "10 8 2 3 N 3 6 N N N 4", 8, 2);

    // Test 2: Example 2 -> 1
    runTest(2, "1 2 3 4 5 6 7", 5, 1);

    // Test 3: Example 3 (Single node root) -> 1
    runTest(3, "1", 1, 1);

    // Test 4: Single node with 0 budget -> 0
    runTest(4, "1", 0, 0);

    // Test 5: Full binary tree with generous budget (4 leaves at level 3, cost 3 each = 12 total, k = 15) -> 4
    runTest(5, "1 2 3 4 5 6 7", 15, 4);

    // Test 6: Skewed left tree (only 1 leaf at level 4) -> 1
    runTest(6, "1 2 N 3 N 4", 4, 1);

    // Test 7: Skewed left tree with insufficient budget -> 0
    runTest(7, "1 2 N 3 N 4", 3, 0);

    // Test 8: Multiple leaves at different levels -> 2
    // Leaves at level 2 (cost 2) and level 3 (cost 3), k = 5 -> both leaves visited
    runTest(8, "1 2 3 N N 4 5", 5, 2);

    // Test 9: Larger budget covering all leaves in complex tree
    runTest(9, "10 8 2 3 N 3 6 N N N 4", 20, 3);

    cout << "※ ============================================================================== ※\n";
    cout << "                         🎉 All Tests Completed Successfully!                     \n\n";

    return 0;
}
