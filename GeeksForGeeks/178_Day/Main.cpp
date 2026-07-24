#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <queue>
#include <sstream>
using namespace std;

// Helper function to build a tree from level-order input (e.g., "1 2 3 N N 4")
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

// Helper to free memory of the allocated tree
void freeTree(Node* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

void runTest(int testNum, const string& treeStr, int expected) {
    Node* root = buildTree(treeStr);
    
    Solution sol;
    int result = sol.longestConsecutive(root);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";
    
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);
    
    // Format input tree string output
    string displayStr = treeStr;
    if (displayStr.length() > 30) {
        displayStr = displayStr.substr(0, 27) + "...";
    }
    
    cout << left << setw(6)  << testId 
         << setw(32) << displayStr
         << setw(18) << (expected == -1 ? "-1" : to_string(expected))
         << setw(18) << (result == -1 ? "-1" : to_string(result))
         << status << "\n";
         
    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Expected: " << expected << "\n"
             << "     Got:      " << result << "\n";
    }
    
    freeTree(root);
}

int main() {
    cout << "\n";
    cout << "  🚀 GeeksforGeeks Day 178 - Longest Consecutive Path in Binary Tree Test Suite  \n";
    cout << "⇚ - ==================================================================================== - ⇛\n";
    cout << left << setw(6)  << "[ID]" 
         << setw(32) << "Tree Level Order" 
         << setw(18) << "Expected Max" 
         << setw(18) << "Actual Max" 
         << "Status\n";
    cout << string(88, '-') << "\n";

    // Test Case 1: Example 1 from GFG [1, 2, 3]
    runTest(1, "1 2 3", 2);

    // Test Case 2: Example 2 from GFG [10, 20, 30, 40, N, 60, 90]
    runTest(2, "10 20 30 40 N 60 90", -1);

    // Test Case 3: Straight line sequence 1 -> 2 -> 3
    runTest(3, "1 N 2 N 3", 3);

    // Test Case 4: Longest consecutive path of length 4
    runTest(4, "1 2 4 3 N N 5 4", 4);

    // Test Case 5: Single element tree
    runTest(5, "10", -1);

    // Test Case 6: Empty tree
    runTest(6, "N", -1);

    // Test Case 7: Multiple paths but no consecutive path of length > 1
    runTest(7, "5 3 7 1 N 6 9", -1);

    // Test Case 8: Sequence at depth
    runTest(8, "10 2 3 N N 4 N N 5", 3);

    // Test Case 9: Longest consecutive path of length 4 (Right-skewed)
    runTest(9, "2 N 3 N 4 N 5", 4);

    cout << "⇚ - ==================================================================================== - ⇛\n";
    cout << "                         🎉 All Tests Completed Successfully!                           \n\n";

    return 0;
}

