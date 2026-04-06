#include<bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    int index;
    Node *left, *right;

    Node(int d, int i) {
        data = d;
        index = i;
        left = right = nullptr;
    }

    Node(Node* l, Node* r) {
        data = l->data + r->data;
        index = min(l->index, r->index);
        left = l;
        right = r;
    }
};

class Compare {
  public:
    bool operator()(Node* a, Node* b) {
        if (a->data != b->data)
            return a->data > b->data;
        return a->index > b->index;
    }
};

class Solution {
  private:
    void preOrder(Node* root, vector<string>& ans, string curr) {
        if (root == nullptr)
            return;

        if (root->left == nullptr && root->right == nullptr) {
            if (curr == "")
                curr = "0";
            ans.push_back(curr);
            return;
        }

        preOrder(root->left, ans, curr + '0');
        preOrder(root->right, ans, curr + '1');
    }

  public:
    vector<string> huffmanCodes(string S, vector<int> f) {
        int n = S.length();

        priority_queue<Node*, vector<Node*>, Compare> pq;
        for (int i = 0; i < n; i++) {
            Node* tmp = new Node(f[i], i);
            pq.push(tmp);
        }

        if (n == 1)
            return {"0"};

        while (pq.size() >= 2) {
            Node* l = pq.top();
            pq.pop();

            Node* r = pq.top();
            pq.pop();

            Node* newNode = new Node(l, r);
            pq.push(newNode);
        }

        Node* root = pq.top();
        vector<string> ans;
        preOrder(root, ans, "");
        return ans;
    }
};

int main(){
    int T;
    cin >> T;
    while(T--)
    {
        string S;
        cin >> S;
        int N = S.length();
        vector<int> f(N);
        for(int i=0;i<N;i++){
            cin>>f[i];
        }
        Solution ob;
        vector<string> ans = ob.huffmanCodes(S, f);
        for(auto i: ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
