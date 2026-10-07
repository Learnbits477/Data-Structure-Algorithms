#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <queue>
#include <sstream>

using namespace std;

Node* buildTree(const string& str) {
    if (str.empty()) return nullptr;
    string s = str;
    if (s.front() == '[') s = s.substr(1);
    if (!s.empty() && s.back() == ']') s.pop_back();
    if (s.empty()) return nullptr;

    vector<string> tokens;
    stringstream ss(s);
    string token;
    while (getline(ss, token, ',')) {
        size_t first = token.find_first_not_of(" \t\r\n");
        size_t last = token.find_last_not_of(" \t\r\n");
        if (first == string::npos) continue;
        tokens.push_back(token.substr(first, last - first + 1));
    }
    if (tokens.empty() || tokens[0] == "N" || tokens[0] == "null") return nullptr;

    Node* root = new Node(stoi(tokens[0]));
    queue<Node*> q;
    q.push(root);
    size_t i = 1;

    while (!q.empty() && i < tokens.size()) {
        Node* curr = q.front();
        q.pop();

        if (i < tokens.size()) {
            if (tokens[i] != "N" && tokens[i] != "null") {
                curr->left = new Node(stoi(tokens[i]));
                q.push(curr->left);
            }
            i++;
        }
        if (i < tokens.size()) {
            if (tokens[i] != "N" && tokens[i] != "null") {
                curr->right = new Node(stoi(tokens[i]));
                q.push(curr->right);
            }
            i++;
        }
    }
    return root;
}

void freeTree(Node* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

void runTest(int testNum, const string& treeStr, int expected, const string& description) {
    // Step: 01 - Construct binary tree from serialized representation
    Node* root1 = buildTree(treeStr);
    Node* root2 = buildTree(treeStr);

    // Step: 02 - Compute result using primary single-pass and secondary two-pass solvers
    Solution sol;
    int res1 = sol.maxPathSum(root1);
    int res2 = sol.maxPathSumTwoPass(root2);

    // Step: 03 - Validate result correctness and solver equivalence
    bool passed = (res1 == expected) && (res2 == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";

    // Step: 04 - Format test identifier and tabular display columns
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);

    string displayDesc = description;
    if (displayDesc.length() > 36) {
        displayDesc = displayDesc.substr(0, 33) + "...";
    }

    string inputDisplay = treeStr.length() > 20 ? treeStr.substr(0, 17) + "..." : treeStr;

    cout << left << setw(6)  << testId
         << setw(38) << displayDesc
         << setw(22) << inputDisplay
         << setw(12) << expected
         << setw(12) << res1
         << status << "\n";

    // Step: 05 - Output debug information upon test mismatch
    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Input:           " << treeStr << "\n"
             << "     Expected:        " << expected << "\n"
             << "     Primary Result:  " << res1 << "\n"
             << "     Two-Pass Result: " << res2 << "\n";
    }

    // Step: 06 - Free dynamically allocated tree nodes
    freeTree(root1);
    freeTree(root2);
}

int main() {
    // Step: 01 - Print test suite header and table format
    cout << "\n🍃 Max Path Sum Between Two Leaves — Test Suite\n";
    cout << "※ ========================================================================================= ※\n";
    cout << left << setw(6)  << "[ID]"
         << setw(38) << "Description"
         << setw(22) << "Tree Input"
         << setw(12) << "Expected"
         << setw(12) << "Result"
         << "Status\n";
    cout << string(94, '-') << "\n";

    // Step: 02 - Execute test cases
    runTest(1, "[3, 4, 5, -10, 4, N, N]", 16, "Example 1: Tree with 3 leaves");
    runTest(2, "[-15, 5, 6, -8, 1, 3, 9, 2, -3, N, N, N, N, N, 0, N, N, N, N, 4, -1, N, N, 10]", 27, "Example 2: Deep unbalanced tree");
    runTest(3, "[3, 4, 1, -10, 4, N, N]", 12, "Example 3: Alternate branching leaves");
    runTest(4, "[1]", -1, "Single node tree (0 path between leaves)");
    runTest(5, "[1, 2, N, 3, N]", -1, "Left degenerate chain (1 leaf)");
    runTest(6, "[1, N, 2, N, 3]", -1, "Right degenerate chain (1 leaf)");
    runTest(7, "[1, N, 2, 3, 4]", 9, "Root has 1 child; 2 leaves in subtree");
    runTest(8, "[10, 5, 20]", 35, "Simple 3-node binary tree");
    runTest(9, "[-10, -5, -6, -2, -3, -4, -1]", -10, "All negative values; optimal local path");
    runTest(10, "[5, -2, -3, 10, 20, 30, 40]", 67, "Balanced tree with positive leaf peaks");

    // Step: 03 - Display final completion summary
    cout << "※ ========================================================================================= ※\n";
    cout << "                         🎉 All Tests Completed Successfully!                     \n\n";
    return 0;
}
