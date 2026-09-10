#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <queue>

using namespace std;

// Helper function to build a binary tree from level-order vector (-1 denotes null)
TreeNode* buildTree(const vector<int>& nodes) {
    if (nodes.empty() || nodes[0] == -1) return nullptr;

    TreeNode* root = new TreeNode(nodes[0]);
    queue<TreeNode*> q;
    q.push(root);

    size_t i = 1;
    while (!q.empty() && i < nodes.size()) {
        TreeNode* curr = q.front();
        q.pop();

        // Left child
        if (i < nodes.size()) {
            if (nodes[i] != -1) {
                curr->left = new TreeNode(nodes[i]);
                q.push(curr->left);
            }
            i++;
        }

        // Right child
        if (i < nodes.size()) {
            if (nodes[i] != -1) {
                curr->right = new TreeNode(nodes[i]);
                q.push(curr->right);
            }
            i++;
        }
    }

    return root;
}

// Helper to free allocated tree nodes
void freeTree(TreeNode* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

void runTest(int testNum, const vector<int>& treeNodes, const string& treeDesc, int expected) {
    TreeNode* root = buildTree(treeNodes);
    Solution sol;
    int result = sol.averageOfSubtree(root);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";

    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);

    cout << left << setw(6)  << testId
         << setw(32) << treeDesc
         << setw(16) << result
         << setw(16) << expected
         << status << "\n";

    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Tree     = " << treeDesc << "\n"
             << "     Expected = " << expected << "\n"
             << "     Got      = " << result << "\n";
    }

    freeTree(root);
}

int main() {
    cout << "\n🌳 2265. Count Nodes Equal to Average of Subtree — Test Suite\n";
    cout << "※ ========================================================================= ※\n";
    cout << left << setw(6)  << "[ID]"
         << setw(32) << "Tree Structure"
         << setw(16) << "Result"
         << setw(16) << "Expected"
         << "Status\n";
    cout << string(80, '-') << "\n";

    // Test 1: Example 1 from problem description: [4, 8, 5, 0, 1, null, 6] -> 5
    runTest(1, {4, 8, 5, 0, 1, -1, 6}, "[4,8,5,0,1,null,6]", 5);

    // Test 2: Example 2 from problem description: [1] -> 1
    runTest(2, {1}, "[1]", 1);

    // Test 3: Two nodes tree [1, 2] -> sum=3, count=2, avg=1. Node 1 has avg=1 (match), Node 2 has avg=2 (match) -> 2
    runTest(3, {1, 2}, "[1,2]", 2);

    // Test 4: All nodes have identical values [5, 5, 5, 5, 5] -> All 5 nodes equal 5 -> 5
    runTest(4, {5, 5, 5, 5, 5}, "[5,5,5,5,5]", 5);

    // Test 5: Skewed tree with varying values [10, 20, -1, 30]
    // 30: sum=30, cnt=1, avg=30 (match)
    // 20: sum=50, cnt=2, avg=25 (no match)
    // 10: sum=60, cnt=3, avg=20 (no match) -> 1
    runTest(5, {10, 20, -1, 30}, "[10,20,null,30]", 1);

    // Test 6: Tree with zeroes [0, 0, 0] -> all match -> 3
    runTest(6, {0, 0, 0}, "[0,0,0]", 3);

    // Test 7: Complex binary tree [6, 2, 8, 0, 4, 7, 9, -1, -1, 3, 5]
    // Leaves: 0(avg 0: match), 3(avg 3: match), 5(avg 5: match), 7(avg 7: match), 9(avg 9: match) -> 5
    // Node 4: sum=12, cnt=3, avg=4 (match) -> +1
    // Node 2: sum=0+12+2=14, cnt=1+3+1=5, avg=2 (match) -> +1
    // Node 8: sum=7+9+8=24, cnt=3, avg=8 (match) -> +1
    // Node 6: sum=14+24+6=44, cnt=5+3+1=9, avg=44/9=4 (no match)
    // Total = 5 + 1 + 1 + 1 = 8
    runTest(7, {6, 2, 8, 0, 4, 7, 9, -1, -1, 3, 5}, "[6,2,8,0,4,7,9,null,null,3,5]", 8);

    // Test 8: Large balanced values [1000, 1000, 1000] -> 3
    runTest(8, {1000, 1000, 1000}, "[1000,1000,1000]", 3);

    cout << "※ ========================================================================= ※\n";
    cout << "                         🎉 All Tests Executed!                             \n\n";

    return 0;
}
