#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>
#include <queue>

using namespace std;

// Helper function to build tree from string format (space or comma separated)
Node* buildTree(const string& str) {
    if (str.empty()) return nullptr;

    string cleanStr = str;
    for (char& c : cleanStr) {
        if (c == ',') c = ' ';
    }

    stringstream ss(cleanStr);
    vector<string> tokens;
    string token;
    while (ss >> token) {
        tokens.push_back(token);
    }

    if (tokens.empty() || tokens[0] == "N" || tokens[0] == "null") {
        return nullptr;
    }

    Node* root = new Node(stoi(tokens[0]));
    queue<Node*> q;
    q.push(root);

    size_t i = 1;
    while (!q.empty() && i < tokens.size()) {
        Node* curr = q.front();
        q.pop();

        // Left child
        if (i < tokens.size()) {
            if (tokens[i] != "N" && tokens[i] != "null") {
                curr->left = new Node(stoi(tokens[i]));
                q.push(curr->left);
            }
            i++;
        }

        // Right child
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

// Helper function to free allocated tree nodes
void freeTree(Node* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

void runTest(int testNum, const string& t1Str, const string& t2Str, bool expected, const string& description) {
    Node* root1 = buildTree(t1Str);
    Node* root2 = buildTree(t2Str);

    Solution sol;
    bool result = sol.areAnagrams(root1, root2);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";

    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);

    string displayDesc = description;
    if (displayDesc.length() > 30) {
        displayDesc = displayDesc.substr(0, 27) + "...";
    }

    string expStr = expected ? "true" : "false";
    string resStr = result ? "true" : "false";

    cout << left << setw(6)  << testId
         << setw(32) << displayDesc
         << setw(12) << expStr
         << setw(12) << resStr
         << status << "\n";

    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Tree 1:      " << t1Str << "\n"
             << "     Tree 2:      " << t2Str << "\n"
             << "     Expected:    " << expStr << "\n"
             << "     Got:         " << resStr << "\n";
    }

    freeTree(root1);
    freeTree(root2);
}

int main() {
    cout << "\n🌳 Check Level Anagrams in Binary Trees — Test Suite\n";
    cout << "※ ============================================================================== ※\n";
    cout << left << setw(6)  << "[ID]"
         << setw(32) << "Test Description"
         << setw(12) << "Expected"
         << setw(12) << "Result"
         << "Status\n";
    cout << string(75, '-') << "\n";

    // Test 1: Example 1 (Anagrams across all 3 levels)
    runTest(1, "1 3 2 N N 5 4", "1 2 3 4 5 N N", true, "Example 1 (Matching levels)");

    // Test 2: Example 2 (Mismatch at level 1: [2, 3] vs [2, 4])
    runTest(2, "1 2 3 5 4", "1 2 4 5 3", false, "Example 2 (Level 1 mismatch)");

    // Test 3: Single node matching
    runTest(3, "42", "42", true, "Single node identical");

    // Test 4: Single node different value
    runTest(4, "10", "20", false, "Single node distinct values");

    // Test 5: One empty tree, one non-empty tree
    runTest(5, "N", "10", false, "One empty, one present");

    // Test 6: Both trees empty
    runTest(6, "N", "N", true, "Both trees empty");

    // Test 7: Different depth / extra level in one tree
    runTest(7, "1 2 3 4 N N N", "1 3 2", false, "Different depths");

    // Test 8: Trees with duplicate values on same level
    runTest(8, "1 2 2 3 4 4 3", "1 2 2 4 3 3 4", true, "Duplicate values per level");

    // Test 9: Complete binary trees mirrored
    runTest(9, "1 2 3 4 5 6 7", "1 3 2 7 6 5 4", true, "Mirrored complete trees");

    // Test 10: Left-skewed vs Right-skewed linear trees with identical sequence
    runTest(10, "1 2 N 3 N 4 N", "1 N 2 N 3 N 4", true, "Left-skewed vs Right-skewed");

    cout << "※ ============================================================================== ※\n";
    cout << "                         🎉 All Tests Completed Successfully!                     \n\n";

    return 0;
}
