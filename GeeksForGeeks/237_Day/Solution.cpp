#include <bits/stdc++.h>
using namespace std;

#ifndef NODE_STRUCT
#define NODE_STRUCT
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};
#endif

class Solution {
public:
    bool areAnagrams(Node *root1, Node *root2) {
        // Base case: if both trees are empty, they are trivially anagrams
        if (!root1 && !root2) return true;
        // If one is empty and the other is not, levels differ
        if (!root1 || !root2) return false;

        queue<Node*> q1, q2;
        q1.push(root1);
        q2.push(root2);

        while (!q1.empty() && !q2.empty()) {
            int s1 = q1.size();
            int s2 = q2.size();

            // Level cardinality mismatch
            if (s1 != s2) return false;

            // Frequency map to verify multiset equality for the current level in O(s1) time
            unordered_map<int, int> freq;

            for (int i = 0; i < s1; ++i) {
                Node* curr1 = q1.front();
                q1.pop();
                Node* curr2 = q2.front();
                q2.pop();

                freq[curr1->data]++;
                freq[curr2->data]--;

                if (curr1->left) q1.push(curr1->left);
                if (curr1->right) q1.push(curr1->right);
                if (curr2->left) q2.push(curr2->left);
                if (curr2->right) q2.push(curr2->right);
            }

            // If any value's net frequency is non-zero, the levels are not anagrams
            for (const auto& kv : freq) {
                if (kv.second != 0) return false;
            }
        }

        // Both trees must terminate at the exact same depth
        return q1.empty() && q2.empty();
    }
};
