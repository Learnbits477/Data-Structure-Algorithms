#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

class Solution {
  public:
    // Function to find the vertical order traversal of Binary Tree.
    vector<vector<int>> verticalOrder(Node *root) {
        vector<vector<int>> ans;
        if (!root) return ans;
        
        // Using unordered_map for O(1) average time complexity
        unordered_map<int, vector<int>> mp;
        int min_hd = 0;
        int max_hd = 0;
        
        // Queue to store node and its horizontal distance
        queue<pair<Node*, int>> q;
        
        q.push({root, 0});
        
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            
            Node* curr = it.first;
            int hd = it.second;
            
            mp[hd].push_back(curr->data);
            
            // Track the boundaries to iterate over the hash map later
            min_hd = min(min_hd, hd);
            max_hd = max(max_hd, hd);
            
            if (curr->left) {
                q.push({curr->left, hd - 1});
            }
            if (curr->right) {
                q.push({curr->right, hd + 1});
            }
        }
        
        // Reserve memory to prevent re-allocations
        ans.reserve(max_hd - min_hd + 1);
        
        // Collect answer correctly from left-most line to right-most line
        for (int i = min_hd; i <= max_hd; i++) {
            ans.push_back(move(mp[i])); // Move the vector instead of copying it
        }
        
        return ans;
    }
};


int main() {
    int t;
    scanf("%d\n", &t);
    while (t--) {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution obj;
        vector<vector<int>> res = obj.verticalOrder(root);
        for (auto i : res) {
            for (auto j : i) cout << j << " ";
        }
        cout << "\n";
        cout << "~\n";
    }
    return 0;
}
