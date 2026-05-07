#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
#include "Solution.cpp"
using namespace std;



// Helper function to build a tree from level-order input (e.g., "1 2 3 N N 4")
Node* buildTree(string str) {
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    vector<string> ip;
    stringstream ss(str);
    string temp;
    while (ss >> temp)
        ip.push_back(temp);

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

int main() {
    Solution sol;

    // Test Case 1
    string t1 = "1 2 3 N N 4";
    string s1 = "3 4";
    Node* rootT1 = buildTree(t1);
    Node* rootS1 = buildTree(s1);
    
    cout << "Test Case 1: " << (sol.isSubTree(rootT1, rootS1) ? "true" : "false") << " (Expected: true)" << endl;

    // Test Case 2
    string t2 = "26 10 N 20 30 40 60";
    string s2 = "26 10 N 20 30 40 60";
    Node* rootT2 = buildTree(t2);
    Node* rootS2 = buildTree(s2);

    cout << "Test Case 2: " << (sol.isSubTree(rootT2, rootS2) ? "true" : "false") << " (Expected: true)" << endl;

    // Test Case 3 (Not a subtree)
    string t3 = "1 2 3";
    string s3 = "1 2 4";
    Node* rootT3 = buildTree(t3);
    Node* rootS3 = buildTree(s3);

    cout << "Test Case 3: " << (sol.isSubTree(rootT3, rootS3) ? "true" : "false") << " (Expected: false)" << endl;

    return 0;
}
