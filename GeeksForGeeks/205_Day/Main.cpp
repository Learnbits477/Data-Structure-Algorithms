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

void freeTree(Node* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

void runTest(int testNum, const string& treeStr, int expected) {
    Node* root = buildTree(treeStr);
    
    Solution sol;
    int result = sol.maxDiff(root);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";
    
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);
    
    string displayStr = treeStr;
    if (displayStr.length() > 30) {
        displayStr = displayStr.substr(0, 27) + "...";
    }
    
    cout << left << setw(6)  << testId 
         << setw(34) << displayStr
         << setw(16) << expected
         << setw(16) << result
         << status << "\n";
         
    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Expected: " << expected << "\n"
             << "     Got:      " << result << "\n";
    }
    
    freeTree(root);
}

int main() {
    cout << "\n🌳 Node and Ancestor Max Diff — Test Suite\n";
    cout << "※ ================================================================================== ※\n";
    cout << left << setw(6)  << "[ID]" 
         << setw(34) << "Input Tree (Level-Order)" 
         << setw(16) << "Expected" 
         << setw(16) << "Result" 
         << "Status\n";
    cout << string(84, '-') << "\n";

    runTest(1, "5 2 N 1", 4);
    runTest(2, "1 2 3 N N N 7", -1);
    runTest(3, "10 3", 7);
    runTest(4, "3 10", -7);
    runTest(5, "5 5 5", 0);
    runTest(6, "100 50 N 25 N 10", 90);
    runTest(7, "10 N 25 N 50 N 100", -15);
    runTest(8, "8 3 10 1 6 N 14 N N 4 7 13", 7);

    cout << "※ ================================================================================== ※\n";
    cout << "                         🎉 All Tests Completed Successfully!                        \n\n";

    return 0;
}
