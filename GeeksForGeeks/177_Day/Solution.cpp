#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int canRepresentBST(vector<int>& arr) {
        int n = arr.size();
        stack<int> s;
        int root = INT_MIN;
        
        for (int i = 0; i < n; ++i) {
            // If we find a node who is on the right side
            // and smaller than the current root, return false (0)
            if (arr[i] < root) {
                return 0;
            }
            
            // If arr[i] is greater than stack top, it is a right child.
            // Pop all elements smaller than arr[i] and update root.
            while (!s.empty() && s.top() < arr[i]) {
                root = s.top();
                s.pop();
            }
            
            // Push current node to stack
            s.push(arr[i]);
        }
        return 1;
    }
};
