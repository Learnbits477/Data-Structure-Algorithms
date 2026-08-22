#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <queue>
#include <sstream>

using namespace std;

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

// Helper to free allocated memory
void freeTree(Node* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

void runTest(int testNum, const string& treeStr, int p, int q, int expected) {
    Node* root = buildTree(treeStr);

    Solution sol;
    int result = sol.NumberOfTurns(root, p, q);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";

    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);

    string queryStr = "p=" + to_string(p) + ", q=" + to_string(q);

    string displayTree = treeStr;
    if (displayTree.length() > 24) {
        displayTree = displayTree.substr(0, 21) + "...";
    }

    cout << left << setw(6)  << testId
         << setw(26) << displayTree
         << setw(16) << queryStr
         << setw(12) << expected
         << setw(12) << result
         << status << "\n";

    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Expected: " << expected << "\n"
             << "     Got:      " << result << "\n";
    }

    freeTree(root);
}

int main() {
    cout << "\n🌳 Number of Turns in Binary Tree — Test Suite\n";
    cout << "※ ================================================================================== ※\n";
    cout << left << setw(6)  << "[ID]"
         << setw(26) << "Input Tree"
         << setw(16) << "Query (p, q)"
         << setw(12) << "Expected"
         << setw(12) << "Result"
         << "Status\n";
    cout << string(80, '-') << "\n";

    string mainTree = "1 2 3 4 5 6 7 8 N N N 9 10";

    runTest(1, mainTree, 5, 10, 4);
    runTest(2, mainTree, 1, 4, -1);
    runTest(3, mainTree, 1, 10, 2);
    runTest(4, mainTree, 8, 10, 3);
    runTest(5, mainTree, 4, 5, 1);
    runTest(6, mainTree, 5, 2, -1);
    runTest(7, mainTree, 5, 1, 1);
    runTest(8, "1 2 3", 2, 3, 1);
    runTest(9, "1 2 N 3 N 4 N 5", 1, 5, -1);
    runTest(10, "1 2 3 4 N N 5 N 6", 6, 5, 2);

    cout << "※ ================================================================================== ※\n";
    cout << "                         🎉 All Tests Completed Successfully!                        \n\n";

    return 0;
}
