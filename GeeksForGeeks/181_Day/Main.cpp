#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

string vecToString(const vector<int>& vec) {
    string res = "[";
    for (size_t i = 0; i < vec.size(); i++) {
        res += to_string(vec[i]);
        if (i + 1 < vec.size()) res += ", ";
    }
    res += "]";
    return res;
}

void getPreorder(Node* root, vector<int>& res) {
    if (!root) return;
    res.push_back(root->data);
    getPreorder(root->left, res);
    getPreorder(root->right, res);
}

void freeTree(Node* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

void runTest(int testNum, vector<int> pre, vector<int> preMirror, vector<int> expected) {
    Solution sol;
    Node* root = sol.constructBinaryTree(pre, preMirror);
    
    vector<int> result;
    getPreorder(root, result);
    
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";
    
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);
    
    string preStr = vecToString(pre);
    if (preStr.length() > 25) {
        preStr = preStr.substr(0, 22) + "...";
    }
    
    string preMStr = vecToString(preMirror);
    if (preMStr.length() > 25) {
        preMStr = preMStr.substr(0, 22) + "...";
    }
    
    string resStr = vecToString(result);
    if (resStr.length() > 25) {
        resStr = resStr.substr(0, 22) + "...";
    }
    
    cout << left << setw(6)  << testId 
         << setw(28) << preStr
         << setw(28) << preMStr
         << setw(28) << resStr
         << status << "\n";
         
    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Expected: " << vecToString(expected) << "\n"
             << "     Got:      " << vecToString(result) << "\n";
    }
    
    freeTree(root);
}

int main() {
    cout << "\n🔢 Construct a Full Binary Tree — Test Suite\n";
    cout << "⇚ - ============================================================================================== - ⇛\n";
    cout << left << setw(6)  << "[ID]" 
         << setw(28) << "Preorder Array" 
         << setw(28) << "PreMirror Array" 
         << setw(28) << "Constructed Preorder" 
         << "Status\n";
    cout << string(96, '-') << "\n";

    runTest(1, {0, 1, 2}, {0, 2, 1}, {0, 1, 2});
    runTest(2, {1, 2, 4, 5, 3, 6, 7}, {1, 3, 7, 6, 2, 5, 4}, {1, 2, 4, 5, 3, 6, 7});
    runTest(3, {42}, {42}, {42});
    runTest(4, {1, 2, 4, 8, 9, 5, 3, 6, 7}, {1, 3, 7, 6, 2, 5, 4, 9, 8}, {1, 2, 4, 8, 9, 5, 3, 6, 7});

    cout << "⇚ - ============================================================================================== - ⇛\n";
    cout << "                           🎉 All Tests Completed Successfully!                           \n\n";

    return 0;
}
