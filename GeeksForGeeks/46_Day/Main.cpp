#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <queue>
#include "Solution.cpp"   // Pulls in Solution class

using namespace std;

// -----------------------------------------------------------
//  Tree Builder Utility
// -----------------------------------------------------------

Node* buildTree(string str) {
    if (str.length() == 0 || str[0] == 'N') {
        return NULL;
    }

    vector<string> ip;
    istringstream iss(str);
    for (string str; iss >> str; ) {
        ip.push_back(str);
    }

    Node* root = new Node(stoi(ip[0]));
    queue<Node*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < ip.size()) {
        Node* currNode = q.front();
        q.pop();

        string currVal = ip[i];
        if (currVal != "N") {
            currNode->left = new Node(stoi(currVal));
            q.push(currNode->left);
        }
        i++;

        if (i >= ip.size()) {
            break;
        }

        currVal = ip[i];
        if (currVal != "N") {
            currNode->right = new Node(stoi(currVal));
            q.push(currNode->right);
        }
        i++;
    }

    return root;
}

// -----------------------------------------------------------
//  Pretty Printer Utilities
// -----------------------------------------------------------

void printVector(const vector<int>& v) {
    cout << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        cout << v[i] << (i == v.size() - 1 ? "" : ", ");
    }
    cout << "]";
}

void runTest(int id, string str, const vector<int>& expected) {
    cout << "  Test Case " << id << "\n";
    cout << "  Input     = " << str << "\n";

    Node* root = buildTree(str);
    Solution sol;
    vector<int> result = sol.topView(root);

    cout << "  Output    = "; printVector(result); cout << "\n";
    cout << "  Expected  = "; printVector(expected); cout << "\n";

    if (result == expected)
        cout << "  Status    : ✅  PASSED\n\n";
    else
        cout << "  Status    : ❌  FAILED\n\n";
}

// -----------------------------------------------------------
//  Main
// -----------------------------------------------------------

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "\n🔢  Top View of Binary Tree — Test Suite\n";
    cout << "================================\n\n";

    // ── Test 1: Example 1 ──────────────────────────────
    {
        string str = "1 2 3";
        vector<int> expected = {2, 1, 3};
        runTest(1, str, expected);
    }

    // ── Test 2: Example 2 ──────────────────────────────
    {
        string str = "10 20 30 40 60 90 100";
        vector<int> expected = {40, 20, 10, 30, 100};
        runTest(2, str, expected);
    }

    // ── Test 3: Overlapping Nodes ──────────────────────
    {
        string str = "1 2 3 N 4 N N N 5 N 6";
        vector<int> expected = {2, 1, 3, 6};
        runTest(3, str, expected);
    }

    cout << "================================\n";
    cout << "✅  All test cases executed.\n\n";
    return 0;
}
