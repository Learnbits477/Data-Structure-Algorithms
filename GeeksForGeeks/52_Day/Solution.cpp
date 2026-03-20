#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

// BST Node
struct Node {
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

/* BST Node
struct Node
{
	int data;
	struct Node *left, *right;
};
*/

// This function finds predecessor and successor of key in BST.
class Solution{
    public:
    vector<Node*> findPreSuc(Node* root, int key) {
        Node *pre = NULL, *suc = NULL;
        
        // Find successor
        Node* curr = root;
        while (curr != NULL) {
            if (curr->data > key) {
                // If current data is greater than the given key, 
                // it is a potential successor. Move left to find a smaller one.
                suc = curr;
                curr = curr->left;
            } else {
                // If it is smaller or equal, successor must be on the right.
                curr = curr->right;
            }
        }
        
        // Find predecessor
        curr = root;
        while (curr != NULL) {
            if (curr->data < key) {
                // If current data is smaller than the given key,
                // it is a potential predecessor. Move right to find a larger one.
                pre = curr;
                curr = curr->right;
            } else {
                // If it is greater or equal, predecessor must be on the left.
                curr = curr->left;
            }
        }
        
        return {pre, suc};
    }
};

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
    Node* root = new Node(stoi(ip[0]));

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
            currNode->left = new Node(stoi(currVal));

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
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);

        getline(cin, s);
        int k = stoi(s);
        Solution ob;
        vector<Node*> result = ob.findPreSuc(root, k);
        Node* pre = result[0];
        Node* suc = result[1];
        if (pre != NULL)
            cout << pre->data << " ";
        else
            cout << "-1 ";

        if (suc != NULL)
            cout << suc->data << " ";
        else
            cout << "-1 ";
        cout << endl;
    }
    return 0;
}
