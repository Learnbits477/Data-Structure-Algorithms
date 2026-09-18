#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <queue>
#include <sstream>

using namespace std;

// Helper function to build BST from level-order string format (e.g. "50 30 70 20 N 60 80")
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

// Helper function to clean up dynamically allocated tree nodes
void freeTree(Node* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

void runTest(int testNum, const string& treeStr, int expected) {
    Node* root = buildTree(treeStr);

    Solution sol;
    int result = sol.absolute_diff(root);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";

    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);

    string displayTree = treeStr;
    if (displayTree.length() > 30) {
        displayTree = displayTree.substr(0, 27) + "...";
    }

    cout << left << setw(6)  << testId
         << setw(32) << displayTree
         << setw(12) << expected
         << setw(12) << result
         << status << "\n";

    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Tree:     " << treeStr << "\n"
             << "     Expected: " << expected << "\n"
             << "     Got:      " << result << "\n";
    }

    freeTree(root);
}

int main() {
    cout << "\n🌳 Minimum Absolute Difference In BST — Test Suite\n";
    cout << "※ ============================================================================== ※\n";
    cout << left << setw(6)  << "[ID]"
         << setw(32) << "Input Tree"
         << setw(12) << "Expected"
         << setw(12) << "Result"
         << "Status\n";
    cout << string(74, '-') << "\n";

    // Test 1: Example 1 -> 10
    runTest(1, "50 30 70 20 N 60 80", 10);

    // Test 2: Example 2 -> 20
    runTest(2, "60 30 90 10", 20);

    // Test 3: Two nodes root and right child -> 2
    runTest(3, "1 N 3", 2);

    // Test 4: Two nodes root and left child -> 3
    runTest(4, "5 2", 3);

    // Test 5: Skewed left BST -> 10
    runTest(5, "50 40 N 30 N 20", 10);

    // Test 6: Skewed right BST -> 15 (diffs: 15, 17, 18)
    runTest(6, "10 N 25 N 42 N 60", 15);

    // Test 7: Large values with difference 1 -> 1
    runTest(7, "1000 500 2000 N N 1001", 1);

    // Test 8: Balanced tree with close values -> 1
    runTest(8, "4 2 6 1 3", 1);

    // Test 9: Balanced tree with uniform step 25 -> 25
    runTest(9, "100 50 150 25 75 125 175", 25);

    // Test 10: Minimum difference between root (8) and in-order predecessor (7) -> 1
    runTest(10, "8 4 12 2 7", 1);

    cout << "※ ============================================================================== ※\n";
    cout << "                         🎉 All Tests Completed Successfully!                     \n\n";

    return 0;
}
